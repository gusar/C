/*
Fibonacci Sequence
	Recursion
*/

#include <stdio.h>

void fibonacci(int);
int counter = 0;
main()
{
	int number;
	printf("Enter a number: ");
	scanf("%d", &number);
	fibonacci(number);
}//end main

void fibonacci(int n)
{
	int old = 0;
	if((n==0) || (n==1))
	{
		printf("%d", n);
	}//end if
	else if(counter == n)
	{
		counter++;
		old + fibonacci(n);
	}//end else
	else
	{
		printf("%d", n);
	}
}//end fibonacci