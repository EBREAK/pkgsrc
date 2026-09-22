# $NetBSD$

DISTNAME=	libsigrokdecode-0.5.3
CATEGORIES=	cad
MASTER_SITES=	https://sigrok.org/download/source/libsigrokdecode/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sigrok.org/wiki/Libsigrokdecode
COMMENT=	Protocol decoder library of the sigrok signal analysis software suite
LICENSE=	gnu-gpl-v3

USE_CC_FEATURES+=	c11
USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

# Only probes for python-3.8 and older at configure time.
PYTHON_VERSIONS_ACCEPTED=	314 313 312 311 310

SUBST_CLASSES+=		py
SUBST_STAGE.py=		pre-configure
SUBST_FILES.py=		configure configure.ac
SUBST_SED.py=		-e "s|python-3\\.8-embed|python-${PYVERSSUFFIX}-embed|g"
SUBST_MESSAGE.py=	Adjusting the version of the embedded Python interpreter.

CONFIGURE_ENV+=		PYTHON3=${PYTHONBIN:Q}

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/${PYPACKAGE}/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
