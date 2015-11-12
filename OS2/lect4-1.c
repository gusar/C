#include <stdio.h>
#include <math.h>

main()
{
	int i, x, r, n, nfact;
	float sum = 0;
	nfact = 1;
	int power;

	printf("Enter x,r: ");
	scanf("%d,%d", &x, &r);

	for(n = 1; n <= 70; n++)
	{
		nfact = nfact * n;
		power = pow((x-r), n);

		sum = sum + (power / nfact);
	}

	printf("Sum: %f\n", sum);
}