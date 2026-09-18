# $NetBSD: Makefile,v 1.1 2026/09/05 18:00:00 evil Exp $

DISTNAME=	agamemnon-0.3.0
PKGNAME=	${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=bbenchoff/}
GITHUB_PROJECT=	AGaMEMnon
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bbenchoff/AGaMEMnon
COMMENT=	Open SDK and FPGA toolchain for AGM AG32 RISC-V MCU with AGRV2K fabric
LICENSE=	mit

WRKSRC=		${WRKDIR}/AGaMEMnon-${PKGVERSION_NOREV}

# PyPI project name differs from DISTNAME
WHEEL_NAME=	agamemnon_ag32-${PKGVERSION_NOREV}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-serial>=3.5:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-platformio>=6.1:../../devel/py-platformio

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	agamemnon

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
