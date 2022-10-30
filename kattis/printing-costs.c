/*

Your workplace is starting to become concerned with the cost of toner used for printing.
Of course, some pages are more expensive to print than others.
Your job is to write a program that helps to figure out how much toner it will take.

Each character requires a different amount of toner to print. For example, a space requires nothing but a capital Q requires 31.
The following table gives the printing cost of each of the 95 printable ASCII characters.
The codes for these characters are consecutive, starting with 32 for space and ending with 126 for tilde (~).

    0        !   9        "   6        #  24        $  29        %  22
&  24        '   3        (  12        )  12        *  17        +  13
,   7        -   7        .   4        /  10        0  22        1  19
2  22        3  23        4  21        5  27        6  26        7  16
8  23        9  26        :   8        ;  11        <  10        =  14
>  10        ?  15        @  32        A  24        B  29        C  20
D  26        E  26        F  20        G  25        H  25        I  18
J  18        K  21        L  16        M  28        N  25        O  26
P  23        Q  31        R  28        S  25        T  16        U  23
V  19        W  26        X  18        Y  14        Z  22        [  18
\  10        ]  18        ^   7        _   8        `   3        a  23
b  25        c  17        d  25        e  23        f  18        g  30
h  21        i  15        j  20        k  21        l  16        m  22
n  18        o  20        p  25        q  25        r  13        s  21
t  17        u  17        v  13        w  19        x  13        y  24
z  19        {  18        |  12        }  18        ~   9

Input

Input consists of up to 1000 lines of text, ending at end of file. Each line is at most 100 characters long.

Output

For each input line, output a line giving the total amount of toner required for printing.

*/

#include <assert.h>
#include <stdio.h>

unsigned
cost(const char *s)
{
	static unsigned char tab[256] = {
	    [' '] = 0,
	    ['!'] = 9,
	    ['"'] = 6,
	    ['#'] = 24,
	    ['$'] = 29,
	    ['%'] = 22,
	    ['&'] = 24,
	    ['\''] = 3,
	    ['('] = 12,
	    [')'] = 12,
	    ['*'] = 17,
	    ['+'] = 13,
	    [','] = 7,
	    ['-'] = 7,
	    ['.'] = 4,
	    ['/'] = 10,
	    ['0'] = 22,
	    ['1'] = 19,
	    ['2'] = 22,
	    ['3'] = 23,
	    ['4'] = 21,
	    ['5'] = 27,
	    ['6'] = 26,
	    ['7'] = 16,
	    ['8'] = 23,
	    ['9'] = 26,
	    [':'] = 8,
	    [';'] = 11,
	    ['<'] = 10,
	    ['='] = 14,
	    ['>'] = 10,
	    ['?'] = 15,
	    ['@'] = 32,
	    ['A'] = 24,
	    ['B'] = 29,
	    ['C'] = 20,
	    ['D'] = 26,
	    ['E'] = 26,
	    ['F'] = 20,
	    ['G'] = 25,
	    ['H'] = 25,
	    ['I'] = 18,
	    ['J'] = 18,
	    ['K'] = 21,
	    ['L'] = 16,
	    ['M'] = 28,
	    ['N'] = 25,
	    ['O'] = 26,
	    ['P'] = 23,
	    ['Q'] = 31,
	    ['R'] = 28,
	    ['S'] = 25,
	    ['T'] = 16,
	    ['U'] = 23,
	    ['V'] = 19,
	    ['W'] = 26,
	    ['X'] = 18,
	    ['Y'] = 14,
	    ['Z'] = 22,
	    ['['] = 18,
	    ['\\'] = 10,
	    [']'] = 18,
	    ['^'] = 7,
	    ['_'] = 8,
	    ['`'] = 3,
	    ['a'] = 23,
	    ['b'] = 25,
	    ['c'] = 17,
	    ['d'] = 25,
	    ['e'] = 23,
	    ['f'] = 18,
	    ['g'] = 30,
	    ['h'] = 21,
	    ['i'] = 15,
	    ['j'] = 20,
	    ['k'] = 21,
	    ['l'] = 16,
	    ['m'] = 22,
	    ['n'] = 18,
	    ['o'] = 20,
	    ['p'] = 25,
	    ['q'] = 25,
	    ['r'] = 13,
	    ['s'] = 21,
	    ['t'] = 17,
	    ['u'] = 17,
	    ['v'] = 13,
	    ['w'] = 19,
	    ['x'] = 13,
	    ['y'] = 24,
	    ['z'] = 19,
	    ['{'] = 18,
	    ['|'] = 12,
	    ['}'] = 18,
	    ['~'] = 9,
	};

	size_t i;
	unsigned c;

	c = 0;
	for (i = 0; s[i]; i++)
		c += tab[s[i] & 0xff];
	return c;
}

int
main(void)
{
	assert(cost("This is a short line.") == 300);
	assert(cost("THIS IS A LONGER, MORE EXPENSIVE LINE.") == 707);

	return 0;
}
