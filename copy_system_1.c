/*
 * =====================================================================================
 *       Filename : copy_system_1.c
 *    Description : copy content from file.in to file.out
 *    Version     : 0.2
 *        Created : 03/27/14 16:44
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
	char block[1024];
	int in, out;
	int nread;

	in = open("file.in", O_RDONLY);
	out = open("file.out", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	while ( (nread = read(in, block, sizeof(block))) > 0 ) {
		write(out, block, nread);
	}

		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

