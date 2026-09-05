$NetBSD$

Always include fcntl.h for fcntl/F_SETFD/FD_CLOEXEC.

--- libiberty/pex-unix.c.orig	2025-04-20 20:10:32.000000000 +0000
+++ libiberty/pex-unix.c
@@ -44,5 +44,3 @@
 
-#ifdef HAVE_FCNTL_H
 #include <fcntl.h>
-#endif
 #ifdef HAVE_SYS_WAIT_H
