/*
==============================
			RETURN
Returning Data From a Function
==============================

*/

#include <stdio.h>

//Declare prototype
int swap(int,int); // <return.type> function.name(<parameters>)

main()
{
	int num1, num2, total;
	printf("Enter two numbers:\n");
	scanf("%d%d", &num1, &num2);

	//Call function
//	total = sum(num1,num2);

	printf("The sum of %d and %d: %d\n", num1, num2, sum(num1,num2));
}//end main

/*Implement function sum()*/
int sum(int n1, int n2)
{
	int temp = 0;
	temp = n1 + n2;
	return(temp);
}//end sum