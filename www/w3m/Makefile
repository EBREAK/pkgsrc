# $NetBSD: Makefile,v 1.108 2026/07/24 15:56:07 taca Exp $

PKGREVISION=	2

COMMENT=	Multilingualized version of a pager/text-based browser w3m

CONFLICTS+=	w3m-img-[0-9]*

.include "../../mk/bsd.fast.prefs.mk"

# w3m's configure appends -lnsl whenever libnsl.so exists in the native
# library directories.  On Slackware 15 that library depends on libtirpc,
# which needs symbol versions (gssapi_krb5_2_MIT) from the native
# libgssapi_krb5.  If pkgsrc mit-krb5 is installed, its library shadows
# the native one via the pkgsrc rpath and every configure link check
# fails (e.g. "checking for GC_init in -lgc... no").  Prefer the native
# directories when the linker resolves transitive dependencies.
.if ${OPSYS} == "Linux" && ${MACHINE_ARCH} == "x86_64"
LDFLAGS+=	-Wl,-rpath-link,/lib64 -Wl,-rpath-link,/usr/lib64
.endif

.include "../../www/w3m/Makefile.common"
.include "../../mk/bsd.pkg.mk"
