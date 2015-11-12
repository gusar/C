/*
29Apr2014
Andrejs Lahs
C13766231

Programming
LabTest 4 

Program uses an array of struct variables and functions
to request details of passengers, store, and print them.

*/

#include <stdio.h>
#include <string.h>

#define SIZE 2


/* Structure templates for date and passengers */
struct date
{
	int day;
	int month;
	int year;
};

struct details
{
	char flight_number[11];
	struct date flight_date;
	char surname[21];
	char firstname[21];
	char seat_number[4];
};


/* Prototypes */
void input_passengers(struct details*[]);
void print_passengers(struct details*[]);



/*
 * MAIN
 * Prints welcome and exit messages,
 * Calls respective functions.
 */
 int main()
 {
 	int i;
 	struct details passengers[SIZE];
 	struct details *P[SIZE];

 	/* Loop assigns pointers to passengers array */
 	for(i = 0; i < SIZE; i++)
 	{
 		P[i] = &passengers[i];
 	}//end for

 	printf( "\nGlobe Ireland Airlines\n"
 			"----------------------\n");

 	/* Enter passenger info */
 	input_passengers(P);
 	printf("---------------------\n");

 	/* Print passenger info */
 	print_passengers(P);

 	printf("\nPress Return to Exit\n");
 	getchar();
 	getchar();
 }//end main



 /*
  * Function requests and stores passenger
  * info in a struct array.
  * Parameters: passengers struct array
  * Returns: void
  */
void input_passengers(struct details *P[SIZE])
{
	int i, d, m, y;
	char f_number[11];


	/* Request flight details */
	printf("\nPlease enter flight details:\n\n");

	printf("Flight number: ");
	scanf("%10s", f_number);

	printf("Flight date (dd/mm/yyyy): ");
	scanf("%d/%d/%d", &d, &m, &y);
	

	/* Loop requests details of all passenger */
	for(i = 0; i < SIZE; i++)
	{
		P[i] -> flight_date.day = d;
		P[i] -> flight_date.month = m;
		P[i] -> flight_date.year = y;
		strcpy(P[i] -> flight_number, f_number);

		printf("\nPlease enter passenger %d information:\n\n", i+1);

		printf("Surname: ");
		scanf("%20s", P[i] -> surname);

		printf("First Name: ");
		scanf("%20s", P[i] -> firstname);

		printf("Seat number: ");
		scanf("%3s", P[i] -> seat_number);
	}//end for
}//end input_passengers



/*
 * Function prints info that is stored
 * in the passengers struct
 * Parameters: passengers struct array
 * Returns: void
 */
void print_passengers(struct details *P[SIZE])
{
	/* Loop prints details of all passengers */
	int i;
	for(i = 0; i < SIZE; i++)
	{
		printf( "\nPassenger %d Details:\n\n"
				"Flight number: %s\n"
				"Flight date: %d/%d/%d\n"
				"Surname: %s\n"
				"First Name: %s\n"
				"Seat number: %s\n",
				 i+1, 
				 P[i] -> flight_number,
				 P[i] -> flight_date.day, 
				 P[i] -> flight_date.month, 
				 P[i] -> flight_date.year, 
				 P[i] -> surname,
				 P[i] -> firstname,
				 P[i] -> seat_number);
	}//end for
}//end print_passengers