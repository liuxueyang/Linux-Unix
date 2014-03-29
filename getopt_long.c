/*
 * =====================================================================================
 *       Filename : getopt_long.c
 *    Description : get options of the command
 *    Version     : 0.2
 *        Created : 03/29/14 14:13
 *         Author : Liu Xue Yang (LXY), liuxueyang457@163.com
 *         Motto  : How about today?
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#define _GNU_SOURCE

	int
main ( int argc, char *argv[] )
{
	int opt;
	struct option longopts[] = {
		{"initialize", 0, NULL, 'i'},
		{"file", 1, NULL, 'f'},
		{"list", 0, NULL, 'l'},
		{"restart", 0, NULL, 'r'},
		{0, 0, 0, 0}
	};
	while ( (opt = getopt_long(argc, argv, ":if:lr", longopts, NULL)) != -1 ) {
		switch ( opt ) {
			case 'i':	
			case 'l':	
			case 'r':	
				printf ( "option: %c\n", opt);
				break;

			case 'f':	
				printf ( "filename: %s\n", optarg);
				break;

			case ':':	
				printf ( "option needs a value\n" );
				break;

			case '?':	
				printf ( "unknown option: %c\n", optopt);
				break;

			default:	
				break;
		}				/* -----  end switch  ----- */
	}
	for ( ; optind < argc; ++optind ) {
		printf ( "argument: %s\n", argv[optind]);
	}

		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

