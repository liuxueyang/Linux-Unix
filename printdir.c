/*
 * =====================================================================================
 *       Filename : printdir.c
 *    Description : a simple implementation of command ls
 *    Version     : 0.1
 *        Created : 03/28/14 11:45
 *         Author : Liu Xue Yang (LXY), liuxueyang457@163.com
 *         Motto  : How about today?
 * =====================================================================================
 */
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  printdir
 *  Description:  list files in the directory
 * =====================================================================================
 */
	void
printdir ( char *dir, int depth  )
{
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;


	if ( NULL == (dp = opendir(dir)) ) {
		fprintf(stderr, "cannot open directory: %s\n", dir);
		return;
	}
	chdir(dir);
	while ( NULL != (entry = readdir(dp)) ) {
		lstat(entry->d_name, &statbuf);
		if ( S_ISDIR(statbuf.st_mode) ) {
			
			if ( 0 == strcmp(".", entry->d_name) || 
					0 == strcmp("..", entry->d_name) || 
					0 == strcmp(".git", entry->d_name)) {
				continue;
			}
			printf("%*s%s\n", depth, " ", entry->d_name);
			printdir(entry->d_name, depth + 4);
		}
		else {
			printf("%*s%s\n", depth, " ", entry->d_name);
		}
	}
	chdir("..");
	closedir(dp);
	return ;
}		/* -----  end of function printdir  ----- */



	int
main ( int argc, char *argv[] )
{
	char *topdir = ".";

	if ( argc >= 2 ) {
		topdir = argv[1];
	}
	printf("Directory scan of %s\n", topdir);
	printdir(topdir, 0);
	printf("done.\n");

		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
