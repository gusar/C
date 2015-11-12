/*------------------
int numbers[5] = {0,0,0,0,0};

int numbers[5] = {0};	//all elements will be zero

int numbers[5] = {,3};	//element [0] will be zero, element [1] will be 3, and the rest will be zero.
------------------*/

//initialising an array

#include <stdio.h>
#define NO_OF_MONTHS 12

main()
{
	int days[NO_OF_MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int month;

	printf("\nEnter a month, eg. 1 = Jan, 2 = Feb, etc.: ");

	do
	{
		scanf("%d", &month);
	}	//end do
	while(month < 1 || month > 12);

	printf("\nNumber of days in month %d is %d\n\n", month, days[month-1]);
}	//end main