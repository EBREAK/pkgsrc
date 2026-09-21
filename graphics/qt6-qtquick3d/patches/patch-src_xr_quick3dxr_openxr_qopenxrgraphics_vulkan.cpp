$NetBSD$

The vendored openxr headers (openxr_platform.h) include X11/Xlib.h when
XR_USE_PLATFORM_XLIB is defined, which the Quick3DXr target defines for
all of its sources.  X11/Xlib.h and X11/X.h define macros (Bool, Status,
None, Always, CursorShape) that clash with identifiers in Qt headers
parsed later in these translation units (QRhiSampler::Filter::None,
QMetaType::Bool, Qt::CursorShape, QUrl::None, ...), breaking the build.

Rework the include order and #undef the offending macros right after
the platform headers, before any further Qt headers are parsed.  In the
OpenGL backend GL/glx.h must still be included while the macros are
defined, as its prototypes use Bool.

--- src/xr/quick3dxr/openxr/qopenxrgraphics_vulkan.cpp.orig	2026-08-12 02:20:36.000000000 +0000
+++ src/xr/quick3dxr/openxr/qopenxrgraphics_vulkan.cpp
@@ -3,7 +3,16 @@
 // Qt-Security score:significant reason:default
 
 
+#include <rhi/qrhi.h>
 #include "qopenxrgraphics_vulkan_p.h"
+// The X11 headers (via openxr_platform.h with XR_USE_PLATFORM_XLIB)
+// define macros that clash with Qt headers; undefine them before
+// including anything else.
+#undef None
+#undef Always
+#undef CursorShape
+#undef Bool
+#undef Status
 
 #include "qopenxrhelpers_p.h"
 #include <QtQuick/QQuickWindow>
@@ -11,7 +20,6 @@
 #include <QtQuick/QQuickGraphicsConfiguration>
 #include <QtQuick/private/qquickrendertarget_p.h>
 
-#include <rhi/qrhi.h>
 
 //#define XR_USE_GRAPHICS_API_VULKAN
 
