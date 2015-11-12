/*
	TUTORIAL
	--------
	Pointers
*/

/*
INDIRECTION OPERATOR *
	used to access the contents of the variable
	whose address is stored in a pointer.
*/

#include <stdio.h>

main()
{
	int num1 = 2;
	char my_char = 'z';
	
	int *ptr1;
	char *ptr2;

	ptr1 = &num1;	//here ptr1 is the address of num1 variable
	ptr2 = &my_char;

	/*contents of num1 variable*/
	printf("\nnum1 (num1) contains %d", num1);	
	/*contents of my_char variable*/
	printf("\n\nmy_char contains %c", my_char);		


	/*contents of num1 accessed using Indirection Operator *ptr1 at the address of ptr1*/
	printf("\n\nnum1 (*ptr1) contains %d", *ptr1);
	/*conents of my_char found with Indirection operator*/
	printf("\nmy_char (*ptr1) contains %c\n\n", *ptr)


	/*print address of of num1 stored in pointer ptr1*/
	printf("\n\nnum1 (ptr1) address is %p", ptr1);
	/*address of num1 directly accessed by &*/
	printf("\nnum1 (&) address is %p", &num1);
	
}//end main