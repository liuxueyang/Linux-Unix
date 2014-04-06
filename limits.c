/*
 * =====================================================================================
 *       Filename : limits.c
 *    Description : useage of some functions of resources and limits
 *    Version     : 0.1
 *        Created : 04/06/14 11:23
 *         Author : Liu Xue Yang (LXY), liuxueyang457@163.com
 *         Motto  : How about today?
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  work
 *  Description:  do some unuseful work
 * =====================================================================================
 */
	void
work (  )
{
	FILE *f;
	int i;
	double x = 4.5;

	f = tmpfile();
	for ( i = 0; i < 10000; ++i ) {
		fprintf(f, "Do some output\n");
		if ( ferror(f) ) {
			fprintf(stderr, "Error writing to temporary file\n");
			exit(1);
		}
	}
	for ( i = 0; i < 1000000; ++i ) {
		x = log(x * x + 3.21);
	}
	return ;
}		/* -----  end of function work  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name: main
 * =====================================================================================
 */

	int
main ( int argc, char *argv[] )
{
	struct rusage r_usage;
	work();
	getrusage(RUSAGE_SELF, &r_usage);
	printf ( "CPU usage: User = %ld.%06d, System = %ld.%06d\n",
			r_usage.ru_utime.tv_sec, r_usage.ru_utime.tv_usec,
			r_usage.ru_stime.tv_sec, r_usage.ru_stime.tv_usec);

	int priority;
	priority = getpriority(PRIO_PROCESS, getpid());
	printf ( "Current priority = %d\n", priority );

	struct rlimit r_limit;
	getrlimit(RLIMIT_FSIZE, &r_limit);
	printf ( "Current FSIZE limit: soft = %lld, hard = %lld\n",
			r_limit.rlim_cur, r_limit.rlim_max);

	r_limit.rlim_cur = 2048;
	r_limit.rlim_max = 4096;
	printf ( "Setting a 2K file size limit\n" );
//	setrlimit(RLIMIT_FSIZE, &r_limit);

	work();
	getrusage(RUSAGE_SELF, &r_usage);
	printf ( "CPU usage: User = %ld.%06d, System = %ld.%06d\n",
			r_usage.ru_utime.tv_sec, r_usage.ru_utime.tv_usec,
			r_usage.ru_stime.tv_sec, r_usage.ru_stime.tv_usec);

		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
