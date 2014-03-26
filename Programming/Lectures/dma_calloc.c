/*
	========
	CALLOC()
	========

calloc() -  also allocates memory dynamically, but unlike
			malloc(), calloc() initialises contents of the
			block to zero.

pointer = calloc( number, size );

^^^^^^^           ^^^^^   ^^^^
pointer to      number of  size of 
the address		elements   element
to the start	in the     in bytes
of the block	block

*/

#include <stdio.h>
#include <stdlib.h>

main()
{
	float *ptr;
	int no_els, i;

	printf("How many elements?\n");
	scanf("%d", &no_els);

	/*Allocate the block of memory*/
	ptr = (float*)calloc(no_els, sizeof(float));	//sizeof(float) is 8 => 8 bytes per element

	/*Check if memory allocated successfully*/
	if(ptr == NULL)
	{
		printf("Cannot allocate memory");
	}//end if

	else
	{
		/*Enter data into block*/
		printf("Enter the values:\n");
		for(i = 0; i < no_els; i++)
		{
			scanf("%f", &*(ptr+i));
		}//end for

		/*Display dara entered*/
		for(i = 0; i < no_els; i++)
		{
			printf("%.2f, ", *(ptr+i));
		}//end for
		printf("\n");

		/*Release block of memory*/
		free(ptr);
	}//end else
}//END MAIN