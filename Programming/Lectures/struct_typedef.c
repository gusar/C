/*
=======
TYPEDEF
=======

	-Similar to the symbolic name


*/

#include <stdio.h>

typedef int* INT_POINTER; //synonim

typedef struct date DATE;

struct date
{
	int day;
	int month;
	int year;
};

struct person
{
	char firstname[11];
	char surname[21];
	struct date DOB;
};

main()
{
	int *p1;
	int *p2;	//same as below

	INT_POINTER p1;		
	INT_POINTER p2;	
}