/*
===============================
PASSING 1-D ARRAY TO A FUNCTION
===============================
*/

#include <stdio.h>

#define SIZE 10

//Declare prototype
int sum_array(int[]);

main()
{
	int values[SIZE];
	int sum = 0;
	int i;

	printf("Enter values into array\n");

	for(i = 0; i < SIZE; i++)
	{
		scanf("%d", &values[i]);
	}

	//Call function

	//Actually passes by REFERENCE, as "values" is the address of the first element.
	sum = sum_array(values);	//Only needs the NAME of the array
	printf("The sum of the values in the array is %d\n", sum);

}//end main


/*Implement function sum_array()*/
int sum_array(int my_array[])
{
	int local_sum = 0;
	int i;

	for(i = 0; i < SIZE; i++)
	{
		local_sum = local_sum + my_array[i];
	}//end for

	return(local_sum);
}//end sum_arrays