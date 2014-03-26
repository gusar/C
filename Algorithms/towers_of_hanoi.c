/*
Towers of Hanoi
*/

#include <stdio.h>

void moveTowers(int, char, char, char);
int counter = 1;
main()
{
	int disks;
	printf("Enter the number of disks: ");
	scanf("%d", &disks);
	moveTowers(disks-1, 'A', 'C', 'B');
}//end main

void moveTowers(int disk, char source, char dest, char spare)
{
	if(disk == 0)
	{
		printf("%d: Disk 0 from %c to %c\n", counter, source, dest);
		counter++;
	}//end if
	else
	{
		moveTowers(disk-1, source, spare, dest);
		printf("%d: Disk %d from %c to %c\n", counter, disk, source, dest);
		counter++;
		moveTowers(disk-1, spare, dest, source);
	}//end else
}//end moveTowers