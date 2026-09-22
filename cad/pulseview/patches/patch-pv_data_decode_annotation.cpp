$NetBSD$

The libsigrokdecode header already provides C++ linkage via G_BEGIN_DECLS,
and modern glib headers (included through it) are not extern "C" safe.
Drop the wrapper.

--- pv/data/decode/annotation.cpp.orig	2020-04-14 20:19:29.000000000 +0000
+++ pv/data/decode/annotation.cpp
@@ -17,9 +17,7 @@
  * along with this program; if not, see <http://www.gnu.org/licenses/>.
  */
 
-extern "C" {
 #include <libsigrokdecode/libsigrokdecode.h>
-}
 
 #include <cassert>
 #include <vector>
