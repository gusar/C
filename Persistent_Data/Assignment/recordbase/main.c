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
#include <main.h>


extern struct header_rec header;
extern struct record employee;


/*
 * MAIN
 * Opens/Creates database.dat
 * Runs menu 
 */
int main()
{

	FILE *pFile;

	pFile = fopen(DATABASE, "r");
	printf("\n------------------------\n");

	/* If the file doesn't exist, create the file */
	if(!pFile)
	{
	
		printf("No file found!\n");

		pFile = fopen(DATABASE, "w");
		
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
	pFile = fopen(DATABASE, "r");
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
 * Function shows menu, takes input 
 * and launches respective function.
 * Parameters: pointer to file link,
 * int variable for ending program.
 * Returns: void
 */
char menu(FILE *pf)
{
	char option[OPTION_SIZE] = {'\0'};
	printf( "------------------\n"
			"       MENU \n"
			"------------------\n"
			"1: Add Employee\n"
			"2: Delete Employee\n"
			"3: List Employees\n"
			"4: Compact Records\n"
			"5: Exit\n\n"
			": " );

	get_input(option, sizeof(option), stdin);


	//Uses user input to run respective menu entry
	switch(*option)
	{
		case '1':
			add_employee(pf);
			pause();
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