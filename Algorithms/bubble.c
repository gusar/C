/*
Bubble Sort
*/

#include <stdio.h>

#define NUM 8

void print(int[]);

main()
{
	int i, j, swapped, temp, counter;
	int A[NUM] = {1,5,4,3,2,6,7,8};
	counter = 0;

	print(A);

	for(i = 0; i < NUM-1; i++)
	{
		swapped = 0;
		for(j = 0; j < NUM-1; j++)
		{
			if(A[j] > A[j+1])
			{
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
				swapped = 1;
			}//end if
		}//end inner for
		counter++;

		if(swapped = 0) break;

	}//end outer for	

	print(A);
	printf("Number of passes: %d\n", counter);
}//end main

void print(int array[])
{
	int i;
	/*Print everything*/
	for(i = 0; i < NUM; i++)
	{
		printf("%d ", array[i]);
	}//end for
	printf("\n");
}//end print