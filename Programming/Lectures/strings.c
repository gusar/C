/*
=======
STRINGS
=======

A string (or literal) is any character(s) enclosed in double quotes.
	'\0' - Terminating NULL character at the end of every string.

"Hello", said the person.
printf("\"Hello\", said the person.");

Files are in the U:\ on the network.
printf("Files are in the U:\\ on the network.");

--------------
\n - new line
\t - tab
\' - single quote
\a - beep
\r - return cursor to the first position on the line
\b - bring cursor previous character position.

--------------
Long character strings:

	printf("This is a very long \
			string broken over tw\
			o or more lines");

	printf("This is a very long "
			"string broken into tw"
			"o or more lines");

---------------
char greeting[] = {'H','e','l','l','o','\0'};
char greeting[] = "Hello";

---------------
greeting.length() - length of string with name greeting

---------------
If we set a character array to be bigger than needed,
the unused slots will be filled with \0s.

---------------
puts() function 
	-displays string and moves to new line
	-no way of formatting

---------------
gets() function
	-is an alternative method to read strings

---------------
We can create a string pointer:
	char *p;
	p = "some text";
*/

#include <stdio.h>
 
 main()
 {
 	char name[21];
 	printf("Enter a name: ");	//puts("Enter a name");
 //	scanf("%20s", name);	//only reads string upto first space
 	gets(name);
 	printf("Your name is: ");
 	puts(name);
 }//end main