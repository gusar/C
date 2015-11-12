/*
25Feb2014
Andrejs Lahs
C13766231

Program takes Celcius values from user and uses a function
to convert them to Fahrenteit, display both. Then
the program calculates the average of Celcius values,
displays them, converts the value to Kelvin, and displays
the new value.
*/

#include <stdio.h>

#define NUM 5

float convert_temp(float[]); //declare prototypes
void in_Kelvin(float*);

main()
{
	float celcius[NUM], average; //declare all variables
	int i;

	printf("Enter 5 temperature values in Celcius:\n"); //get 5 float values from user
	for(i = 0; i < NUM; i++)
	{
		scanf("%f", &celcius[i]);
	}//end for

	average = convert_temp(celcius);	//call convert_temp function
	printf("The average of all Celcius values is: %.2f\n", average);

	in_Kelvin(&average);	//average value will change to kelvin
	printf("Celcius average is also: %.2f Kelvin\n", average);
}//end main


float convert_temp(float c[])
{
	float fahrenheit, function_average, sum = 0; //declare variables
	int i;

	for(i = 0; i < NUM; i++) //values get converted here, result is displayed, and sum is calculated.
	{
		fahrenheit = ((c[i] * 9) / 5) + 32;	//conversion formula
		printf("%.2f Celcius = %.2f Fahrenheit\n", c[i], fahrenheit);
		sum = sum + c[i];	//making a sum of all celcius value
	}//end for

	function_average = sum / NUM;
	return(function_average); //return the average celcius value;
}//end convert_temp


void in_Kelvin(float *pointer)	//average variable address it used to change its value
{
	*pointer = *pointer + 273;	//adress value is converted to kelvin
}//end in_Kelvin