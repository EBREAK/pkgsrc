$NetBSD$

Fix build with jimtcl >= 0.84: the isproc member of Jim_Cmd was replaced
by a flags field with JIM_CMD_ISPROC.

--- src/helper/command.c.orig	2026-03-18 14:32:57.000000000 +0000
+++ src/helper/command.c
@@ -45,17 +45,30 @@
 /* set of functions to wrap jimtcl internal data */
 static inline bool jimcmd_is_proc(Jim_Cmd *cmd)
 {
+#if JIM_VERSION >= 84
+	return cmd->flags & JIM_CMD_ISPROC;
+#else
 	return cmd->isproc;
+#endif
 }
 
 bool jimcmd_is_oocd_command(Jim_Cmd *cmd)
 {
+#if JIM_VERSION >= 84
+	return !(cmd->flags & JIM_CMD_ISPROC) &&
+	       cmd->u.native.cmdProc == jim_command_dispatch;
+#else
 	return !cmd->isproc && cmd->u.native.cmdProc == jim_command_dispatch;
+#endif
 }
 
 void *jimcmd_privdata(Jim_Cmd *cmd)
 {
+#if JIM_VERSION >= 84
+	return (cmd->flags & JIM_CMD_ISPROC) ? NULL : cmd->u.native.privData;
+#else
 	return cmd->isproc ? NULL : cmd->u.native.privData;
+#endif
 }
 
 static int command_retval_set(Jim_Interp *interp, int retval)
