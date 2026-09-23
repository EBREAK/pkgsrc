# $NetBSD: buildlink3.mk,v 1.12 2026/05/19 12:59:48 jperkin Exp $

BUILDLINK_TREE+=	openal-soft

.include "../../mk/bsd.fast.prefs.mk"

# Unfortunately for users of pkgsrc on stable OS versions, the latest
# version of OpenAL requires quite recent C++ standards support.
#
# We want to avoid requiring a compiler newer than what the majority
# of our packages will be built with, in order to avoid ABI issues and
# conflicts with the C++ standard library.  We also want to avoid
# requiring the user install a special compiler just to build OpenAL,
# which is a fairly stable interface.
#
# In order to best cope with this situation, older versions of OpenAL
# are selected on systems that ship older compilers by default.
#
# In order to avoid C++ standard library issues entirely, it is
# possible to set OPENAL_USE_CXX=no in mk.conf.  This will bring
# in the last version of OpenAL written in pure C.

# On NetBSD, avoid including compiler.mk, in case a mixture of
# GCC versions are being used to build the pkgsrc tree.
.if ${OPSYS} == "NetBSD"
.  if ${OPSYS_VERSION} < 100000
.    include "../../audio/openal-soft-cxx14/buildlink3.mk"
.  endif
.else
.  include "../../mk/compiler.mk"
# OpenAL is written in C++20 and, when the native compiler is too old,
# is built with the pkgsrc compiler.  Consumers using an older native
# compiler cannot link the resulting library: their libstdc++ lacks the
# required symbol versions (e.g. std::__glibcxx_assert_fail@GLIBCXX_3.4.30
# for a gcc12-built OpenAL), which breaks configure-time link checks
# (seen with x11/qt5-qtmultimedia on Slackware 15).  Use the pure-C
# variant with such compilers.
.  if !defined(OPENAL_USE_CXX) && \
      (${CC_VERSION:Mgcc-4.*} || ${CC_VERSION:Mgcc-[89].*} || \
       ${CC_VERSION:Mgcc-1[01].*})
OPENAL_USE_CXX=	no
.  elif !defined(OPENAL_USE_CXX) && \
      (${CC_VERSION:Mgcc-[567].*} || ${CC_VERSION:Mclang-1[0-5].*})
.    include "../../audio/openal-soft-cxx14/buildlink3.mk"
.  endif
.endif

OPENAL_USE_CXX?=	yes

.if ${OPENAL_USE_CXX:tl} == "no"
.  include "../../audio/openal-soft-c/buildlink3.mk"
.endif

# If an OpenAL buildlink3 file has already been included,
# the following section will be ignored.
.if !defined(OPENAL_SOFT_BUILDLINK3_MK)
OPENAL_SOFT_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	c++17

BUILDLINK_API_DEPENDS.openal-soft+=	openal-soft>=1.5.304
BUILDLINK_PKGSRCDIR.openal-soft?=	../../audio/openal-soft
.endif	# OPENAL_SOFT_BUILDLINK3_MK

BUILDLINK_TREE+=	-openal-soft
