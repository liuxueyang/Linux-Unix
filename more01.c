/*
 * =====================================================================================
 *       Filename : more01.c
 *    Description : read and print 24 lines then pause for a few special commands
 *    Version     : 0.1
 *        Created : 03/07/14 18:51
 *         Author : Liu Xue Yang (LXY), liuxueyang457@163.com
 *         Motto  : How about today?
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#define	PAGELEN 24			/* page lines */
#define	LINELEN 512			/* length of a line */

int see_more ( );
void do_more ( FILE *fp );

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
 *         Name:  see_more
 *  Description:  print messages, wait for response, return # of lines to advance
 *  q means no, space means yes, CR means next line
 * =====================================================================================
 */
	int
see_more (  )
{
	int c;
	printf ( "\033[7m more?\033[m\n" );
	while ( (c = getchar()) != EOF) {
		if ( c == 'q' ) {
			return 0;
		}
		if ( c == ' ' ) {
			return PAGELEN;
		}
		if ( c == '\n' ) {
			return 1;
		}
	}
	return 0;
}		/* -----  end of function see_more  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  do_more
 *  Description:  read PAGELEN lines, then call see_more() for future instructions
 * =====================================================================================
 */
	void
do_more ( FILE *fp )
{
	char line[LINELEN];
	int num_of_lines = 0;
	int see_more(), reply;
	while ( fgets(line, LINELEN, fp) ) {          /* more input */
		if ( num_of_lines == PAGELEN ) {            /* full page */
			reply = see_more();                       /* ask user */
			if ( reply == 0 ) {                       /* enter 'q' */
				break;
			}
			num_of_lines -= reply;
		}
		if ( fputs(line, stdout) == EOF ) {
			exit(1);
		}
		++num_of_lines;
	}
	return ;
}		/* -----  end of function do_more  ----- */
