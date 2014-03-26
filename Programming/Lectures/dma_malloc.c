/*
=========================
DYNAMIC MEMORY ALLOCATION
=========================

malloc() - 	allocates a contiguous block of memory
			during run-time and returns a pointer 
			to the start of the block.

pointer		 	=			malloc(size);

^^^^^^						       ^^^^
Pointer containing 			Size of block of
the address of the 			memory in bytes.
start at the block
*/

#include <stdio.h>
#include <stdlib.h>

main()
{
	int *ptr;
	int no_els, no_bytes, i;

	printf("How many numbers do you want to enter:");
	scanf("%d", &no_els);

	no_bytes = no_els * sizeof(int);	//size of memory required

	/*Allocate memory*/
	ptr = (int*)malloc(no_bytes);		//casting to some other int (int*)

	if(ptr == NULL)		//NULL is nothing
	{
		printf("Cannot allocate memory");
	}//end if
 	
	else
	{
		/*Enter all the numbers*/
		printf("Enter the numbers:\n");
		for (i = 0; i < no_els; ++i)
		{
			scanf("%d", &*(ptr + i));
		}//end for


		/*Display all the numbers*/
		for (i = 0; i < no_els; ++i)
		{
			printf("%d\n", *(ptr+i));
		}//end for

		free(ptr);	//free the memory after use (not wiped)

	}//end else
}//END MAIN