/*

Functions check for errors and do the following:
Read/print header record;
Write new header to file;
Get user input and validate it;
Clear stdin buffer;
Pause the program.

*/

#include <stdio.h>
#include <string.h>
#include <main.h>


extern struct header_rec header;
extern struct record employee;


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
 * Returns: 1 if writing failed, otherwise returns 0.
 */
int write_header(FILE *pf)
{
	if(fwrite(&header, sizeof(struct header_rec), 1, pf) == 0)
	{
		printf("\nERROR WRITING HEADER");
		pause();
		return 1;
	}
	else 
		return 0;
}//end write_header



/*
 * Function checks the length of user input to
 * check if is the required size. Trims character
 * \n at the end of string captured by fgets().
 * Parameters: pointer to string, size of string,
 * name of input stream.
 * Returns: 1 when finished.
 */
int get_input(char *output, int size, FILE *stream)
{
	char input[TEST_SIZE];
	fgets(input, sizeof(input), stream);


	/* Check input size */
	int len = strlen(input);
	if(len > size || len < 2)
	{
		if(len > size*2) clear_stdin();

		printf("Please up to %d characters\n: ", size-1);
		get_input(output, size, stream);
		return 0;
	}//end if


	/* Clean menu inputs */
	switch(size)
	{
		/* Duration input */
		case DURATION_SIZE:
			if(isalpha(*input) || isalpha(*(input+1)))
			{
				printf("Please enter a number\n: ");
				get_input(output, size, stream);
				return 0;
			}
			break;
		//end	

		/* Menu/Search type input */
		case OPTION_SIZE:
			if(strlen(input) > 2 || isalpha(*input))
			{	
				printf("\nInvalid option. Number must be 1-5.");
				clear_stdin();
				get_input(output, size, stream);
				return 0;
			}
			break;
		//end

		default: break;
	}//end switch


	/* Trim new line character */
	char *c = strchr(input, '\n');
	*c = '\0';

	strcpy(output, input);
	return 1;
}//end fgets_



/*
 * Function removes all data from
 * stdin one character at a time.
 * Parameters: none
 * Returns: void
 */
void clear_stdin()
{
	char dump;
	{
		dump = getchar();
	} while(dump != '\n');
}//end clear_stdin



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
}//end pause