/*Program displays fibonacci sequence numbers
up to a term that is requested by user*/

#include <stdio.h>

main()
{
	int num_current, num_next1, num_next2, user_i;	//declaration of variables
	int i;
	
	num_current = 0;	//initial values for fibonacci sequence
	num_next1 = 1;
	num_next2 = 1;
	
	printf("\nFibonnaci sequence.\nPlease enter the number of terms to be shown: "); //request the number of terms to be shown
	scanf("%d", &user_i);
	printf("\n");
	
	for(i = 0; i < user_i; i++)		//loop calculates current and 2 next values of the sequence and prints the current term
	{	
		printf("%d", num_current);
		num_next2 = num_next1 + num_current;
		num_current = num_next1;
		num_next1 = num_next2;
		
		if(i<(user_i-1))	//if-else to decide whether to put a comma or a full stop after the number.
		{
			printf(", ");
		}	//endif
		else
		{
			printf(".\n");
		}	//end else
	}	//end for
	
	printf("\n");
}	//end main