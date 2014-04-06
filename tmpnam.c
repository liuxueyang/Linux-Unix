/*
 * =====================================================================================
 *       Filename : tmpnam.c
 *    Description : tmpnam uses
 *    Version     : 0.1
 *        Created : 04/06/14 10:21
 *         Author : Liu Xue Yang (LXY), liuxueyang457@163.com
 *         Motto  : How about today?
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name: main
 * =====================================================================================
 */

	int
main ( int argc, char *argv[] )
{
	char tmpname[L_tmpnam] = ".xxxxxx";
	char *filename;
	int tmpfp;

	filename = mktemp(tmpname);
	printf ( "Temporary file name is %s\n", filename );
	tmpfp = mkstemp(filename);
	if ( tmpfp ) {
		printf ( "Open a temporary file OK\n" );
	}
	else {
		perror("tmpfile");
	}

		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

