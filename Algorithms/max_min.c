/*Find min and max in an unordered array, then search array*/

#include <stdio.h>

void print(int[]);

main()
{
	int A[8] = {4,3,2,5,7,8,1,6};
	print(A);

	int search;
	printf("Enter a number within the range: ");
	scanf("%d", &search);
	int i;
	int min = A[0];
	int max = A[0];
	
	/*min_max*/
	for (i = 0; i < 8; ++i)
	{
		if (min > A[i])	min = A[i];
		else if ( max < A[i]) max = A[i];
	}
	printf("Max: %d\nMin: %d\n", max, min);	

	/*search*/
	for (i = 0; i < 8; ++i)
	{
		if(A[i] == search)
		{
			printf("%d is element number %d\n", search, i);
			break;
		}
	}
}//end main

void print(int array[])
{
	int i;
	for (i = 0; i < 8; ++i) printf("%d, ", array[i]);
	printf("\n");
}//end print