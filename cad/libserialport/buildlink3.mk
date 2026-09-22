# $NetBSD$

BUILDLINK_TREE+=	libserialport

.if !defined(LIBSERIALPORT_BUILDLINK3_MK)
LIBSERIALPORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libserialport+=	libserialport>=0.1.1
BUILDLINK_PKGSRCDIR.libserialport?=	../../cad/libserialport
.endif	# LIBSERIALPORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libserialport
