$NetBSD$

Fix plugin.cc compilation when configure fails to detect dlfcn.h
due to _FORTIFY_SOURCE warnings from glibc.

--- gcc/plugin.cc.orig	2024-05-07 08:52:52.000000000 +0000
+++ gcc/plugin.cc
@@ -23,6 +23,9 @@ along with GCC; see the file COPYING3.
 #include "config.h"
 #define INCLUDE_DLFCN_H
 #include "system.h"
+#if !defined (HAVE_DLFCN_H) && defined (__linux__)
+#include <dlfcn.h>
+#endif
 #include "coretypes.h"
 #include "options.h"
 #include "tree-pass.h"
