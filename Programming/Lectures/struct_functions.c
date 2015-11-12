/*
=================================
Passing a Structure to a Function
=================================
*/

#include <stdio.h>

struct student_rec
{
	char firstname[11];
	char surname[21];
	int ID;
	int results[5];
};

/*prototypes*/
void display(struct student_rec);
void get(struct student_rec*);

main()
{
	struct student_rec student;
	struct student_rec *ptr;

	ptr = &student;

	/*call get()*/
	get(ptr);

	/*cal display*/
	display(student);
}//end main

/*
Implement get()
PASS BY REFERENCE
working with pointers
*/
void get(struct student_rec *s_ptr)
{
	register int i;;
	printf("Enter firstname: \n");
	scanf("%11s", s_ptr -> firstname);

	printf("Enter surname: \n");
	scanf("%21s", s_ptr -> surname);

	printf("Enter ID: \n");
	scanf("%d", &(s_ptr -> ID) );

	printf("Enter results: \n");
	for(i = 0; i < 5; i++)
	{
		scanf("%d", &(s_ptr -> results[i]));
	}//end for
}//end get

/*
Implement display()
PASS BY VALUE
working with a copy of the struct
*/
void display (struct student_rec stu)
{
	register int i;

	printf("The student record is:\n");
	printf("Firstname: %s\n", stu.firstname);
	printf("Surname: %s\n", stu.surname);
	printf("ID: %d\n", stu.ID);
	printf("Results are:\n");

	for(i = 0; i < 5; i++)
	{
		printf("%d\n", stu.results[i]);
	}//end for
}//end display