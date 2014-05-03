/*
Programming with Persistent Data
DT228/1
Assignment

Andrejs Lahs
C13766231

Program for managing employee records in a binary file.
User can see how many employees there are in total/active/deleted.
Menu allows user to add new records, delete records 
(by marking the record with a star), search record by name,
surname, department, or duration. User can also choose to
compact all of the records; this means that all of the records
marked for deletion will be removed from the file, active records
will be sorted by surname, and internal/external fragmentation will
be removed.

Compiles with GCC
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>


struct header_rec
{
	int total;
	int active;
	int deleted;
	int cur_number;
} header;

struct record
{
	char number[6];
	char firstName[16];
	char lastName[16];
	char address[26];
	char department[10];
	char duration[3];
} employee;


/*PROTOTYPES*/
char menu(FILE*);
void add_employee(FILE*);
void delete_employee(FILE*);
void read_header(FILE*);
void write_header(FILE*);
void list_employees(FILE*);
void compact_records(FILE*);
void quick_sort(struct record[], int, int);
int partition(struct record[], int, int);
int fgets_(char*, int, FILE*);
void pause();



/*
 * MAIN
 * Opens/Creates database.dat
 * Runs menu 
 */
int main()
{

	FILE *pFile;

	pFile = fopen("database.dat", "r");
	printf("\n------------------------\n");

	/* If the file doesn't exist, create the file */
	if(!pFile)
	{
	
		printf("No file found!\n");

		pFile = fopen("database.dat", "w");
		
		if(!pFile)
		{
			printf("File cannot be created.\n");
			return 0;	//terminate
		}

		/* Initialize file header */
		header.total = 0;
		header.active = 0;
		header.deleted = 0;
		header.cur_number = 10001;
		write_header(pFile);
		fclose(pFile);

		printf("File Created\n");
	}//end if
	else printf("File Successfully Opened\n");


	/* Load header into memory and print */
	pFile = fopen("database.dat", "r");
	read_header(pFile);
	fclose(pFile);


	/* Run menu */
	char menu_option;
	do
	{
		menu_option = menu(pFile);
	}while(menu_option != '5');

	return 0;
}//end main



/*
 * Function shows menu, takes input, checks it
 * for errors and launches respective function.
 * Parameters: pointer to file link,
 * int variable for ending program.
 * Returns: void
 */
char menu(FILE *pf)
{
	char option[30] = "0";
	printf( "------------------\n"
			"       MENU \n"
			"------------------\n"
			"1: Add Employee\n"
			"2: Delete Employee\n"
			"3: List Employees\n"
			"4: Compact Records\n"
			"5: Exit\n\n"
			": " );
	scanf("%s", option);


	/* Check for user error */
	if(strlen(option) > 1 || isalpha(*option)) 
	{	
		printf("\nInvalid option. Number must be 1-5.");
		pause();
		return 0;
	}

	//Uses user input to run respective menu entry
	switch(*option)
	{
		case '1':
			add_employee(pf);
			break;

		case '2':
			delete_employee(pf);
			pause();
			break;

		case '3':
			list_employees(pf);
			pause();
			break;

		case '4':
			compact_records(pf);
			pause();
			break;

		case '5':
			printf("\n\nPROGRAM ENDED");
			pause();
			break;

		default:
			printf("\nInvalid menu entry");
			pause();
			break;
	}//end switch

	return *option;
}//end menu



/*
 * Function adds an employee struct to
 * database.dat file, increments header
 * Parameters: pointer to file link
 * Return: void
 */
