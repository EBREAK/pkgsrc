# $NetBSD: Makefile,v 1.4 2025/09/08 22:54:47 lloyd Exp $

DISTNAME=		gcc-14.3.0
PKGNAME=		cross-riscv64-none-elf-${DISTNAME}
#PKGREVISION=		1
CATEGORIES=		cross
NEWLIBVER=		4.5.0.20241231
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-${PKGVERSION_NOREV}/}
EXTRACT_SUFX=		.tar.xz
DISTFILES=		${DEFAULT_DISTFILES} \
			newlib-${NEWLIBVER}.tar.gz
SITES.newlib-${NEWLIBVER}.tar.gz=	https://www.sourceware.org/pub/newlib/

MAINTAINER=		port-riscv@NetBSD.org
HOMEPAGE=		# none
COMMENT=		GCC for bare metal RISC-V 64-bit little-endian ELF
LICENSE=		gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

EXTRACT_USING=		bsdtar

# Relocations result in a linker error.
MKPIE_SUPPORTED=	no

# for http://gcc.gnu.org/bugzilla/show_bug.cgi?id=33549
# use makeinfo from pkgsrc/devel/gtexinfo.
TOOL_DEPENDS+=			gtexinfo>=5.1:../../devel/gtexinfo
_TOOLS_USE_PKGSRC.makeinfo=	yes

DEPENDS+=		cross-riscv64-none-elf-binutils>=2.45:../../cross/riscv64-none-elf-binutils

USE_LANGUAGES+=		c c++

CHECK_PORTABILITY_SKIP+=	contrib/*
CHECK_PORTABILITY_SKIP+=	gcc/config/nvptx/gen-opt.sh

RISCV64ELF_PREFIX=	${PREFIX}/cross-riscv64-none-elf
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure

CONFIG_SHELL=		${TOOLS_PATH.bash}
WRAPPER_SHELL=		${TOOLS_PATH.bash}
USE_TOOLS+=		bash gmake gsed makeinfo perl

GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # has sub-configures
GNU_CONFIGURE_PREFIX=	${RISCV64ELF_PREFIX}

CONFIGURE_ARGS+=	--target=riscv64-none-elf
CONFIGURE_ARGS+=	--enable-languages=c,c++
CONFIGURE_ARGS+=	--with-newlib
CONFIGURE_ARGS+=	--enable-multilib
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-libstdcxx-pch
CONFIGURE_ARGS+=	--disable-gcov

INFO_FILES=		yes

post-extract:
	${LN} -s ${WRKDIR}/newlib-${NEWLIBVER}/newlib ${WRKSRC}/newlib
	${LN} -s ${WRKDIR}/newlib-${NEWLIBVER}/libgloss ${WRKSRC}/libgloss
	${ECHO} 'MULTILIB_OPTIONS = march=rv32i/march=rv32ic/march=rv32im/march=rv32imc/march=rv32iac/march=rv32imac/march=rv32imafc/march=rv32imafdc/march=rv32gc/march=rv64imac/march=rv64imafdc/march=rv64gc/march=rv32ec/march=rv32emc/march=rv32imac_zba_zbb_zbs/march=rv32imafc_zba_zbb_zbs mabi=ilp32/mabi=ilp32f/mabi=lp64/mabi=lp64d/mabi=ilp32e' > ${WRKSRC}/gcc/config/riscv/t-elf-multilib
	${ECHO} 'MULTILIB_DIRNAMES = rv32i rv32ic rv32im rv32imc rv32iac rv32imac rv32imafc rv32imafdc rv32gc rv64imac rv64imafdc rv64gc rv32ec rv32emc rv32imac_zba_zbb_zbs rv32imafc_zba_zbb_zbs ilp32 ilp32f lp64 lp64d ilp32e' >> ${WRKSRC}/gcc/config/riscv/t-elf-multilib
	${ECHO} 'MULTILIB_REQUIRED = march=rv32i/mabi=ilp32 march=rv32im/mabi=ilp32 march=rv32iac/mabi=ilp32 march=rv32imac/mabi=ilp32 march=rv32imafc/mabi=ilp32f march=rv64imac/mabi=lp64 march=rv64imafdc/mabi=lp64d march=rv32ec/mabi=ilp32e march=rv32emc/mabi=ilp32e march=rv32imac_zba_zbb_zbs/mabi=ilp32 march=rv32imafc_zba_zbb_zbs/mabi=ilp32f' >> ${WRKSRC}/gcc/config/riscv/t-elf-multilib
	${ECHO} 'MULTILIB_REUSE = march.rv32i/mabi.ilp32=march.rv32ic/mabi.ilp32 march.rv32im/mabi.ilp32=march.rv32imc/mabi.ilp32 march.rv32imafc/mabi.ilp32f=march.rv32imafdc/mabi.ilp32f march.rv32imafc/mabi.ilp32f=march.rv32gc/mabi.ilp32f march.rv64imafdc/mabi.lp64d=march.rv64gc/mabi.lp64d' >> ${WRKSRC}/gcc/config/riscv/t-elf-multilib

# _FORTIFY_SOURCE without -O causes #warning on stderr during cc -E,
# which breaks autoconf header detection (e.g. fcntl.h, sys/mman.h).
pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}
	${RUN} ${SED} -i '/^prepend=-D_FORTIFY_SOURCE=/d' \
		${WRKDIR}/.cwrapper/config/cc \
		${WRKDIR}/.cwrapper/config/c++

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
