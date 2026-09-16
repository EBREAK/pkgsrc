$NetBSD$

Do not treat maybe-uninitialized as an error; it is prone to false
positives with gcc < 12 (seen with gcc 11 at -O2 in cmocka.c), which
breaks the build since -Werror=uninitialized also escalates it.

--- CompilerChecks.cmake.orig	2025-12-19 13:13:53.000000000 +0000
+++ CompilerChecks.cmake
@@ -38,6 +38,9 @@ if (UNIX)
     add_c_compiler_flag("-Werror=uninitialized" SUPPORTED_COMPILER_FLAGS)
     add_c_compiler_flag("-Wimplicit-fallthrough" SUPPORTED_COMPILER_FLAGS)
     add_c_compiler_flag("-Werror=strict-overflow" SUPPORTED_COMPILER_FLAGS)
+    # -Werror=uninitialized also escalates -Wmaybe-uninitialized, which
+    # is prone to false positives with gcc < 12.
+    add_c_compiler_flag("-Wno-error=maybe-uninitialized" SUPPORTED_COMPILER_FLAGS)
     add_c_compiler_flag("-Wstrict-overflow=2" SUPPORTED_COMPILER_FLAGS)
     add_c_compiler_flag("-Wno-format-zero-length" SUPPORTED_COMPILER_FLAGS)
     add_c_compiler_flag("-Wmissing-field-initializers" SUPPORTED_COMPILER_FLAGS)
