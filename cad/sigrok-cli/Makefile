# $NetBSD$

DISTNAME=	sigrok-cli-0.7.2
CATEGORIES=	cad
MASTER_SITES=	https://sigrok.org/download/source/sigrok-cli/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sigrok.org/wiki/Sigrok-cli
COMMENT=	Command-line frontend for the sigrok signal analysis software suite
LICENSE=	gnu-gpl-v3

USE_CC_FEATURES+=	c11
USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

.include "../../cad/libsigrok/buildlink3.mk"
.include "../../cad/libsigrokdecode/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
