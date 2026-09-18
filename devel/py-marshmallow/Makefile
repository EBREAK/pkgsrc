# $NetBSD: Makefile,v 1.1 2026/09/05 16:00:00 evil Exp $

DISTNAME=	marshmallow-3.26.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/marshmallow/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://marshmallow.readthedocs.io/
COMMENT=	A lightweight library for converting complex datatypes
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.9:../../devel/py-flit_core

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
