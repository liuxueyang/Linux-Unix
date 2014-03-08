/*
 * =====================================================================================
 *       Filename : more01_1.c
 *    Description : I write myself
 *    Version     : 0.1
 *        Created : 03/08/14 12:40
 *         Author : Liu Xue Yang (LXY), liuxueyang457@163.com
 *         Motto  : How about today?
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#define	PAGELEN 24			/* # of lines in a page */
#define	LINELEN 512			/* # of chars in a line */

int do_more(FILE*);
int see_more();
	int
main ( int argc, char *argv[] )
{
	FILE *fp;

	if ( argc == 1 ) {
		do_more(stdin);
	}
	else {
		while ( --argc ) {
			if ( (fp = fopen(* ++argv, "r")) != NULL ) {
				do_more(fp);
			}
			else {
				break;
			}
		}
	}

		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  do_more
 *  Description:  read 24 lines and then wait for user's command
 * =====================================================================================
 */
	int
do_more ( FILE *fp )
{
	char line[LINELEN];
	int num_of_lines = 0;
	int reply;
	while ( (fgets(line, LINELEN, fp)) != NULL ) {
		if ( PAGELEN == num_of_lines ) {
			reply = see_more();
			if ( reply == 0 ) {
				break;
			}
			num_of_lines -= reply;
		}
		fputs(line, stdout);
		++num_of_lines;
	}

	return 0;
}		/* -----  end of function do_more  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  see_more
 *  Description:  wait for user's command
 * =====================================================================================
 */
	int
see_more (  )
{
	int c;
	printf ( "\033[7m more?\033[m" );
	while ( (c = getchar()) != EOF ) {
		if ( c == '\n' ) {
			return 1;
		}
		if ( c == ' ' ) {
			return PAGELEN;
		}
		if ( c == 'q' ) {
			return 0;
		}
	}
	return 0;
}		/* -----  end of function see_more  ----- */
