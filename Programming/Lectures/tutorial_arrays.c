/*Arrays_tutorial*/

#include <stdio.h>

main()
{

	for(i = 1; i < 10; i++)
	{
		a[i] = 9 - 1;
	}

	for(i = 1; i < 10; i++)
	{
		a[i] = a[a[i]];
	}
}//end main