/*
=================
  Pass By Value
	   vs
Pass By Reference
=================
*/

#include <stdio.h>

void fxn_value(int);
void fxn_reference(int*);

main()
{
	int actual_arg = 1;

	/*Pass by Value*/
	printf("actual_arg is %d\n", actual_arg);
	fxn_value(actual_arg);
	printf("actual_arg is %d\n", actual_arg);
	/*End*/

	/*Pass by Reference*/
	printf("actual_arg is %d\n", actual_arg);
	fxn_reference(&actual_arg);
	printf("actual_arg is %d\n", actual_arg);
	/*End*/
}//end main


void fxn_value(int formal_arg)
{
	printf("formal arg_ is %d", formal_arg);
	formal_arg++;
}//end fxn_value


void fxn_reference(int *formal_arg)
{
	printf("formal arg_ is %d", *formal_arg);
	(*formal_arg)++;
}//end fxn_reference