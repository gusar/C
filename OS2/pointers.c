#include <stdio.h>

main()
{
	int array[8] = {7,6,8,3,2,14,11,12};
	int count = 0;
	int i;
	for(i = 0; i < 8; i++)
	{
		if( (*(array+i)%2) == 0)
		{
			count++;
		}
		if(i == 4)
		{
			printf("5th element: %d\n", *(array+i));
		}
	}
	printf("Even count: %d", count);

}