$NetBSD$

Fix build with gcc14+ where configure may fail to detect HAVE_FCNTL_H,
HAVE_SPAWN_H and HAVE_LIMITS_H due to _FORTIFY_SOURCE warnings.

--- libiberty/pex-unix.c.orig	2024-05-07 08:52:52.000000000 +0000
+++ libiberty/pex-unix.c
@@ -42,27 +42,23 @@
 
 #include <sys/types.h>
 
-#ifdef HAVE_FCNTL_H
 #include <fcntl.h>
-#endif
 #ifdef HAVE_SYS_WAIT_H
 #include <sys/wait.h>
 #endif
 #ifdef HAVE_GETRUSAGE
 #include <sys/time.h>
 #include <sys/resource.h>
 #endif
 #ifdef HAVE_SYS_STAT_H
 #include <sys/stat.h>
 #endif
 #ifdef HAVE_PROCESS_H
 #include <process.h>
 #endif
-#ifdef HAVE_SPAWN_H
 #include <spawn.h>
-#endif
 
 #ifdef vfork /* Autoconf may define this to fork for us. */
 # define VFORK_STRING "fork"
 #else
 # define VFORK_STRING "vfork"
