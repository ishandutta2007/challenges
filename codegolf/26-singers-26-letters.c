/*

According to RollingStone, below are the 26 greatest singers of all time:

Aretha Franklin         Al Green
Ray Charles             Robert Plant
Elvis Presley           Mick Jagger
Sam Cooke               Tina Turner
John Lennon             Freddie Mercury
Marvin Gaye             Bob Marley
Bob Dylan               Smokey Robinson
Otis Redding            Johnny Cash
Stevie Wonder           Etta James
James Brown             David Bowie
Paul McCartney          Van Morrison
Little Richard          Michael Jackson
Roy Orbison             Jackie Wilson
You can get this as a list of strings here.

Task
Given a singer name, print or return a letter from A to Z which uniquely identifies this singer. (If your code returns A for Bob Dylan, then it cannot return A for any other singer.)

As opposed to other similar challenges, the mapping is up to you as long as it's collision-free.

Rules
The input is guaranteed to be one of the 26 singer names listed above with this exact spelling and without any leading or trailing whitespace.
You may output the letter in either lowercase or uppercase. But it must be consistent.
You are encouraged to provide a test suite for all 26 possible inputs.
This is code-golf, so the shortest answer in bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
singer(const char *s)
{
	static const char *tab[] = {
	    "Aretha Franklin",
	    "Ray Charles",
	    "Elvis Presley",
	    "Sam Cooke",
	    "John Lennon",
	    "Marvin Gaye",
	    "Bob Dylan",
	    "Otis Redding",
	    "Stevie Wonder",
	    "James Brown",
	    "Paul McCartney",
	    "Little Richard",
	    "Roy Orbison",
	    "Al Green",
	    "Robert Plant",
	    "Mick Jagger",
	    "Tina Turner",
	    "Freddie Mercury",
	    "Bob Marley",
	    "Smokey Robinson",
	    "Johnny Cash",
	    "Etta James",
	    "David Bowie",
	    "Van Morrison",
	    "Michael Jackson",
	    "Jackie Wilson",
	};

	size_t i;

	for (i = 0; i < nelem(tab); i++) {
		if (!strcmp(s, tab[i]))
			return 'A' + i;
	}
	return '?';
}

int
main(void)
{
	assert(singer("Aretha Franklin") == 'A');
	assert(singer("Michael Jackson") == 'Y');
	assert(singer("Jackie Wilson") == 'Z');

	return 0;
}
