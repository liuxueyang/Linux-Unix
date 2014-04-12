/*
 * =====================================================================================
 *       Filename : hostget.c
 *    Description : utsname struct
 *    Version     : 0.1
 *        Created : 04/06/14 10:55
 *         Author : Liu Xue Yang (LXY), liuxueyang457@163.com
 *         Motto  : How about today?
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <unistd.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name: main
 * =====================================================================================
 */

	int
main ( int argc, char *argv[] )
{
//	char computer[256];
	struct utsname uts;
//	if ( gethostname(computer, 256) != 0 || uname(&uts) != -1 ) {
//		fprintf(stderr, "Could not get host information");
//		exit(1);
//	}
//	printf ( "Computer host name is %s\n", computer );
	uname(&uts);
	printf ( "System is %s on %s hardware\n", uts.sysname, uts.machine );
	printf ( "Nodename is %s\n", uts.nodename );
	printf ( "Version is %s, %s\n", uts.release, uts.version );

		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

