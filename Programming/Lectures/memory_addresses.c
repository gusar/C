/*
Program to display memory addresses
*/

#include <stdio.h>

main()
{
	int var1 = 1;
	char var2 = 'A';

	int *ptr1 = &var1;
	char *ptr2 = &var2;

	printf("\nAddresses:");
	printf("\nptr1 contains %p\n", ptr1);
	printf("ptr2 contains %p\n\n", ptr2);

	/*SLOWER*/
	printf("\nNo preloaded address:");
	printf("\nvar1 contains %d and stored at address %p\n", var1, &var1);
	printf("var2 contains %c and stored at address %p\n\n", var2, &var2);

	/*FASTER*/
	printf("Indirection Operator (preloaded addresses):");
	printf("\n*ptr1 contains %d\n", *ptr1);
	printf("*ptr2 contains %d\n\n", *ptr2);
}