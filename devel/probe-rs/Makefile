# $NetBSD$

DISTNAME=	probe-rs-0.32.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=probe-rs/}
GITHUB_PROJECT=	probe-rs
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://probe.rs/
COMMENT=	Flashing and debugging toolkit for embedded microcontrollers
LICENSE=	mit OR apache-2.0

ONLY_FOR_PLATFORM=	Linux-*-* Darwin-*-*

RUST_REQ=	1.95.0
USE_LANGUAGES+=	c
USE_TOOLS+=	pkg-config

.include "cargo-depends.mk"

CARGO_ARGS=	build --release -p probe-rs-tools -p target-gen ${DEFAULT_CARGO_ARGS}

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/probe-rs ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cargo-flash ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cargo-embed ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/target-gen ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
.  include "../../sysutils/libudev/buildlink3.mk"
.endif
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
