/*

Compacting of all active records in the database file:
Load all records into memory (max records < 12.7 MB);
sort the records by surname using a modified quicksort;
attempt to write sorted records and the new header into
a temp file; if successful, replace the old file with
the new one.

*/


#include <stdio.h>
#include <string.h>
#include <main.h>


extern struct header_rec header;
extern struct record employee;


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

	pf = fopen(DATABASE, "r");
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
	int error = 0;
	pf = fopen(TEMP_DATABASE, "w");

	header.total = j;
	header.deleted = 0;
	error = write_header(pf);

	for(i = 0; i < header.total; i++)
	{
		employee = all_employees[i];
		if(fwrite(&employee, sizeof(struct record), 1, pf) == 0)
		{
			printf("ERROR WRITING RECORD\n");
			error = 1;
		}
	}//end for
	fclose(pf);

	if(error == 0)
	{
		if(remove(DATABASE) + rename(TEMP_DATABASE, DATABASE) == 0 )
		{
			printf( "\nCompacting Finished"
					"\nRecords are now sorted by surname.");
		}
		else
			printf("\nERROR OVERWRITING OLD DATABASE");
	}
	else
		printf( "\nERROR WHILE WRITING NEW FILE"
				"\nCompacting has been aborted,\ndatabase remains unchangned." );
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