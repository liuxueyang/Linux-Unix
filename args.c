/*
 * =====================================================================================
 *       Filename : args.c
 *    Description : print arguments of the program and its options
 *    Version     : 0.1
 *        Created : 03/28/14 18:55
 *         Author : Liu Xue Yang (LXY), liuxueyang457@163.com
 *         Motto  : How about today?
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

	int
main ( int argc, char *argv[] )
{
	int arg;

	for ( arg = 0; arg < argc; ++arg ) {
		if ( '-' == argv[arg][0] ) {
			printf ( "option: %s\n" , argv[arg] + 1);
		}
		else {
			printf ( "argument %d: %s\n" , arg, argv[arg]);
		}
	}

		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

