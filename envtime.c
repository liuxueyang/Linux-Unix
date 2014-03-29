/*
 * =====================================================================================
 *       Filename : envtime.c
 *    Description : get time system
 *    Version     : 0.1
 *        Created : 03/29/14 15:12
 *         Author : Liu Xue Yang (LXY), liuxueyang457@163.com
 *         Motto  : How about today?
 * =====================================================================================
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>


	int
main ( int argc, char *argv[] )
{
	int i;
	time_t the_time;
	for ( i = 1; i <= 10; ++i ) {
		the_time = time((time_t *) 0);
		printf ( "The time is %ld\n", the_time);
		sleep(2);
	}

		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

