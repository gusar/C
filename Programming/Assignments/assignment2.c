/*
Andrejs Lahs
C13766231
Assignment2

-----
LOTTO
-----

Compiles with GCC
Used POSIX function:
system("clear")

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 6
#define RANGE 43
#define RUN 1
#define READY 2
#define STOP 0

/*Prototypes*/
void menu(int*);
void menu_run(int*);
void pick_numbers(int[], int[]);
void show_numbers(int[]);
void sort(int[]);
void check_winning(int[]);
void display_frequency(int[]);
void pause();


/*******************************
Loop menu() until state 
becomes STOP, pass state address
*******************************/
main()
{
	int state = RUN;
	while(state != STOP)
	{
		menu(&state);
	}
}//end main



/*************************************
Display menu GUI
Args: pointer to int state from main()
Returns: void
runs menu_run(), passes state pointer
*************************************/
void menu(int* state_p)
{
	system("clear");
	printf("\n\t\t\t LOTTO\n"
			 "\t---------------------------------------\n"
			 "\t1. Pick Lotto numbers\n"
			 "\t2. Show the entered numbers\n"
			 "\t3. Sort numbers\n"
			 "\t4. Check winning numbers\n"
			 "\t5. Display frequency of entered numbers\n"
			 "\t6. Exit\n"
			 "\t---------------------------------------\n"
		   "\n\t : ");

	menu_run(state_p); //pass state
}//end menu



/***************************************
Args: pointer to int state from menu()
Returns: void
Get menu input, check it for errors, run
respective function. State must be READY
before user can choose options 2-4
***************************************/
void menu_run(int *state_p)
{
	char option[31] = "0";
	scanf("%30s", option);
	
	/*check if lenth is correct*/
	if(strlen(option) > 1)
		*option = '0';
	//end

	/*error if option 1 has not been chosen yet*/
	if(*state_p != READY && *option != '1' && *option != '6')
	{
		printf("\n\tPlease choose option 1 first");
		*option = '0';
	}//end
	
	static int picks[SIZE] = {0};
	static int frequency_counter[RANGE] = {0};

	/*Available menu options*/
	switch(*option)
	{ 
		case '1': 
			pick_numbers(picks, frequency_counter);
			printf("\n\tNumbers have been saved!\n");
			*state_p = READY;
			sleep(2); //sleep 2 seconds
			break;
		//end

		case '2': 
			printf("\n\tThe numbers you have picked are: ");
			show_numbers(picks);
			pause();
			break;
		//end

		case '3':
			sort(picks);
			printf("\n\tDone: Numbers are sorted now");
			pause();
			break;
		//end

		case '4':
			check_winning(picks);
			pause();
			break;
		//end

		case '5':
			display_frequency(frequency_counter);
			pause();
			break;
		//end

		case '6':
			printf("\n\tThanks for playing!\n\n");
			sleep(2);
			system("clear");
			*state_p = STOP; //state ends program
			break;
		//end

		default:
			printf("\n\tInvalid entry. Please pick again: ");
			menu_run(state_p);
	}//end switch
}//end menu_run



/************************************************
Menu Option '1'
Args: pointers to picks[] and frequency_counter[]
Returns: void
Request string numbers, convert to int, check
for errors, increment counter[] elements
************************************************/
void pick_numbers(int int_picks[], int counter[])
{
	register int i, j;
	char string_pick[31] = "0";

	printf("\n\tEnter six non-repeating numbers from 1-42\n\n");

	/*fill up int_picks[]*/
	for (i = 0; i < SIZE; i++)
	{
		do 
		{
			printf("\tNumber %d : ", i+1);
			scanf("%30s", string_pick);

			*(int_picks+i) = atoi(string_pick);

			/*check if number has been picked before*/
			for(j = 0; j < i; j++)
			{
				if(*(int_picks+i) == *(int_picks+j))
					*(int_picks+i) = 0;
			}//end

			/*check if the number is within allowed range*/	
			if(*(int_picks+i) < 1 || *(int_picks+i) > 42) 
				printf("\tInvalid number, pick again\n");

		} while(*(int_picks+i) < 1 || *(int_picks+i) > 42);
		//end do

		/*picked number increments the respective element
		of the frequency_counter[] through the pointer*/
		*(counter + *(int_picks + i)) += 1;
	}//end for
}//end user_input



/*************************************
Option '2'
Display entered numbers using a loop
Args: pointer to an int array
Returns: void
*************************************/
void show_numbers(int A[])
{
	register int i;
	for(i = 0; i < SIZE; i++)
	{
		printf("%d ", *(A+i));
		if(i < SIZE-1) printf("| ");
	}//end for
}//end show_numbers



/**************************************
Menu Option '3'
Sort picks[] with bubble sort algorithm
Args: pointer to picks[] in menu_run()
Returns: void
**************************************/
void sort(int A[])
{
	register int i, j;
	int swapped, temp;

	for(i = 0; i < SIZE-1; i++)
	{
		swapped = 0;
		for(j = 0; j < SIZE-1; j++)
		{
			if(*(A+j) > *(A+j+1))
			{
				temp = *(A+j);
				*(A+j) = *(A+j+1);
				*(A+j+1) = temp;
				swapped = 1;
			}//end if
		}//end inner for
		if(swapped = 0) break;
	}//end outer for
}//end main



/*************************************
Menu Option '4'
Args: pointer to picks[] in menu_run()
Returns: void
Compare picks[] against win_numbers[],
show prize
*************************************/
void check_winning(int user_numbers[])
{
	register int i, j;
	int win_numbers[SIZE] = {1, 3, 5, 7, 9, 11};
	int bonus = 42;
	int matches = 0;

	/*check for 6 winning numbers*/
	for(i = 0; i < SIZE; i++)
	{
		for(j = 0; j < SIZE; j++)
		{
			if(*(user_numbers+i) == *(win_numbers+j))
				matches++;
		}//end
	}//end for

	/*check for bonus number*/
	for(i = 0; i < SIZE; i++)
	{
		if(*(user_numbers+i) == bonus)
			matches += 10;
	}//end for

	/*Print win_numbers[] and bonus*/
	printf("\n\tWinner numbers are: ");
	show_numbers(win_numbers);
	printf("\n\tBonus number: %d\n", bonus);

	/*Display relevant prize*/
	switch(matches)
	{
		case  6: 
			printf("\n\t6 correct: JACKPOT!!!");
			break;
		//end
		case 15:
			printf("\n\t5 + bonus: New Car!!!");
			break;
		//end
		case  5:
			printf("\n\t5 correct: Holiday!");
			break;
		//end
		case 14:
			printf("\n\t4 + bonus: Weekend Away!");
			break;
		//end
		case  4:
			printf("\n\t4 correct: Night Out");
			break;
		//end
		case 13:
			printf("\n\t3 + bonus: Cinema Ticket");
			break;
		//end
		default: 
			printf("\n\tMaybe more luck next time"); 
	}//end switch
}//end check_winning



/*************************************************
Menu Option '5'
Args: pointer to frequency_counter[] in menu_run()
Returns: void
Display frequency of all numbers entered
*************************************************/
void display_frequency(int counter[])
{
	int i;

	for(i = 1; i < RANGE; i++)
	{
		if(*(counter+i) > 0)
		{
			printf("\n\t%d was selected %d times", i, *(counter+i));
		}
	}//end for
}//end display_frequency



/******************************
Pause until user presses return
Args: void
Returns: void 
******************************/
void pause()
{
	printf("\n\n\tPress return to continue");
	getchar();
	getchar();
}//end pause