/*Fibonacci sequence*/

#include <stdio.h>

main()
{
	int term, i;	//declaration of variables
	int current = 1;	//initial values for fibonacci sequence
	int minus_one = 1;
	int minus_two = 0;
	
	printf("Enter the number of terms to be shown: ");
	scanf("%d", &term);
	
	if(term==1) printf("0\n");
	else if(term==2) printf("1\n");
	else
	{
		for(i = 2; i < term; i++)
		{	
			current = minus_one + minus_two;
			minus_two = minus_one;
			minus_one = current;
		}	//end for
	printf("%d\n", current);
	}//end else
}	//end main