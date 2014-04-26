/*
 * =====================================================================================
 *       Filename : menu2.c
 *    Description : check whether there is a redirection
 *    Version     : 0.2
 *        Created : 04/06/14 15:52
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
getchoice ( char *greet, char * choices[] )
{
	int chosen = 0;
	int selected;
	char **option;

	do
	{
		printf ( "Choice: %s\n", greet );
		option = choices;
		while ( *option ) {
			printf ( "%s\n", *option );
			++option;
		}
		do {
			selected = getchar();
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
			printf ( "\nIncorrect choice, select again\n" );
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

	if ( !isatty(fileno(stdout)) ) {
		fprintf(stderr, "You are not a terminal!\n");
		exit(1);
	}
	do
	{
		choice = getchoice("Please select an action", menu);
		printf ( "\nYou have chosen: %c\n", choice );
	} while (choice != 'q');

		return EXIT_SUCCESS;
}

