$NetBSD: patch-compiler_rustc__codegen__ssa_src_back_linker.rs,v 1.22 2026/04/02 19:06:34 wiz Exp $

Do not use @rpath on Darwin.
Find external libunwind on Linux.

--- compiler/rustc_codegen_ssa/src/back/linker.rs.orig	2026-01-24 10:12:53.935808570 +0000
+++ compiler/rustc_codegen_ssa/src/back/linker.rs
@@ -454,7 +454,7 @@ impl<'a> GccLinker<'a> {
             // principled solution at some point to force the compiler to pass
             // the right `-Wl,-install_name` with an `@rpath` in it.
             if self.sess.opts.cg.rpath || self.sess.opts.unstable_opts.osx_rpath_install_name {
-                let mut rpath = OsString::from("@rpath/");
+                let mut rpath = OsString::from("@PREFIX@/lib/");
                 rpath.push(out_filename.file_name().unwrap());
                 self.link_arg("-install_name").link_arg(rpath);
             }
@@ -596,6 +596,18 @@ impl<'a> Linker for GccLinker<'a> {
     }
 
     fn link_dylib_by_name(&mut self, name: &str, verbatim: bool, as_needed: bool) {
+        if self.sess.target.llvm_target.contains("linux") && name == "unwind" {
+            // Use a cc_arg( "-B" ), not a link_arg( "-L" ): the compiler driver
+            // (e.g. gcc on Linux systems shipping a "nongnu" libunwind in its
+            // default library path, such as /usr/lib64) places its built-in
+            // search directories before all command-line -L arguments, so -L
+            // cannot make -lunwind resolve to pkgsrc's LLVM libunwind.
+            // -B directories are searched first, ahead of the built-in ones.
+            // Note link_arg() would wrap this in -Wl, which ld itself does
+            // not understand, so it has to be handed to cc verbatim.
+            self.cc_arg("-B@PREFIX@/lib/");
+            self.link_arg("-R@PREFIX@/lib");
+        }
         if self.sess.target.os == Os::Illumos && name == "c" {
             // libc will be added via late_link_args on illumos so that it will
             // appear last in the library search order.
