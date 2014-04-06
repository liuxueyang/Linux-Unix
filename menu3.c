/*
 * =====================================================================================
 *       Filename : menu3.c
 *    Description : redirect some output to terminal while others to file
 *    Version     : 0.3
 *        Created : 04/06/14 16:11
 *         Author : Liu Xue Yang (LXY), liuxueyang457@163.com
 *         Motto  : How about today?
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char *menu[] = {
	"a - add new record",
	"d - delete record",
	"q - quit",
	NULL
};

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  getchoice
 *  Description:  print menu and get choice
 * =====================================================================================
 */
	int
getchoice ( char *greet, char * choices[], FILE *in, FILE *out )
{
	int chosen = 0;
	int selected;
	char **option;

	do
	{
		fprintf ( out, "Choice: %s\n", greet );
		option = choices;
		while ( *option ) {
			fprintf ( out, "%s\n", *option );
			++option;
		}
		do {
			selected = fgetc(in);
		} while ( '\n' == selected );				/* -----  end do-while  ----- */
		option = choices;
		while ( *option ) {
			if ( selected == *option[0] ) {
				chosen = 1;
				break;
			}
			++option;
		}
		if ( !chosen ) {
			fprintf ( out, "Incorrect choice, select again\n" );
		} 
	} while (!chosen);
	return selected;
}		/* -----  end of function getchoice  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name: main
 * =====================================================================================
 */

	int
main ( int argc, char *argv[] )
{
	int choice = 0;
	FILE *in, *out;

	if ( !isatty(fileno(stdout)) ) {
		fprintf(stderr, "You are not a terminal!\n");
//		exit(1);
	}
	in = fopen("/dev/tty", "r");
	out = fopen("/dev/tty", "w");
	if ( !in || !out ) {
		fprintf(stderr, "Unable to open /dev/tty\n");
		exit(1);
	}
	do
	{
		choice = getchoice("Please select an action", menu, in, out);
		printf ( "You have chosen: %c\n", choice );
	} while (choice != 'q');

		return EXIT_SUCCESS;
}


