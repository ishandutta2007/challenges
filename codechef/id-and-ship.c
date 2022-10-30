/*

Write a program that takes in a letterclass ID of a ship and display the equivalent string class description of the given ID. Use the table below.

Class ID 	Ship Class
B or b 	BattleShip	
C or c 	Cruiser	
D or d 	Destroyer	
F or f 	Frigate

*/
#include <stdio.h>
#include <ctype.h>

const char *
ship(int id)
{
	switch (tolower(id)) {
	case 'b':
		return "BattleShip";
	case 'c':
		return "Cruiser";
	case 'd':
		return "Destroyer";
	case 'f':
		return "Frigate";
	}
	return "Unknown";
}

int
main(void)
{
	printf("%s\n", ship('B'));
	printf("%s\n", ship('c'));
	printf("%s\n", ship('D'));
	printf("%s\n", ship('F'));
	return 0;
}
