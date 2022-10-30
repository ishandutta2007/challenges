/*

Challenge and origin
On Stack Overflow a popular question is: How to convert byte size into human readable format in java? The most up voted answer has a quite nice method for doing this, but this is codegolf and we can do better, can't we?

Your challenge is to write a method or program that coverts the given number of bytes to the correct human readable format and prints the result to the standard out of your language.*

*See the rules for more clarification!

Input
The input will always be a positive number of bytes with a maximum of (2^31)-1.

Output
You may choose if you prefer the International System of Units or the binary notation as output (the SI notation probably saves you some bytes).

SI:      B, kB,  MB,  GB
Binary:  B, KiB, MiB, GiB
Note: Higher units than GB or GiB are not posible due to the restricted input range.

Example output
International System of Units:

Input       Output
0           0.0     B
999         999.0   B
1000        1.0     kB
1023        1.0     kB
1024        1.0     kB
1601        1.6     kB
160581      160.6   kB
4066888     4.1     MB
634000000   634.0   MB
2147483647  2.1     GB
Binary:

Input       Output
0           0.0     B
999         999.0   B
1000        1000.0  B
1023        1023.0  B
1024        1.0     KiB
1601        1.6     KiB
160581      156.8   KiB
4066888     3.9     MiB
634000000   604.6   MiB
2147483647  2.0     GiB
Rules
Build-in functions for byte formatting are not allowed!
The output should always be in the same notation standard, you may not mix SI or binary;
The output should always be in the largest unit possible where the resulting number is still higher or equal to one;
The output should always have one decimal number, but you may choose to print an integer number when the resulting output is in bytes (B);
You may choose if you would like to add a space, tab or nothing between the number and the unit;
Input is received via STDIN or function parameters;
Output is printed to the console or returned as string (or similar character container);
This is code golf, so the shortest answer wins. Have fun!
Edit: Even more clarification
Some numbers have interesting rounding behaviors like the number 999950. Most code implementations would return 1000.0 kB instead of 1.0 MB.
Why? Because 999950/1000 evaluates to 999.950 which is effectively rounded to 1000.0 when using String.format in Java (in most other languages too). Hench some extra checks are needed to handle cases like this.

For this challenge both styles, 1000.0 kB and 1.0 MB are accepted, although the last style is preferred.

Pseudo code / java test code:


public static String bytesToSI(long bytes){
      if (bytes < 1000){
          return bytes + ".0 B";
      }
      //Without this rounding check:
      //999950    would be 1000.0 kB instead of 1.0 MB
      //999950000 would be 1000.0 MB instead of 1.0 GB
      int p = (int) Math.ceil(Math.log(bytes) / Math.log(1000));
      if(bytes/Math.pow(1000, p) < 0.99995){
          p--;
      }
      //Format
      return String.format("%.1f %sB", bytes/Math.pow(1000, p), "kMGTPE".charAt(p-1));
}

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef long long vlong;

char *
by2si(vlong n, char *b)
{
	static const char units[] = "kMGTPE";
	vlong p;

	if (n < 1000) {
		sprintf(b, "%lld.0 B", n);
		return b;
	}

	p = ceil(log(n) / log(1000));
	if ((n / pow(1000, p)) < 0.99995)
		p--;

	sprintf(b, "%.1f %cB", n / pow(1000, p), units[p - 1]);
	return b;
}

void
test(vlong n, const char *r)
{
	char b[128];

	by2si(n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(0, "0.0 B");
	test(999, "999.0 B");
	test(1000, "1.0 kB");
	test(1023, "1.0 kB");
	test(1024, "1.0 kB");
	test(1601, "1.6 kB");
	test(160581ULL, "160.6 kB");
	test(4066888ULL, "4.1 MB");
	test(634000000ULL, "634.0 MB");
	test(2147483647ULL, "2.1 GB");

	return 0;
}
