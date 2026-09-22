# $NetBSD$

BUILDLINK_TREE+=	libsigrokdecode

.if !defined(LIBSIGROKDECODE_BUILDLINK3_MK)
LIBSIGROKDECODE_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.libsigrokdecode+=	libsigrokdecode>=0.5.2
BUILDLINK_PKGSRCDIR.libsigrokdecode?=	../../cad/libsigrokdecode

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/${PYPACKAGE}/buildlink3.mk"
.endif	# LIBSIGROKDECODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsigrokdecode
