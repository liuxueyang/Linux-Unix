/*
 * =====================================================================================
 *       Filename : sprintf.c
 *    Description : sprintf
 *    Version     : 0.1
 *        Created : 04/05/14 13:39
 *         Author : Liu Xue Yang (LXY), liuxueyang457@163.com
 *         Motto  : How about today?
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 
 * ===  FUNCTION  ======================================================================
 *         Name: main
 * =====================================================================================
 */

	int
main ( int argc, char *argv[] )
{
	char buf[100];
	sprintf(buf, "%d%s", 3, "liu");
	printf ( "buf = %s\n", buf );

	int a;
	char s[100];
	sscanf(buf, "%d %s", &a, s);
	printf ( "a = %d\ns = %s\n", a, s );

		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

