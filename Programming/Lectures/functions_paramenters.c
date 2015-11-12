/*
PARAMETERS
(arguments)

Pass by value.
A copy of the parameter is passed to a function.
*/

#include <stdio.h>

void stars(int, char); //declare parameter(s') type(s)

main()
{
	int num = 0;
	printf("Before function call \n");

	printf("How many stars?\n");
	scanf("%d", &num);

	stars(num, 'F');	//Parameters passed to the function

	printf("\nAfter function call \n");
}//end main

void stars(int num_stars, char my_char) //Declare types and parameters' variable names
{
	int i;	
	for(i = 0; i < num_stars; i++)
	{
		printf("*");
	}//end for
}//end stars