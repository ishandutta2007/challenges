/*

This function should take four integer inputs (a,b,c,d) and return a binary word based on which values equal the maximum of the four.

The return value will be between 1 and 0xF.

For example:

a = 6, b = 77, c = 1, d = 4

returns 2 (binary 0010; only 2nd-least significant bit is set corresponding to b being sole max value)

a = 4, b = 5, c = 10, d = 10

returns 0xC (binary 1100; 3rd- and 4th-least significant bits set corresponding to c and d equaling max value)

a = 1, b = 1, c = 1, d = 1

returns 0xF (binary 1111; all four bits set because all values equal the max)

Here is a simple implementation:

int getWord(int a, int b, int c, int d)
{
    int max = a;
    int word = 1;
    if (b > max)
    {
        max = b;
        word = 2;
    }
    else if (b == max)
    {
        word |= 2;
    }
    if (c > max)
    {
        max = c;
        word = 4;
    }
    else if (c == max)
    {
        word |= 4;
    }
    if (d > max)
    {
        word = 8;
    }
    else if (d == max)
    {
        word |= 8;
    }
    return word;
}

return value can be string of 0's and 1's, bool / bit vector, or integer

*/

package main

func main() {
	assert(word(6, 77, 1, 4) == 2)
	assert(word(4, 5, 10, 10) == 0xc)
	assert(word(1, 1, 1, 1) == 0xf)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func word(a, b, c, d int) int {
	v, w := con(a, b, 1, 2)
	v, w = con(v, c, w, 4)
	v, w = con(v, d, w, 8)
	return w
}

func con(a, b, x, y int) (int, int) {
	if a > b {
		return a, x
	}
	if a < b {
		return b, y
	}
	return a, x | y
}
