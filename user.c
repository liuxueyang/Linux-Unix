/*
 * =====================================================================================
 *       Filename : user.c
 *    Description : uid and gid and so on.
 *    Version     : 0.1
 *        Created : 04/06/14 10:41
 *         Author : Liu Xue Yang (LXY), liuxueyang457@163.com
 *         Motto  : How about today?
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name: main
 * =====================================================================================
 */

	int
main ( int argc, char *argv[] )
{
	uid_t uid;
	gid_t gid;
	struct passwd * pw;

	uid = getuid();
	gid = getgid();
	printf ( "User is %s\n", getlogin() );
	printf ( "User IDs: uid = %d gid = %d\n", uid, gid );

	pw = getpwuid(uid);
	printf ( "UID passwd entry:\nname = %s, uid = %d, gid = %d, home = %s, shell = %s\n",
			pw->pw_name, pw->pw_uid, pw->pw_gid, pw->pw_dir, pw->pw_shell);

	pw = getpwnam("root");
	printf ( "root passwd entry:\nname = %s, uid = %d, gid = %d, home = %s, shell = %s\n",
			pw->pw_name, pw->pw_uid, pw->pw_gid, pw->pw_dir, pw->pw_shell);

		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

