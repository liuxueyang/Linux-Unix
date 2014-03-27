/*
 * =====================================================================================
 *       Filename : simple_write.c
 *    Description : System call function write
 *    Version     : 0.1
 *        Created : 03/27/14 11:16
 *         Author : Liu Xue Yang (LXY), liuxueyang457@163.com
 *         Motto  : How about today?
 * =====================================================================================
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


	int
main ( int argc, char *argv[] )
{
	
	if ( (write(1, "Here is some data\n", 18)) != 18 ) {
		write(2, "A write error has occurred on file descriptor 1\n", 46);
	}

		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

