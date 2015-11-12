#include <stdio.h>

main()
{
	int i, j, branches, spaces, stars = 1;
	printf("Enter height in number of branches: ");
	scanf("%d", &branches);
	spaces = branches;

	for (i = 0; i < branches; i++)
	{
		for (j = 1; j < spaces; j++) printf(" ");
		for (j = 0; j < stars; j++) printf("*");
		printf("\n");
		spaces = spaces - 1;
		stars = stars + 2;
	}
	for (i = 1; i < branches; i++) printf(" ");
	printf("*\n");
}