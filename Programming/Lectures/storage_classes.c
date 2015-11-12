/*
===============
STORAGE CLASSES
===============

In C, there are 4 types of storage class:
--------------------
	1. Auto Variable

		-By default, all variables in C are auto unless otherwise specified.
			e.g. auto int num1;		<--->	int num1;
				 auto char my_char;	<--->	char my_char;
		-Are LOCAL, i.e. exist only inside the function.
		-When a function ends, the memory used for the auto variable is freed.
--------------------
	2. Static Variable
	
		-Are also LOCAL variables.
		-But, static variables MAINTAIN their data when the function ends, i.e. memory is not freed.
--------------------
	3. Extern Variable
	
		-Means that the variable has been declared in an external file that was included in the program.
		-Can be shared across different files.
--------------------
	4. Register Variables

		-They have their memory assigned inside the CPU and NOT in the memory (RAM).
		-Register variables are used to increase the speed of execution of a program.
			e.g. register int i;
		-Often used for index variables in loops.
--------------------
*/

/*Extern Variable Example*/
#include <stdio.h>
/*.h files only contrain isolated functions i.e. there is no main*/
#include "myfile.h"	//int num must be declared in the file
void function(void);
main()
{
	extern int num;	//the program will grab the variable from the external file.
	for(int i = 0; i < 2; i++)
	{
		function();
	}
	parintf("num is %d", num);
}//end main
void function()
{
	extern int num;	//extern variable
	num++;
}//end function