/*
 * =====================================================================================
 *       Filename : simple_read.c
 *    Description : System function call
 *    Version     : 0.1
 *        Created : 03/27/14 11:27
 *         Author : Liu Xue Yang (LXY), liuxueyang457@163.com
 *         Motto  : How about today?
 * =====================================================================================
 */
#include <stdlib.h>
#include <unistd.h>


	int
main ( int argc, char *argv[] )
{
	char buffer[128];
	int nread;

	nread = read(0, buffer, 128);
	if ( -1 == nread ) {
		write(2, "A read error has occured\n", 26);
	}

	if ( nread != (write(1, buffer, nread)) ) {
		write(2, "A write error has occured\n", 27);
	}

		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

