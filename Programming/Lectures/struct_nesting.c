/*
NESTING STRUCTS
*/

#include <stdio.h>

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
	struct person student;
	student.DOB.day = 12;
	student.DOB.month = 4;
	student.DOB.year = 1996;
}//end main