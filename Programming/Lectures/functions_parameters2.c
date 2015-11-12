/*
PARAMETERS
*/

#include <stdio.h>

void number_sum(int, int);

main()
{
	int num1 = 0;
	int num2 = 0;
	printf("Enter two numbers \n");
	scanf("%d", &num1);
	scanf("%d", &num2);

	number_sum(num1, num2);
}//end main

void number_sum(int number1, int number2)
{
	int sum = 0;	
	sum = number1 + number2;
	printf("Sum: %d\n", sum);
}//end stars