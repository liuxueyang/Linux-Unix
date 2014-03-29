/*
 * =====================================================================================
 *       Filename : showenv.c
 *    Description : show the enviroment
 *    Version     : 0.1
 *        Created : 03/29/14 14:57
 *         Author : Liu Xue Yang (LXY), liuxueyang457@163.com
 *         Motto  : How about today?
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
extern char **environ;

	int
main ( int argc, char *argv[] )
{
	char **env = environ;
	while ( *env ) {
		printf ( "%s\n", *env);
		++env;
	}

		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

