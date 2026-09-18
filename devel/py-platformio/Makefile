# $NetBSD: Makefile,v 1.1 2026/09/05 16:00:00 evil Exp $

DISTNAME=	platformio-6.1.19
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/platformio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://platformio.org/
COMMENT=	Open source ecosystem for embedded development
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-bottle>=0.13:../../www/py-bottle
DEPENDS+=	${PYPKGPREFIX}-click>=8.0.4:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-marshmallow>=3:../../devel/py-marshmallow
DEPENDS+=	${PYPKGPREFIX}-pyelftools>=0.27:../../devel/py-pyelftools
DEPENDS+=	${PYPKGPREFIX}-serial>=3.5:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-requests>=2:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-semantic_version>=2.10:../../devel/py-semantic_version
DEPENDS+=	${PYPKGPREFIX}-tabulate>=0.8:../../textproc/py-tabulate

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	pio piodebuggdb platformio

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
