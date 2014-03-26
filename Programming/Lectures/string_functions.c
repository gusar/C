/*
================
STRING FUNCTIONS
    string.h
================

1. strlen(string);
		-Returns legth of a string (excluding null character.

2. strcpy(destination_string, source_string);
		-Copies contents of string2 into string1.
		-Source string must be null terminated.
		-C assumes that destination string is large enough to fill in the source string.

3. strcat(string1, string2)
		-Joins strings together. 
		-Destination string must be large enough to hold the joined strings.

4. strcmp(string1, string2)
		-Returns a 0 if the two strings are identical, otherwise returns non-zero.
		-strcmp() compares 2 strings.
		-Both must be NULL-terminated.

4.5 strnsmp(dest, source, n)
		-Compares strings up to n characters

int n = atoi(string); - ASCII to integer.
double n = atol(string);
long n = atof(string);
*/

#include <stdio.h>
#include <string.h>

main()
{
	char name1[] = "Sharon";
	char name2[10] = "Mark";
	char *name3 = "Patrick";

	/*String Length*/
	int len;
	len = strlen(name1);

	printf("%d %lu %lu %lu %d\n", (int)strlen(name1), strlen(name2), strlen(name3), strlen("Rob"), len);	//6 4 7 3 6
	/*-------------*/

	/*Copy Strings*/
	strcpy(name2, name1);
	puts(name2);
	/*------------*/

	/*Join Stings*/
	char str1[15] = "first & ";
	char str2[] = "second";
	strcat(str1, str2);
	puts(str1);
	/*--------------*/ 

	/*Compare Strings*/
	char str3[] = "Hello World";
	char str4[] = "Hello World";
	int same = 1;
	same = strcmp(str3, str4);
	if(same == 0) printf("Same: %d", same);
	else printf("Different: %d", same);
	/*---------------*/
	printf("\n");

	/*Print an Array of Strings*/
	char *months[12] = {"Jan", "Fed", "Mar",
						"Apr", "May", "Jun",
						"Jul", "Aug", "Sep",
						"Oct", "Nov", "Dec"};
	int i;
	printf("The months are: ");
	for(i = 0; i < 12; i++) printf("%s ", *(months+i));
	/*---------------*/
	printf("\n");

}//end mai