void add_employee(FILE *pf)
{

	pf = fopen("database.dat", "a+");

	// Set new employee number
	snprintf(employee.number, sizeof(char)*6, "%d", header.cur_number);
	printf("\n-------------\nNumber: %s\n-------------\n", employee.number);

	// Get employee info
	getchar();
	printf("Enter Name: ");
	fgets_(employee.firstName, sizeof(employee.firstName), stdin);

	printf("Enter Surname: ");
	fgets_(employee.lastName, sizeof(employee.lastName), stdin);

	printf("Enter Address: ");
	fgets_(employee.address, sizeof(employee.address), stdin);

	printf("Enter Department: ");
	fgets_(employee.department, sizeof(employee.department), stdin);

	printf("Enter Duration: ");
	fgets_(employee.duration, sizeof(employee.duration), stdin);

	if(fwrite(&employee, sizeof(struct record), 1, pf) == 0) 
		printf("\nERROR ADDING EMPLOYEE");
	else
		printf("\nEmployee added");

	fclose(pf);

	/* Increment and write header numbers */
	pf = fopen("database.dat", "r+");
	header.active++;
	header.total++;
	header.cur_number++;
	write_header(pf);
	fclose(pf);

	printf("\n\nPress return\n");
	getchar();
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
	pf = fopen("database.dat", "r+");

	fseek(pf, sizeof(struct header_rec), SEEK_CUR);

	char key[6] = {0};
	printf("\nEmployee Number\n: ");
	scanf("%s", key);


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
 * Function reads header of
 * the database.dat file.
 * Parameters: pointer to file link
 * Return: void
 */
void read_header(FILE *pf)
{
	if(fread(&header, sizeof(struct header_rec), 1, pf) != 0)
		printf( "\nTotal: %d\n"
				"Active: %d\n"
				"Deleted: %d\n\n", 
				header.total, header.active, header.deleted);
	else
	{
		printf("\nERROR: NO HEADER FOUND");
		pause();
	}
}//end read_header



/*
 * Function checks for errors while writing
 * header struct to file.
 * Parameters: pointer to file link
 * Returns: void
 */
void write_header(FILE *pf)
{
	if(fwrite(&header, sizeof(struct header_rec), 1, pf) == 0)
	{
		printf("\nERROR WRITING HEADER");
		pause();
	}
}//end write_header



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
	pf = fopen("database.dat", "r");

	/* Request and set a search key (if any) */
	char search_type;
	char *search_var;
	char search_key[16];
	printf( "List all records (1) OR\nSearch by: Name (2)/ "
			"Surname (3)/ Department (4)/ Duration (5): ");
	scanf("%1s", &search_type);

	switch(search_type)
	{
		case '2':
			search_var = employee.firstName;
			printf("\nEnter name: ");
			scanf("%s", search_key);
			break;

		case '3':
			search_var = employee.lastName;
			printf("\nEnter surname: ");
			scanf("%s", search_key);
			break;

		case '4':
			search_var = employee.department;
			printf("\nEnter department: ");
			scanf("%s", search_key);
			break;

		case '5':
			search_var = employee.duration;
			printf("\nEnter duration: ");
			scanf("%s", search_key);
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
			if(search_type == '1' || (search_type != '1' && strcmp(search_key, search_var) == 0))
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



/*
 * Function loads all the active records 
 * in the database.dat into a struct array,
 * launches soritng by surname, then overwrites
 * the existing file with new data.
 * Parameters: pointer to file link
 * Returns: void
 */
void compact_records(FILE *pf)
{
	int i, j = 0;
	struct record all_employees[header.active];

	pf = fopen("database.dat", "r");
	fseek(pf, sizeof(struct header_rec), SEEK_SET);

	/* Load all entries into an array */
	while(fread(&employee, sizeof(struct record), 1, pf) != 0)
	{
		if(*employee.number != '*')
		{
			all_employees[j] = employee;
			j++;
		}//end if
	}//end for
	fclose(pf);


	/* Sorting algorithm sorcery*/
	quick_sort(all_employees, 0, header.active-1);
	

	/* Overwrite database.dat with all_employees[]*/
	remove("database.dat");
	pf = fopen("database.dat", "w");

	header.total = j;
	header.deleted = 0;
	write_header(pf);

	for(i = 0; i < header.total; i++)
	{
		employee = all_employees[i];
		if(fwrite(&employee, sizeof(struct record), 1, pf) == 0)
		{
			printf("ERROR WRITING RECORD\n");
		}
	}//end for
	fclose(pf);

	printf("\nCompacting Finished");
}//end compact_records



/*
 * QUICKSORT ALGORITHM (improved version)
 * Part 1
 * Function uses recursion to stack and 
 * sort employees by surname.
 * Parameters: lowest element number, highest
 * element number, array of structures.
 * Returns: void
 */
void quick_sort(struct record A[], int low, int high)
{
	int q;
	if(high > low)
	{
		q = partition(A, low, high);
		quick_sort(A, low, q-1);
		quick_sort(A, q+1, high);
	}//end if
}//end quick_sort



/*
 * QUICKSORT
 * Part 2
 * Function chooses a pivot and swaps elements.
 * Paramenters: lowest element, highest element,
 * array of structures.
 * Returns: integer for high/low in quick_sort function.
 */
int partition(struct record A[], int low, int high)
{
	int j, i, P;
	struct record temp;

	P = low;
	i = low + 1;
	j = high;
	
	/* Find new pivot location, if a number is smaller 
	than pivot, place it on the left of the pivot. */
	do
	{
		while (strcmp(A[i].lastName, A[P].lastName) < 0)
		{
			i++;
			if (j >= high) break;
		} 
		
		while (strcmp(A[j].lastName, A[P].lastName) > 0)
		{
			j--;
			if (j <= low) break;
		}
	
		if (i < j)
		{ 
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	} while (i < j);//end while


	/* Place pivot element into the new position */
	if (j != low)
	{
		temp = A[P];
		A[P] = A[j];
		A[j] = temp;
	}

	return j;
}//end partition



/*
 * Function trims \n at the end of string
 * captured by fgets()
 * Parameters: pointer to string, 
 * size of string, name of input stream.
 * Returns: 1 when finished.
 */
int fgets_(char *output, int size, FILE *stream)
{
	fgets(output, size, stream);
	char *c = strchr(output, '\n');
	*c = '\0';
	return 1;
}//end fgets_



/*
 * Function pauses the program until
 * the user presses return key.
 * Parameters: none
 * Returns: void
 */
void pause()
{
 	printf("\n\nPress return to continue\n");
	getchar();
	getchar();
}//end pause