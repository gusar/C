/*
08.10.2014
Take an input of a string with name and surname,
then reverse the positions of the two words.
*/

#include <stdio.h>
#include <string.h>

main(){
	int i,j,k;
	char s1[30];
	char s2[30];

	printf("Enter full name: ");
	gets(s1);

	/*  */
	for(i = 0; s1[i] != ' '; i++){
		k = i;
	}

	/* Reat from s1[k+1] to end intp s2[0..k] */
	j = 0;

	for(i = k+1; s1[i]; i++){
		s2[j] = s1[i];
		j++;
	}

	/* add a space */
	s2[j] = ' ';

	/* move to next s2 index */
	j++;

	/* add in from s1[0] to s1[k-1] */
	for(i = 0; i < k; i++){
		s2[j] = s1[i];
		j++;
	}

	/* add null character */
	s2[j] = '\0';

	puts(s1);
	puts(s2);
}