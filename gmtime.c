/*
 * =====================================================================================
 *       Filename : gmtime.c
 *    Description : print current time
 *    Version     : 0.1
 *        Created : 03/29/14 15:20
 *         Author : Liu Xue Yang (LXY), liuxueyang457@163.com
 *         Motto  : How about today?
 * =====================================================================================
 */
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

	int
main ( int argc, char *argv[] )
{
	struct tm *tm_ptr;
	time_t the_time;

	time(&the_time);
	tm_ptr = localtime(&the_time);

	printf ( "Raw time is %ld\n", the_time);
	printf ( "gmtime gives:\n" );
	printf ( "date: %02d/%02d/%02d/%02d\n",  
			tm_ptr->tm_wday, tm_ptr->tm_mon+1, tm_ptr->tm_mday, tm_ptr->tm_year + 1900);
	printf ( "time: %02d:%02d:%02d\n",
			tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);

	time_t now_time = 0;

	int tmp = mktime(tm_ptr);
	if ( -1 != tmp ) {
		now_time = tmp;
	}
	printf ( "Raw time is %ld\n", now_time );

	printf ( "buf_time = %s\n", asctime(tm_ptr) );

		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

