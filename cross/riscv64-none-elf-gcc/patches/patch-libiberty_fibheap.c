$NetBSD$

Always include limits.h for LONG_MIN.

--- libiberty/fibheap.c.orig	2025-04-20 20:10:32.000000000 +0000
+++ libiberty/fibheap.c
@@ -23,5 +23,3 @@
 #endif
-#ifdef HAVE_LIMITS_H
 #include <limits.h>
-#endif
 #ifdef HAVE_STDLIB_H
