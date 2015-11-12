/*

Functions edit the database file and update
the header record; add a new employee; mark an
employee for deletion by searching for record number;
list all employees, or search the records by key.

*/


#include <stdio.h>
#include <string.h>
#include <main.h>


extern struct header_rec header;
extern struct record employee;


/*
 * Function adds an employee struct to
 * database.dat file, increments header
 * Parameters: pointer to file link
 * Return: void
 */
int add_employee(FILE *pf)
{

	pf = fopen(DATABASE, "a+");

	/* Check if database is full */
	if(header.cur_number > 99999)
	{
		printf("\nDATABASE IS FULL");
		return 1;
	}

	// Set new employee number
	snprintf(employee.number, sizeof(employee.number), "%ld", header.cur_number);
	printf("\n-------------\nNumber: %s\n-------------\n", employee.number);

	// Get employee info
	printf("Enter Name: ");
	get_input(employee.firstName, sizeof(employee.firstName), stdin);

	printf("Enter Surname: ");
	get_input(employee.lastName, sizeof(employee.lastName), stdin);

	printf("Enter Address: ");
	get_input(employee.address, sizeof(employee.address), stdin);

	printf("Enter Department: ");
	get_input(employee.department, sizeof(employee.department), stdin);

	printf("Enter Duration: ");
	get_input(employee.duration, sizeof(employee.duration), stdin);

	if(fwrite(&employee, sizeof(struct record), 1, pf) == 0) 
	{
		printf("\nERROR ADDING EMPLOYEE");
		fclose(pf);
	}

	else
	{
		printf("\nEmployee added");
		fclose(pf);

		/* Increment and write header numbers */
		pf = fopen(DATABASE, "r+");
		header.active++;
		header.total++;
		header.cur_number++;
		write_header(pf);
		fclose(pf);
	}

	return 0;
}//end add_employee



/*
 * Function requests employee number and uses a loop
 * to check all records to find and remove that 
 * employee from the list of active entries.
 * Parameters: pointer to file link
 * Returns: void
 */
void delete_employee(FILE *pf)
{
	pf = fopen(DATABASE, "r+");

	fseek(pf, sizeof(struct header_rec), SEEK_CUR);

	char key[KEY_SIZE] = {0};
	printf("\nEmployee Number\n: ");
	get_input(key, sizeof(key), stdin);


	/* Loop while records exist */
	int not_found = 1;
	while(fread(&employee, sizeof(struct record), 1, pf) != 0)
	{
		/* Compare key with the record */
		if(strcmp(key, employee.number) == 0)
		{
			fseek(pf, -sizeof(struct record), SEEK_CUR);
			fwrite("*", 1, 1, pf);
			printf("\nEmployee number %s is now deleted", key);

			/* Adjust header */
			fseek(pf, 0, SEEK_SET);
			header.active--;
			header.deleted++;
			write_header(pf);

			not_found = 0;
			break;
		}//end if
	}//end while
	if(not_found == 1) printf("\nNot found");

	fclose(pf);
}//end delete_employee



/*
 * Function prints file header and active
 * employees which are requested by user:
 * all, or search by name, surname,
 * department, or duration.
 * Parameters: pointer to file link
 * Returns: void
 */
void list_employees(FILE *pf)
{
	pf = fopen(DATABASE, "r");

	/* Request and set a search key (if any) */
	char search_type[OPTION_SIZE];
	char *search_var;
	char search_key[SEARCH_SIZE];
	printf( "List all records (1) OR\nSearch by: Name (2)/ "
			"Surname (3)/ Department (4)/ Duration (5): ");

	get_input(search_type, sizeof(search_type), stdin);

	switch(*search_type)
	{
		case '2':
			search_var = employee.firstName;
			printf("\nEnter name: ");
			get_input(search_key, sizeof(search_key), stdin);
			break;

		case '3':
			search_var = employee.lastName;
			printf("\nEnter surname: ");
			get_input(search_key, sizeof(search_key), stdin);
			break;

		case '4':
			search_var = employee.department;
			printf("\nEnter department: ");
			get_input(search_key, sizeof(search_key), stdin);
			break;

		case '5':
			search_var = employee.duration;
			printf("\nEnter duration: ");
			get_input(search_key, sizeof(search_key), stdin);
			break;

		default: break;
	}//end switch

	printf("\n================\n");
	read_header(pf);
	printf("----------------\n");

	int not_found = 1;
	while(fread(&employee, sizeof(struct record), 1, pf) != 0)
	{
		if(*employee.number != '*')
		{
			if(*search_type == '1' || (*search_type != '1' && strcmp(search_key, search_var) == 0))
			{
				not_found = 0;
				printf( "Number: %s\n"
						"Full Name: %s %s\n"
						"Address: %s\n"
						"Department: %s\n"
						"Duration: %s\n"
						"----------------\n",
						employee.number, employee.firstName, employee.lastName,
						employee.address, employee.department, employee.duration );
			}//end if
		}//end if
	}//end while
	if(not_found == 1) printf("\nNo such records found!\n\n");

	fclose(pf);
}//end list_employees