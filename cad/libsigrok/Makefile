# $NetBSD$

DISTNAME=	libsigrok-0.5.2
CATEGORIES=	cad
MASTER_SITES=	https://sigrok.org/download/source/libsigrok/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sigrok.org/wiki/Libsigrok
COMMENT=	Backend library for the sigrok signal analysis software suite
LICENSE=	gnu-gpl-v3

USE_CC_FEATURES+=	c11
USE_CXX_FEATURES+=	c++11
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--without-libbluez
CONFIGURE_ARGS+=	--without-libgpib
CONFIGURE_ARGS+=	--without-libhidapi
CONFIGURE_ARGS+=	--without-libieee1284
CONFIGURE_ARGS+=	--without-librevisa
# The Python and Ruby bindings additionally need swig, pygobject, and
# setuptools; the C++ bindings (libsigrokcxx, needed by pulseview) are
# enabled by default and are built against glibmm.
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-ruby

post-install: install-udev-rules
install-udev-rules:
	${RUN}cd ${WRKSRC} && \
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/libsigrok && \
	${INSTALL_DATA} contrib/60-libsigrok.rules \
	    contrib/61-libsigrok-plugdev.rules \
	    contrib/61-libsigrok-uaccess.rules \
	    ${DESTDIR}${PREFIX}/share/examples/libsigrok

.include "../../archivers/libzip/buildlink3.mk"
.include "../../cad/libserialport/buildlink3.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/libftdi1/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
