/*
 * =====================================================================================
 *       Filename : menu1.c
 *    Description : menu choice
 *    Version     : 0.1
 *        Created : 04/06/14 12:03
 *         Author : Liu Xue Yang (LXY), liuxueyang457@163.com
 *         Motto  : How about today?
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
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
		selected = getchar();
		option = choices;
		while ( *option ) {
			if ( selected == *option[0] ) {
				chosen = 1;
				break;
			}
			++option;
		}
		if ( !chosen ) {
			printf ( "Incorrect choice, select again\n" );
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

	do
	{
		choice = getchoice("Please select an action", menu);
		printf ( "You have chosen: %c\n", choice );
	} while (choice != 'q');

		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
