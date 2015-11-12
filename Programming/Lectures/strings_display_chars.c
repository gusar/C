/*
Display each character of a string
using pointer notation.
*/

#include <stdio.h>

main()
{
	char *p;
	p = "some text";

	//Display characters
	while(*p != '\0')	//while the current character is not the NULL character
	{
		printf("%c", *p);
		p++;	//increment the address in p
	}//end while
	printf("\n");
}//end main