# $NetBSD$

DISTNAME=	wlink-0.1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ch32-rs/}
GITHUB_PROJECT=	wlink
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ch32-rs/wlink/
COMMENT=	WCH-Link flash and debug tool for WCH RISC-V microcontrollers
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

.include "../../sysutils/libudev/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
