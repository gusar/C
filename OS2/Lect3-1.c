#include <stdio.h>

main()
{
	int i = 0;
	int num = 0;
	int count = 0;

	while(num <= 150 && i < 100)
	{
		scanf("%d", &num);
		i++	;
	}

	printf("Numbers before 150: %d\n", i-1);
}