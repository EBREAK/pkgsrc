# $NetBSD$

DISTNAME=	86box-6.0
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=86Box/}
GITHUB_PROJECT=	86Box
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://86box.net/
COMMENT=	Emulator of x86-based systems from the IBM PC 5150 to the Pentium era
LICENSE=	gnu-gpl-v2

# The GitHub tag tarball extracts to a directory with the original
# repository name casing.
WRKSRC=		${WRKDIR}/86Box-${PKGVERSION_NOREV}

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++17
USE_TOOLS+=		pkg-config

# Embed the translations for Qt's own strings shipped by Qt.
TOOL_DEPENDS+=	qt5-qttranslations-[0-9]*:../../x11/qt5-qttranslations

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DRELEASE=ON
CMAKE_CONFIGURE_ARGS+=	-DDEV_BRANCH=OFF
# The Discord Game SDK is not redistributable and is dlopen(3)ed anyway.
CMAKE_CONFIGURE_ARGS+=	-DDISCORD=OFF
# rtmidi is not packaged for pkgsrc yet.
CMAKE_CONFIGURE_ARGS+=	-DRTMIDI=OFF

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "x86_64" || ${MACHINE_ARCH} == "aarch64"
# The dynamic recompiler needs executable memory (W^X).
NOT_PAX_MPROTECT_SAFE+=	bin/86Box
.else
# The dynamic recompilers only support x86-64 and arm64 hosts.
CMAKE_CONFIGURE_ARGS+=	-DDYNAREC=OFF
.endif

INSTALLATION_DIRS=	share/applications

post-install:
	${INSTALL_DATA} ${FILESDIR}/86box.desktop \
	    ${DESTDIR}${PREFIX}/share/applications/86box.desktop

.include "../../devel/cmake/build.mk"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../cad/libserialport/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/libslirp/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
