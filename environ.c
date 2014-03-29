/*
 * =====================================================================================
 *       Filename : environ.c
 *    Description : environment variable
 *    Version     : 0.1
 *        Created : 03/29/14 14:40
 *         Author : Liu Xue Yang (LXY), liuxueyang457@163.com
 *         Motto  : How about today?
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	int
main ( int argc, char *argv[] )
{
	char *var, *value;
	if ( 1 == argc || 3 < argc ) {
		fprintf ( stderr, "usage: environ var [value]\n");
		exit(1);
	}
	var = argv[1];
	value = getenv(var);
	if ( value ) {
		printf ( "Variable %s has value %s\n", var, value);
	}
	else {
		printf ( "Variable %s has no value\n", var);
	}
	if ( 3 == argc ) {
		char *string;
		value = argv[2];
		string = malloc(strlen(var) + strlen(value) + 2);
		if ( !string ) {
			fprintf ( stderr, "out of memory\n");
			exit(1);
		}
		strcpy(string, var);
		strcat(string, "=");
		strcat(string, value);
		printf ( "Calling putenv with: %s\n", string);
		if ( 0 != putenv(string) ) {
			fprintf ( stderr, "putenv failed\n");
			free(string);
			exit(1);
		}
		value = getenv(var);
		if ( value ) {
			printf ( "New value of %s is %s\n", var, value);
		}
		else {
			printf ( "New value of %s is null??\n", var);
		}
	}

		return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

