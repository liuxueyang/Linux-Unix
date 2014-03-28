/*
 * =====================================================================================
 *       Filename : argopt.c
 *    Description : user of getopt function
 *    Version     : 0.1
 *        Created : 03/28/14 19:52
 *         Author : Liu Xue Yang (LXY), liuxueyang457@163.com
 *         Motto  : How about today?
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


	int
main ( int argc, char *argv[] )
{
	int opt;
	while ( -1 != (opt = getopt(argc, argv, ":if:lr")) ) {
		
		switch ( opt ) {
			case 'i':	
			case 'l':	
			case 'r':	
				printf ( "option: %c\n", opt);
				break;

			case 'f':	
				printf ( "filename: %s\n", optarg );
				break;

			case ':':	
				printf ( "option needs a value\n" );
				break;

			case '?':	
				printf ( "unknown option: %c\n", optopt );
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

