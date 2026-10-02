# $NetBSD$

DISTNAME=	86box-roms-6.0
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=86Box/}
GITHUB_PROJECT=	roms
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/86Box/roms
COMMENT=	ROM set for the 86Box PC emulator
LICENSE=	86box-roms-license

# The GitHub tag tarball extracts to a directory named after the
# repository, not after the package.
WRKSRC=		${WRKDIR}/roms-${PKGVERSION_NOREV}

# The ROMs are the property of their respective copyright owners and are
# made available in the interest of preservation.
RESTRICTED=		ROMs are property of their respective copyright owners
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

NO_BUILD=	yes
USE_TOOLS+=	pax

ROMSDIR=	share/86Box/roms
INSTALLATION_DIRS=	${ROMSDIR}

GENERATE_PLIST=	\
	cd ${DESTDIR}${PREFIX} && ${FIND} ${ROMSDIR} -type f -print | ${SORT} ;

do-install:
	${RUN}${RM} -rf ${WRKSRC}/.github
	${RUN}cd ${WRKSRC} && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/${ROMSDIR}

.include "../../mk/bsd.pkg.mk"
