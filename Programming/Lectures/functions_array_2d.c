/*
===============================
PASSING 2-D ARRAY TO A FUNCTION
===============================
*/

#include <stdio.h>

//Declare prototype
int sum_array(int[][2], int);

main()
{
	int values[5][2] = {31, 14,
						51, 7,
						3, 11,
						6, 8,
						44, 90};
	int sum = 0;

	//Call function
	sum = sum_array(values, 5);

	printf("The sum of the values in the array is %d\n", sum);

}//end main


/*Implement function sum_array()*/
int sum_array(int my_array[][2],int no_of_rows)
{
	int i, j;
	int total = 0;

	for(i = 0; i < no_of_rows; i++)
	{
		for(j = 0; j < 2; j++)
		{
			total = total + my_array[i][j];
		}//end inner for
	}//end outer for

	return(total);
}//end sum_array