/*
      Andrejs Lahs
       C13766231
 Math Quiz - Assignment 1

    Compiles with GCC
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define NO_OF_QUESTIONS 5

main()
{
	void pause_function(void);				//see below main()

	srand (time(NULL));						//initialize random seed for rand()

	int i;
	char menu_option;
	int random = 0;
	int used_random[NO_OF_QUESTIONS]; 
	int requested_number = NO_OF_QUESTIONS;	//5 questions asked by default
	int correct_counter = 0;		
	int incorrect_counter = 0;
	int results_checked = TRUE;				//while true, user can select option 2
	char user_answer[5] = {};				//5 immitates digit limitation of an int

	/*An array of 5 questions as strings.
	Strings seem to me as an efficient way to store 
	(relatively)long questions as single entities. 
	Arrays provide a fast access to any question.
	Also shorter code - easier to read (in this case).*/
	char *question[NO_OF_QUESTIONS] =  {"(6 + 9) % 3 = ",
						 				"8 * 3 + 6^2 = ",
						 				"2 + 2 = ",
						 				"42 / 7 * 9 = ",
						 				"999 / 3 / 3 = "
						 			   };

	/*An array of 5 correct answers as strings.
	  The array allows for quick reference, and
	  storing answers as strings also serves as 
	  user error correction. Strings are also 
	  easily compared with strcmp().*/
	char *correct_answer[NO_OF_QUESTIONS] = {"0", 
											 "60",
											 "4",
											 "54",
											 "111"
											}; 

	/*Main body of the game. Including Menu and all options*/
	do
	{	

		system ( "clear" );	//clears screen. function compiles with gcc.
		printf("\n   ===========================================================================\n");
		printf(  "                                --MAIN MENU--"								   );
		printf("\n   1. Enter the number of questions to be asked (Default = 5)"				   );
		printf("\n   2. Start Quiz"																   );
		printf("\n   3. Display number of questions that were answered correctly and incorrectly"  );
		printf("\n   4. Exit"																	   );
		printf("\n   ===========================================================================\n");
		printf("\n   Enter a menu entry number: ");
		scanf("%1s", &menu_option);

		/*Processing menu input*/
		switch(menu_option)
		{

			/*User enters a number of questions to be asked*/
			case '1':
			{
				system ( "clear" );
				printf("\n   Please enter how many questions you want to answer: ");
				scanf("%d", &requested_number);
				break;
			}//END CASE 1

			/*Quiz asks pulls random questions, checks answers, and counts them*/
			case '2':
			{
				system ( "clear" );
				/*Quits to menu if user has already played, and not selected option 3 afterwards*/
				if(results_checked == FALSE)
				{
					printf("\n   Access denied, choose menu option 3 to unlock the quiz.\n");
					pause_function();
					break;
				}//end if

				/*Loop initialises array of to impossible values*/
				for(i = 0; i < NO_OF_QUESTIONS; i++)
				{
					used_random[i] = 5;
				}//end for

				/*Loop counts questions asked*/
				for(i = 0; i < requested_number; i++)
				{		
					/*Random number picker. Also makes sure questions dont repeat*/
					do
					{
						random = rand() % NO_OF_QUESTIONS;
					} while(random == used_random[0] || 
					   	    random == used_random[1] || 
						    random == used_random[2] || 
						    random == used_random[3]);
					
					used_random[i] = random;
					/*End Random number picker*/

					/*Question is asked here*/
					printf("\n   Question %d:", i+1);
					printf("\n   %s", question[random]);
					scanf("%s", user_answer);

					/*Checking if answer is correct*/
					if(strcmp(user_answer, correct_answer[random]) == 0)
					{
						printf("   Correct! The answer is: %s\n", correct_answer[random]);
						correct_counter++;
					}//END IF
					else
					{
						printf("   Wrong, the answer is: %s\n", correct_answer[random]);
						incorrect_counter++;
					}//END ELSE
				}//END FOR

				results_checked = FALSE; //user can no longer select option 2

				pause_function();
				break;
			}//END CASE 2

			case '3':
			{
				/*Printing how many answers were correct and incorrect*/
				system ( "clear" );
				printf("\n   Questions answered correctly:   %d", correct_counter);
				printf("\n   Questions answered incorrectly: %d\n", incorrect_counter);

				results_checked = TRUE; //allows to select option 2 again

				pause_function();
				break;
			}//END CASE 3

			case '4':
			{
				/*Ends switch and game*/
				system ( "clear" );
				printf("\n   Thanks for playing! You are an amazing person!\n");
				sleep(5);
				system ( "clear" );
				break;
			}//END CASE 4

			default:
			{
				/*Invalid input correction*/
				printf("\n\n   Invalid option, enter a number 1-4: ");				
				printf("\n");
				sleep(3);
			}//END DEFAULT
		}//END SWITCH
	}//END DO
	while(menu_option != 4); //Ends the program if option 4 was chosen
}//END MAIN

/*Function that pauses the program until user presses enter.
  Adding all the code below multiple times makes the code
  confusing. Istead, it is much more efficient and compact 
  to call the function when needed.*/
void pause_function()
{
	int old_data;
	printf("\n   Press Enter");
	getchar();
	do 	//makes sure that memory buffer is clear
	{
		old_data = getchar();
	}while(old_data != '\n');
}//END FUNCTION