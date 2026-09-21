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

--- src/xr/quick3dxr/openxr/qopenxrgraphics_opengl.cpp.orig	2026-08-12 02:20:36.000000000 +0000
+++ src/xr/quick3dxr/openxr/qopenxrgraphics_opengl.cpp
@@ -3,18 +3,26 @@
 // Qt-Security score:significant reason:default
 
 
+#include <rhi/qrhi.h>
+
 #include "qopenxrgraphics_opengl_p.h"
+#if defined(XR_USE_PLATFORM_XLIB) || defined(XR_USE_PLATFORM_XCB)
+#  include <GL/glx.h>
+#endif
+// The X11 headers define macros that clash with Qt headers
+// (Bool, Status, None, Always, CursorShape); undefine them before
+// including anything else.
+#undef None
+#undef Always
+#undef CursorShape
+#undef Bool
+#undef Status
 #include "qopenxrhelpers_p.h"
 
 #include <QtGui/QOpenGLContext>
 #include <QtQuick/QQuickWindow>
 #include <QtQuick/private/qquickrendertarget_p.h>
 
-#include <rhi/qrhi.h>
-
-#if defined(XR_USE_PLATFORM_XLIB) || defined(XR_USE_PLATFORM_XCB)
-#include <GL/glx.h>
-#endif
 
 #include <qpa/qplatformnativeinterface.h>
 
