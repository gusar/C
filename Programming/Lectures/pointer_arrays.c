/*
	POINTERS AND ARRAYS

		20 November
*/

#include <stdio.h>

#define SIZE 5

main()
{

/*	Pointer of an array is a pointer to 
	a contiguous block of variables .
	
	In C, the name of an array is the same as 
	the addrtess of the 1st element of that array.

	a ~ &a[0]
*/

	int a[SIZE];
	//Name of the array is the same as address of 1st element
	printf("a is %p and &a[0] is %p\n", a, &a[0]);

/*	a+1 ~ &a[1]
	a+2 ~ &a[2]
	a+3 ~ &a[3]
	a+4 ~ &a[4]
*/

	int i;
	for(i = 0; i < SIZE; i++)
	{
		printf("%p\n", &a[i]);	//Subscript notation
		printf("%p\n", a+i);	//Pointer nonation
	}//end for

/*	 a ~ &a[0]
	*a ~  a[0]	
or 
	*(a+0) ~ a[0]
	*(a+1) ~ a[1]
	*(a+2) ~ a[2]
	*(a+3) ~ a[3]
	*(a+4) ~ a[4]
*/	

	printf("\n");
	/*Display Content*/
	for(i = 0; i < SIZE; i++)
	{
		printf("%d\n", a[i]);	//Subscript notation
		printf("%d\n", *(a+i));	//Pointer notation
	}//end for

}//END MAIN