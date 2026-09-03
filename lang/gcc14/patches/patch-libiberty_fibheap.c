$NetBSD$

Fix build with gcc14+ where configure may fail to detect HAVE_LIMITS_H
due to _FORTIFY_SOURCE warnings, causing LONG_MIN to be undeclared.

--- libiberty/fibheap.c.orig	2024-05-07 08:52:52.000000000 +0000
+++ libiberty/fibheap.c
@@ -22,9 +22,7 @@
 #ifdef HAVE_CONFIG_H
 #include "config.h"
 #endif
-#ifdef HAVE_LIMITS_H
 #include <limits.h>
-#endif
 #ifdef HAVE_STDLIB_H
 #include <stdlib.h>
 #endif
