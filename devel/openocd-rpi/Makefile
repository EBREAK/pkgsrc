# $NetBSD$

DISTNAME=	openocd-0.12.0.20260318
PKGNAME=	openocd-rpi-0.12.0.20260318
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=raspberrypi/}
GITHUB_PROJECT=	openocd
# rpi-common branch
GITHUB_TAG=	acff23ffd100479d6481a1155123774b79a990b9

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/raspberrypi/openocd/
COMMENT=	Open On-Chip Debugger (Raspberry Pi fork with Pico-series support)
LICENSE=	gnu-gpl-v2

# Installs under "openocd-rpi" names and share/openocd-rpi paths so that
# it can coexist with devel/openocd; no file conflicts.

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config
USE_TOOLS+=		aclocal autoconf autoheader automake autoreconf
USE_TOOLS+=		makeinfo
INFO_FILES=		yes
OVERRIDE_DIRDEPTH=	5

CONFIGURE_ARGS+=	--disable-internal-jimtcl
CONFIGURE_ARGS+=	--program-suffix=-rpi

BUILDLINK_TRANSFORM+=	rm:-Werror

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "options.mk"

.include "../../lang/jimtcl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
