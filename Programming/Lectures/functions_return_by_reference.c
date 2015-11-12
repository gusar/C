/*
#include <stdio.h>

int* fxn();

main()
{
	...
	...

}//end main

int* fxn()
{
	static int num1;	//memory for num1 will remain
	...
	...
	return(&num1);
}//end fxn

/*=====================*/

const float pi = 3.14;	//value can not be changed
float* circle_area(float*);

main()
{
	float radius = 0;
	printf("Enter a radius: ");
	scanf("%f, &radius");

	c_area = circle_area(&radius);
	printf("Area is: %2f", c_area);
}//end main

float* circle_area(float *ptr)
{
	float area = 0;
	area = pi * *(ptr) * *(ptr);
	return(&area);	
}//end circle_area