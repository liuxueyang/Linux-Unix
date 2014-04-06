/*
 * =====================================================================================
 *       Filename : strftime.c
 *    Description : strftime and strptime uses
 *    Version     : 0.1
 *        Created : 04/06/14 09:49
 *         Author : Liu Xue Yang (LXY), liuxueyang457@163.com
 *         Motto  : How about today?
 * =====================================================================================
 */
#include <stdio.h>
#include <time.h>
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
	struct tm *tm_ptr;
	time_t the_time;
	char buf[256];
	char *result;

	time(&the_time);
	tm_ptr = localtime(&the_time);
	strftime(buf, 256, "%A %d %B, %H:%M %p", tm_ptr);
	printf ( "strftime gives: %s\n", buf );

	strcpy(buf, "Thu 26 July 2007, 17:53 will do fine.");
	printf ( "calling strptime with: %s\n", buf );
	result = strptime(buf, "%a %d %b %Y, %H:%M %p", tm_ptr);

	printf ( "strptime consumed up to %s\n", result ); /* I does not end up with "will do fine"? */
	printf ( "strptime gives : \n" );
	printf ( "date: %02d/%02d/%02d %02d\n", tm_ptr->tm_year % 100, tm_ptr->tm_mon + 1,
			tm_ptr->tm_mday, tm_ptr->tm_wday);
	printf ( "time: %02d:%02d\n", tm_ptr->tm_hour, tm_ptr->tm_min );

		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

