/*

Whyte Notation is a classification method mainly for steam locomotive, that classifies by wheel arrangement.
On a steam locomotive ( we're only focusing on non articulated locomotives here ), the wheels are generally disposed like this : you have a specific number of leading wheels, then a specific number of driver wheels, and then a specific number of trailing wheels.
On the top of that, each different wheel arrangement has its own name.

For example, look at this machine :

SNCF Class 141R

It has 2 leading wheels ( 1 on each sides ), 8 driving wheels ( 4 on each sides ) and 2 trailing wheels ( 1 on each sides )

Its Whyte Notation would be 2-8-2, and its name associated with it is "Mikado".
Based on the Whyte Notation, we can create a visual arrangement that can be represented by a string, with the o character as a small wheel ( leading wheel if in front of the driver wheels, else trailing ), and a caps O for the driver wheels

Taking the previous locomotive as an example, its visual arrangement would be this : oOOOOo, with one small o on the front ( the leading wheels ), 4 caps O in the middle ( the driving wheels ), and one small o at the end ( the trailing wheels )

Here is the conversion table that we'll use to base the code on ( the table of entries that will have to be supported by your code ) :

    Input    |   Output
-------------+----------
oO           | Planet
oOo          | Jenny Lind
oOO          | Porter
oOOo         | Columbian
ooO          | Jervis
ooOoo        | Huntington
oooO         | Cramton
OO           | Four-coupled
OOo          | Olomana
OOoo         | Forney
ooOO         | American
ooOOo        | Atlantic
ooOOoo       | Jubilee
oOOO         | Mogul
oOOOo        | Prairie
oOOOoo       | Adriatic
ooOOO        | Ten-wheeler
ooOOOo       | Pacific
ooOOOoo      | Hudson
OOOO         | Eight-coupled
oOOOO        | Consolidation
oOOOOo       | Mikado
oOOOOoo      | Berkshire
ooOOOO       | Mastodon
ooOOOOo      | Mountain
ooOOOOoo     | Northern
oooOOOOooo   | Turbine
OOOOO        | Ten-coupled
OOOOOo       | Union
oOOOOO       | Decapod
ooOOOOO      | El Gobernador
ooOOOOOo     | Overland
oOOOOOo      | Santa Fe
oOOOOOOoo    | Texas
ooOOOOOOo    | Union Pacific
ooOOOOOOOoo  | AA20
Your task
Your task is to write 2 programs of functions.

First program / function : from arrangement to name
The first function / program will be taking as input a string that exists in the table given previously, and will output the associated name ( for example, oOOOOo will return "Mikado" ).

For the input, the only inputs you have to support are the one in the table previously given. Anything else that isn't in the table leads to undefined behavior.

For the output, the string has to be the exact name, with the exception of case, which can be whatever you want. Trailing spaces are fine too.

Examples of acceptable output : Mikado, mikado, MIKADO   , mIkAdO, Ten-wheeler

Examples of not acceptable output : Mi Ka Do,    Mikado, Tenwheeler, Ten_wheeler, Ten wheeler

Second program / function : the opposite
This program of function will do the opposite of the first program, meaning that when given a name, it will print / return / output the string representing the wheel arrangement of the locomotive.

As input, it will take whatever name existing in the "Output" part of the previously given table. Shall the name not exist, it leads to undefined behavior

As output, it will give the exact string that represents the wheel arrangement, no flexibility allowed. So for example, Mikado as input must return oOOOOo.

Global constraints
Both of the programs have to be able to take as input the other program's output, and func2(func1(wheel_arrangement_string)) has to be equal to wheel_arrangement_string.
Same goes the other way, with func1(funct2(wheel_arrangement_name)) that has to be equal to wheel_arrangement_name.

Aside from that, standard I/O rules apply, and default loopholes are forbidden

Additionnal Rules
Programs and functions can call each others, and share calls to any additional functions or use any additional data you want, as long as they are included in the score

Scoring rules
Your score will simply be the sum of each program / function code sizes, as well as the size of any additional data / function required to make the code work. Each functions need to support all the entries listed in the table previously given.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
conv(const char *s, int n)
{
	static const char whyte[][2][80] = {
	    {"oO", "Planet"},
	    {"oOo", "Jenny Lind"},
	    {"oOO", "Porter"},
	    {"oOOo", "Columbian"},
	    {"ooO", "Jervis"},
	    {"ooOoo", "Huntington"},
	    {"oooO", "Cramton"},
	    {"OO", "Four-coupled"},
	    {"OOo", "Olomana"},
	    {"OOoo", "Forney"},
	    {"ooOO", "American"},
	    {"ooOOo", "Atlantic"},
	    {"ooOOoo", "Jubilee"},
	    {"oOOO", "Mogul"},
	    {"oOOOo", "Prairie"},
	    {"oOOOoo", "Adriatic"},
	    {"ooOOO", "Ten-wheeler"},
	    {"ooOOOo", "Pacific"},
	    {"ooOOOoo", "Hudson"},
	    {"OOOO", "Eight-coupled"},
	    {"oOOOO", "Consolidation"},
	    {"oOOOOo", "Mikado"},
	    {"oOOOOoo", "Berkshire"},
	    {"ooOOOO", "Mastodon"},
	    {"ooOOOOo", "Mountain"},
	    {"ooOOOOoo", "Northern"},
	    {"oooOOOOooo", "Turbine"},
	    {"OOOOO", "Ten-coupled"},
	    {"OOOOOo", "Union"},
	    {"oOOOOO", "Decapod"},
	    {"ooOOOOO", "El Gobernador"},
	    {"ooOOOOOo", "Overland"},
	    {"oOOOOOo", "Santa Fe"},
	    {"oOOOOOOoo", "Texas"},
	    {"ooOOOOOOo", "Union Pacific"},
	    {"ooOOOOOOOoo", "AA20"},
	};

	size_t i;

	for (i = 0; i < nelem(whyte); i++) {
		if (!strcmp(s, whyte[i][n]))
			return whyte[i][1 - n];
	}
	return s;
}

const char *
wheel2name(const char *s)
{
	return conv(s, 0);
}

const char *
name2wheel(const char *s)
{
	return conv(s, 1);
}

void
test(const char *s, const char *t)
{
	assert(!strcmp(wheel2name(s), t));
	assert(!strcmp(name2wheel(t), s));
}

int
main(void)
{
	test("oOOOOo", "Mikado");

	return 0;
}
