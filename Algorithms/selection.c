/*
Selection Sorting Algorithm
*/

#include <stdio.h>

#define NUM 8

void print(int[]);

main()
{
	int i, j, min, temp;
	int A[NUM] = {1,5,4,3,2,6,7,8};

	print(A);

	for(i = 0; i < NUM-1; i++)
	{
		min = i;
		for(j = 0; j < NUM; j++)
		{
			if(A[j] < A [min])
			{
				min = j;
			}//end if
		}//end inner for
		temp = A[min];
		A[min] = A[i];
		A[i] = temp;
	}//end outer for

	print(A);

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