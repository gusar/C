/*
Algorithms
DT228/1
Assignment

Andrejs Lahs
C13766231

Limited Implementation of Pseudocode:
Quicksort algorithm
Binary Search algorithm

Program stores three struct variable arrays,
combines them into one, sorts them alphabetically
by surname and searches them by surname.

Compiles with GCC
*/

#include <stdio.h>
#include <string.h>

#define SIZE 11



/* Struct template for student info */
struct record
{
	char number[11];
	char course[6];
	char year[2];
	char name[21];
	char surname[21];
	char address[31];
} TUD[SIZE], DIT[5], ITT[3], ITB[3];


/* Prototypes */
void merge();
void quick_sort(int low, int high);
int partition(int low, int high);
void search_menu();
void binary_search(char*, int, int);



/*
 * MAIN
 * Request and store student info,
 * call merge function, sort function
 * and search menu function.
 */
int main()
{
	/* Request and store student info */
	char dit[4] = "DIT";
	char itt[4] = "ITT";
	char itb[4] = "ITB";
	char *it;
	struct record *it_rec;
	int i, j;
	for (i = 0, j = 1; i < SIZE; i++, j++)
	{
		if(i < 5)
		{
			it = dit;
			it_rec = &DIT[i];
		}
		else if(i >= 5 && i < 8) 
		{
			it = itt;
			it_rec = &ITT[i-5];
		}
		else if(i >= 8)
		{
			it = itb;
			it_rec = &ITB[i-8];
		}

		printf("\n-------------");
		printf("\n%s Student %d\n", it, j);
		printf("Enter name: ");
		scanf("%20s", it_rec -> name);
		printf("Enter surname: ");
		scanf("%20s", it_rec -> surname);
		printf("Enter student number: ");
		scanf("%10s", it_rec -> number);
		printf("Enter course: ");
		scanf("%5s", it_rec -> course);
		printf("Enter year: ");
		scanf("%2s", it_rec -> year);
		printf("Enter address: ");
		scanf("%30s", it_rec -> address);
	}

	/* Copy 3 arrays into one */
	merge();


	/* Sort records by surname */
	quick_sort(0, SIZE-1);

	for(i = 0; i < SIZE; i++)
	{
		printf("%d: %s\n", i+1, TUD[i].surname);
	}
	
	/* Call search menu */
	char again;
	do
	{
		search_menu();
		printf("\nSearch again? (y/n): ");
		scanf(" %c", &again);
	}while(again == 'y');

}//end main



/*
 * MERGING
 * Function copies 3 struct arrays
 * into a single struct array.
 */
void merge()
{
	int i;
	for(i = 0; i < 5; i++)
	{
		TUD[i] = DIT[i];
	}
	for(i; i < (5+3); i++)
	{
		TUD[i] = ITT[i-5];
	}
	for(i; i <= (SIZE); i++)
	{
		TUD[i] = ITB[i-8];
	}
}//end merge



/*
 * Quicksort
 * Part 1
 * Function uses recursion to sort
 * employees by surname.
 * Parameters: lowest element number,
 * highest element number.
 * Returns: void
 */
void quick_sort(int low, int high)
{
	int q;
	if(high > low)
	{
		q = partition(low, high);
		quick_sort(low, q-1);
		quick_sort(q+1, high);
	}//end if
}//end quick_sort



/*
 * Quicksort
 * Part 2
 * Function chooses a pivot and swaps elements.
 * Paramenters: lowest element, highest element.
 * Returns: integer for high/low in quick_sort function.
 */
int partition(int low, int high)
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
		while (strcmp(TUD[i].surname, TUD[P].surname) < 0)
		{
			i++;
			if (j >= high) break;
		} 
		
		while (strcmp(TUD[j].surname, TUD[P].surname) > 0)
		{
			j--;
			if (j <= low) break;
		}
	
		if (i < j)
		{ 
			temp = TUD[i];
			TUD[i] = TUD[j];
			TUD[j] = temp;
		}
	} while (i < j);//end while


	/* Place pivot element into the new position */
	if (j != low)
	{
		temp = TUD[P];
		TUD[P] = TUD[j];
		TUD[j] = temp;
	}

	return j;
}//end partition



/*
 * SEARCH MENU
 */
void search_menu()
{
	int result;
	char key[21];
    printf("Enter surname to search: ");
    scanf("%20s", key);
    binary_search(key, 0, SIZE);
}//end search_menu



/*
 * BINARY SEARCH
 */
void binary_search(char *key, int low, int high)
{
	int mid;
	if(high < low) printf("No such student found\n");;

	mid = (low + high) / 2;

	if(strcmp(TUD[mid].surname, key) > 0)
	{
		binary_search(key, low, mid-1);
	}
	else if(strcmp(TUD[mid].surname, key) < 0)
	{
		binary_search(key, mid+1, high);
	}
	else printf("Student found:\n"
				"Name: %s\n"
				"Surname: %s\n"
				"Student number: %s\n"
				"Course: %s\n"
				"Year: %s\n"
				"Address: %s\n",
				TUD[mid].name, TUD[mid].surname, TUD[mid].number,
				TUD[mid].course, TUD[mid].year, TUD[mid].address);

}//end dinary_search