# $NetBSD$

DISTNAME=	wchisp-0.3.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ch32-rs/}
GITHUB_PROJECT=	wchisp
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ch32-rs/wchisp/
COMMENT=	Chip programmer for WCH (Nanjing Qinheng) microcontrollers
LICENSE=	gnu-gpl-v2

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

# Do not use the vendored libusb from rusb, link against pkgsrc libusb1.
CARGO_NO_DEFAULT_FEATURES=	yes

.include "../../devel/libusb1/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
