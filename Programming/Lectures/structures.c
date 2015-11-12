/*
==========
STRUCTURES
==========

1.
	Defining a structure.
		-Structure template
		-struct *structure tag* {*n amount of structure members*};
		e.g.
			struct student_rec
			{
				char firstname[11];
				char secondname[21];
				int ID;
				int results[5];
			};

			//data type data type variable variable
			struct student_rec student1, student2;
			
			//assign a string to the structure member
			strcpy(student1.firstname, "Joe");
*/

#include <stdio.h>
#include <stdlib.h>

/*Define prototype for student*/
struct student_rec
{
	char firstname[11];
	char surname[21];
	int ID;
	int results[5];
};

main()
{
	/*Create structure variable*/
	struct student_rec student;
	register int i; //register variable is stored in cpu

	/*Define student structure*/
	printf("Enter student name: ");	//get name
	scanf("%10s", student.firstname);

	printf("Enter student surname: "); //get surname
	scanf("%20s", student.surname);

	printf("Enter student ID: "); //get ID
	scanf("%d", &student.ID);

	printf("Enter student results:\n"); //get results
	for (i = 0; i < 5; ++i)
	{
		scanf("%d", &student.results[i]);
	}//end for


	/*Display student information*/
	printf("Student name: %s\n", student.firstname);
	printf("Student surname: %s\n", student.surname);
	printf("Student ID: %d\n", student.ID);
	printf("Student results:\n");
	for (i = 0; i < 5; i++)
	{
		printf("%d\n", student.results[i]);
	}
}//end main