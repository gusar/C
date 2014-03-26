/*
=========
FUNCTIONS
(Methods)
=========

Program that uses a function:
*/

#include <stdio.h>
#define NUM 5

//Declare function prototype
void stars(void);	//Preferably outside of main()

/*
int var1;   Global variable visible to
			the entire program. Dangerous.
*/

main()	//Can't call main function
{
	printf("Before function call \n");

	//Call function
	stars();

	printf("After function call \n");
}//end main

//Implement function stars()
void stars()
{
	int i;	/*Local variables are declared in a 
			  function and can't be used outside of it*/
	for(i = 0; i < NUM; i++)
	{
		printf("*");
	}//end for
}//end stars