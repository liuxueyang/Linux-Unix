/*
 * =====================================================================================
 *       Filename : ctime.c
 *    Description : ctime
 *    Version     : 0.1
 *        Created : 03/31/14 15:01
 *         Author : Liu Xue Yang (LXY), liuxueyang457@163.com
 *         Motto  : How about today?
 * =====================================================================================
 */
#include <time.h>
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
	time_t timeval;
	time(&timeval);
	printf ( "The date is: %s\n", ctime(&timeval) );

		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

