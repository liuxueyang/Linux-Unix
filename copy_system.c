/*
 * =====================================================================================
 *       Filename : copy_system.c
 *    Description : copy content from file.in to file.out
 *    Version     : 0.1
 *        Created : 03/27/14 16:34
 *         Author : Liu Xue Yang (LXY), liuxueyang457@163.com
 *         Motto  : How about today?
 * =====================================================================================
 */
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


	int
main ( int argc, char *argv[] )
{
	char c;
	int in, out;

	in = open("file.in", O_RDONLY);
	out = open("file.out", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	while ( read(in, &c, 1) == 1 ) {
		write(out, &c, 1);
	}

		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

