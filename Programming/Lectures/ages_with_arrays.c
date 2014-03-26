/*Program to read ages, find oldest, youngest and average*/

			/*ALSO USING SYMBOLIC NAME*/

#include <stdio.h>
#define SIZE 5	//<<----symbolic name

main()
{
	int ages[SIZE];
	int i;
	int total_age = 0;
	int oldest = 0;
	int youngest = 0;
//	int total_people = 0;

//	printf("\nEnter the total number of people: \n");
//	scanf("%d", &total_people);

	printf("\nEnter the ages of %d people: \n", SIZE);

	for(i = 0; i < SIZE; i++)	//read ages into array
	{
		scanf("%d", &ages[i]);
		total_age = total_age + ages[i];
	}	//end for()

	youngest = ages[0];	//assume the youngest and oldest age
	oldest = ages[0];	//entered is stored in the 1st element of the array.

	for(i = 0; i < SIZE; i++)	//cycle through array to compare numbers
	{
		if(ages[i] > oldest)	//figure out oldest age
		{
			oldest = ages[i];

		}	//end if

		if(ages[i] < youngest)	//figure out youngest age
		{
			youngest = ages[i];
		}	//end if
	}	//end for

	printf("\nThe youngest age is %d", youngest);
	printf("\nThe oldest age is %d", oldest);
	printf("\nThe average is %.1f\n\n", (float)total_age / 5);
}	//end main