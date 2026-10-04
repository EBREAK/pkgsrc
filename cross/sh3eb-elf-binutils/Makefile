# $NetBSD$

DISTNAME=	binutils-2.45
PKGNAME=	cross-sh3eb-elf-${DISTNAME}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Cross binutils for bare metal Renesas SuperH (sh3eb-elf)
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

USE_LANGUAGES+=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		bison gmake makeinfo perl
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # several sub-configures know --enable-nls

TOOL_DEPENDS+=		gtexinfo>=5.1:../../devel/gtexinfo
_TOOLS_USE_PKGSRC.makeinfo=	yes

SH3EBELF_PREFIX=	${PREFIX}/cross-sh3eb-elf

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GNU_CONFIGURE_PREFIX=	${SH3EBELF_PREFIX}

CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ARGS+=	--target=sh3eb-elf
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--enable-deterministic-archives
INFO_FILES=		yes

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

post-install:
	${RM} ${DESTDIR}${SH3EBELF_PREFIX}/sh3eb-elf/lib/ldscripts/stamp

.include "../../mk/bsd.pkg.mk"
