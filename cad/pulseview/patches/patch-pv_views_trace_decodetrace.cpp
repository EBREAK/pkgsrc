$NetBSD$

The libsigrokdecode header already provides C++ linkage via G_BEGIN_DECLS,
and modern glib headers (included through it) are not extern "C" safe.
Drop the wrapper.

--- pv/views/trace/decodetrace.cpp.orig	2020-04-14 20:19:29.000000000 +0000
+++ pv/views/trace/decodetrace.cpp
@@ -17,9 +17,7 @@
  * along with this program; if not, see <http://www.gnu.org/licenses/>.
  */
 
-extern "C" {
 #include <libsigrokdecode/libsigrokdecode.h>
-}
 
 #include <limits>
 #include <mutex>
