/*

A big part of radio communication is the NATO Phonetic Alphabet, which encodes letters as words to make them easier to understand over comms. Your job, if you wish to accept it, is to print them one by one.

You must print this exact string to stdout:

A: Alfa
B: Bravo
C: Charlie
D: Delta
E: Echo
F: Foxtrot
G: Golf
H: Hotel
I: India
J: Juliet
K: Kilo
L: Lima
M: Mike
N: November
O: Oscar
P: Papa
Q: Quebec
R: Romeo
S: Sierra
T: Tango
U: Uniform
V: Victor
W: Whiskey
X: Xray
Y: Yankee
Z: Zulu

Rules:

    Your program takes no input
    Standard loopholes are Disallowed.
    If there are any builtins in your language that turn letters to their NATO equivelants, you may not use them (I'm looking at you Mathematica).
    You may have trailing spaces and one trailing newline.

*/

#include <cstdio>

const char *radiosign = R"(
A: Alfa
B: Bravo
C: Charlie
D: Delta
E: Echo
F: Foxtrot
G: Golf
H: Hotel
I: India
J: Juliet
K: Kilo
L: Lima
M: Mike
N: November
O: Oscar
P: Papa
Q: Quebec
R: Romeo
S: Sierra
T: Tango
U: Uniform
V: Victor
W: Whiskey
X: Xray
Y: Yankee
Z: Zulu
)";

int main()
{
	printf("%s\n", radiosign);
	return 0;
}
