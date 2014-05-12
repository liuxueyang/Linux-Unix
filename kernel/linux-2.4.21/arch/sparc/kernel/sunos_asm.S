/* $Id: sunos_asm.S,v 1.15 2000/01/11 17:33:21 jj Exp $
 * sunos_asm.S: SunOS system calls which must have a low-level
 *              entry point to operate correctly.
 *
 * Copyright (C) 1995 David S. Miller (davem@caip.rutgers.edu)
 *
 * Based upon preliminary work which is:
 *
 * Copyright (C) 1995 Adrian M. Rodriguez (adrian@remus.rutgers.edu)
 */

#include <asm/cprefix.h>
#include <asm/ptrace.h>

	.text
	.align 4

	/* When calling ret_sys_call, %o0 should contain the same
	 * value as in [%sp + STACKFRAME_SZ + PT_I0] */

	/* SunOS getpid() returns pid in %o0 and ppid in %o1 */
	.globl	C_LABEL(sunos_getpid)
C_LABEL(sunos_getpid):
	call	C_LABEL(sys_getppid)
	 nop

	call	C_LABEL(sys_getpid)
	 st	%o0, [%sp + STACKFRAME_SZ + PT_I1]

	b	C_LABEL(ret_sys_call)
	 st	%o0, [%sp + STACKFRAME_SZ + PT_I0]

	/* SunOS getuid() returns uid in %o0 and euid in %o1 */
	.globl	C_LABEL(sunos_getuid)
C_LABEL(sunos_getuid):
	call	C_LABEL(sys_geteuid16)
	 nop

	call	C_LABEL(sys_getuid16)
	 st	%o0, [%sp + STACKFRAME_SZ + PT_I1]

	b	C_LABEL(ret_sys_call)
	 st	%o0, [%sp + STACKFRAME_SZ + PT_I0]

	/* SunOS getgid() returns gid in %o0 and egid in %o1 */
	.globl	C_LABEL(sunos_getgid)
C_LABEL(sunos_getgid):
	call	C_LABEL(sys_getegid16)
	 nop

	call	C_LABEL(sys_getgid16)
	 st	%o0, [%sp + STACKFRAME_SZ + PT_I1]

	b	C_LABEL(ret_sys_call)
	 st	%o0, [%sp + STACKFRAME_SZ + PT_I0]

	/* SunOS's execv() call only specifies the argv argument, the
	 * environment settings are the same as the calling processes.
	 */
	.globl	C_LABEL(sunos_execv)
C_LABEL(sunos_execv):
	st	%g0, [%sp + STACKFRAME_SZ + PT_I2]

	call	C_LABEL(sparc_execve)
	 add	%sp, STACKFRAME_SZ, %o0

	b	C_LABEL(ret_sys_call)
	 ld	[%sp + STACKFRAME_SZ + PT_I0], %o0