/*
 * =====================================================================================
 *       Filename : more02.c
 *    Description : read and print 24 lines then pause for user to type some command
 *    Version     : 0.2
 *        Created : 03/08/14 12:27
 *         Author : Liu Xue Yang (LXY), liuxueyang457@163.com
 *         Motto  : How about today?
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#define	PAGELEN 24			/* lines in a page */
#define	LINELEN 512			/* length of a line */

int do_more(FILE *);
int see_more(FILE *);

	int
main ( int argc, char *argv[] )
{
	FILE *fp;
	if ( argc == 1 ) {
		do_more(stdin);
	}
	else {
		while ( --argc ) {
			
			if ( (fp = fopen(* ++argv, "r")) ) {
				do_more(fp);
				see_more(fp);
			}
			else {
				exit(1);
			}
		}
	}

		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  do_more
 *  Description:  read PAGELEN lines, then call see_more() for further instructions
 * =====================================================================================
 */
	int
do_more ( FILE *fp)
{
	FILE *fp_tty;
	int num_of_lines = 0, reply;
	char line[LINELEN];
	fp_tty = fopen("/dev/tty", "r");
	if ( fp_tty == NULL ) {
		exit(1);
	}
	while ( (fgets(line, LINELEN, fp)) != NULL ) {
		
		if ( PAGELEN == num_of_lines ) {
			reply = see_more(fp_tty);
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
 *  Description:  wait for user enter some command
 * =====================================================================================
 */
	int
see_more ( FILE *fp )
{
	int c;
	printf ( "\033[7m more? \033[m" );
	while ( (c = getc(fp)) != EOF ) {
		
		if ( c == ' ' ) {
			return PAGELEN;
		}
		if ( c == '\n' ) {
			return 1;
		}
		if ( c == 'q' ) {
			return 0;
		}
	}
	return 0;
}		/* -----  end of function see_more  ----- */
