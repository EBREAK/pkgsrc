# $NetBSD$

DISTNAME=	mkg3a-0.5.1
CATEGORIES=	cross
MASTER_SITES=	https://gitlab.com/taricorp/mkg3a/-/archive/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/taricorp/mkg3a
COMMENT=	Pack raw binaries into Casio Prizm .g3a add-in files
LICENSE=	zlib

USE_LANGUAGES=	c
USE_TOOLS+=	gzip

# Sources in the GitLab tarball have CRLF line endings; normalize the
# files that get patched so plain LF patches apply.
SUBST_CLASSES+=		crlf
SUBST_STAGE.crlf=	pre-patch
SUBST_FILES.crlf=	CMakeLists.txt
SUBST_SED.crlf=		-e 's,\r$$,,'

.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
