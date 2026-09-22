# $NetBSD$

DISTNAME=	pulseview-0.4.2
CATEGORIES=	cad
MASTER_SITES=	https://sigrok.org/download/source/pulseview/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sigrok.org/wiki/PulseView
COMMENT=	Qt-based GUI frontend for the sigrok signal analysis software suite
LICENSE=	gnu-gpl-v3

USE_CXX_FEATURES+=	c++14
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

# pulseview forces -std=c++11, but modern Boost (as in pkgsrc) requires
# C++14 for its headers; let the compiler default apply instead.
BUILDLINK_TRANSFORM+=	rm:-std=c++11

.include "../../devel/cmake/build.mk"

CMAKE_CONFIGURE_ARGS+=	-DENABLE_TESTS=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_STACKTRACE=OFF
CMAKE_CONFIGURE_ARGS+=	-DDISABLE_WERROR=ON
# pulseview declares compatibility with CMake < 3.5.
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../cad/libsigrok/buildlink3.mk"
.include "../../cad/libsigrokdecode/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
