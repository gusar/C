/*
Andrejs Lahs
3-12-2013
Labtest 2

Program uses arrays to receive values
for gallons and miles, then calculates
mpg and outputs the result.
*/

#include <stdio.h>

#define SIZE 5	//size of arrays

main()
{
	int i;
	float gallons[SIZE] = {0};	//initialising arrays
	float miles[SIZE] = {0};
	float mpg[SIZE] = {0};

	/*Asking for gallons values*/
	for(i = 0; i < SIZE; i++)
	{
		printf("Enter value number %d for gallons:\n", (i+1));
		scanf("%f", (gallons+i));
	}//end for

	/*Asking for miles values*/
	for(i = 0; i < SIZE; i++)
	{
		printf("Enter value number %d for miles:\n", (i+1));
		scanf("%f", (miles+i));
	}//end for


	/*Calculating mgp and immediately printing it out*/
	for(i = 0; i < SIZE; i++)
	{
		*(mpg+i) = *(miles+i) / *(gallons+i);

		printf("MPG %d: %.2f\n", (i+1), *(mpg+i));	//print results to 2 decimal points
	}//end for

}//END MAIN