/*

Inspired by the recent craze over another two character language, ;#

Intro

According to community consensus, acceptable answers on this site must use programming languages that, at minimum:

Can determine if a natural number is prime
Can add two natural numbers together
Can represent a list/tuple of numbers, as well as a single number
For purposes of this challenge, we will ignore #3. Therefore, the simplest language that could be used on this site (ignoring #3) would have exactly two commands, isPrime and add.
For ease of interpretation and byte count, let's assign isPrime to p and add to +. Thus, we have our language, +p. Your challenge is to interpret some +p code.

Behavior

+ the add instruction takes two numbers, adds them, and outputs the result
p the isPrime instruction takes a single number, and outputs 1 if it is prime, and 0 if it is not
Rules

You must write a program/function which, given a string of characters, interprets that string as +p code. You may assume well-formed input (only + and p characters).
Input is flexible. You may take in the program as a string, character array, integer array of codepoints, etc. Input for the program being interpreted is also flexible.
You may take in an integer array, and use up entries as the program executes, or each instruction (+ and p) may individually request input.
You may assume there will be enough input for every instruction. Input is guaranteed to consist of numbers between 0 and 200 (but your algorithms should theoretically work for any positive integer input).
Output is also flexible. You may print the results, return them as a list, return a string that contains all the results, etc.
If printed or returned as a string, output must be separated by some non-digit, consistent separator, such as a new line, tab, space, or , character.
You may have a trailing separator or some trailing whitespace. Also, p's output may be any truthy or falsey value, as defined by the language you are working in, rather than 1 or 0.
The interpreter may or may not terminate (if it is a full program), but it must stop printing after all instructions are interpreted. (It cannot continue printing the separator forever, or a null character, etc.).
These standard loopholes are forbidden by default
This is code-golf, the answer with the least bytes wins
Test Cases

Program: +
Input: [56, 50]
Output: 106
----------------------------------
Program: p
Input: [12]
Output: 0
----------------------------------
Program: p
Input: [13]
Output: 1
----------------------------------
Program: ++
Input: [172, 120, 33, 58]
Output: 292 91
----------------------------------
Program: p
Input: [29]
Output: 1
----------------------------------
Program: pp
Input: [176, 12]
Output: 0 0
----------------------------------
Program: ++++p
Input: [32, 16, 69, 197, 73, 171, 21, 178, 72]
Output: 48 266 244 199 0
----------------------------------
Program: pp+++p+pp+
Input: [151, 27, 119, 189, 198, 107, 174, 15, 166, 106, 134, 108, 169, 55, 42]
Output: 1 0 308 305 189 0 240 0 0 97
----------------------------------
Program: p+p+++++++pp+p
Input: [143, 67, 30, 149, 178, 52, 112, 122, 55, 122, 142, 199, 20, 175, 138, 80, 116, 180, 50, 116, 15, 92, 74]
Output: 0 97 1 230 234 177 341 195 218 296 0 0 107 0
----------------------------------
Program: ++p++p+pp+++++p+p+pp++
Input: [120, 177, 23, 116, 163, 52, 65, 98, 177, 16, 96, 131, 160, 48, 153, 0, 139, 33, 62, 49, 129, 86, 99, 135, 187, 80, 137, 130, 113, 136, 0, 1, 186, 100, 38, 153]
Output: 297 139 1 117 275 0 227 0 0 153 172 111 215 234 0 217 0 249 0 0 286 191
----------------------------------
Program: ++p+++++p+p+++++++
Input: [181, 169, 6, 84, 68, 171, 129, 107, 106, 114, 197, 58, 11, 88, 156, 169, 43, 77, 49, 43, 102, 78, 93, 51, 91, 37, 64, 93, 82, 126, 181, 81, 44]
Output: 350 90 0 300 213 311 69 244 0 120 0 145 171 142 101 175 307 125
----------------------------------
Program: ++p+
Input: [131, 127, 115, 40, 113, 196, 83]
Output: 258 155 1 279
----------------------------------
Program: +ppp++p+ppp+p++++++++p+p+++pp+ppp++
Input: [6, 9, 187, 168, 96, 167, 178, 139, 86, 148, 99, 103, 166, 18, 119, 15, 132, 77, 16, 88, 139, 34, 58, 90, 43, 69, 68, 152, 59, 106, 134, 49, 155, 100, 52, 55, 27, 188, 41, 77, 23, 49, 171, 23, 193, 84, 111, 165, 80, 18, 63, 23, 116, 112, 119]
Output: 15 0 0 0 345 225 0 202 0 0 0 147 0 104 173 148 112 220 165 183 255 0 82 0 118 72 194 1 0 276 0 0 0 139 231
----------------------------------
Program: ++++++++p++++++++++++
Input: [156, 5, 34, 25, 117, 98, 139, 131, 88, 82, 191, 13, 1, 170, 51, 116, 144, 85, 92, 170, 25, 94, 149, 131, 19, 161, 115, 160, 8, 6, 195, 101, 11, 185, 87, 50, 33, 140, 188, 135, 164]
Output: 161 59 215 270 170 204 171 167 0 177 195 243 150 276 168 201 112 272 83 328 299
----------------------------------
Many, many, very long test cases

The java code used to generate test cases

Example

Below is an ungolfed java function which will interpret +p:

public static void interpret(String program, int[] input) {
    int index = 0;
    for (char inst : program.toCharArray()) {
        switch (inst) {
            case '+':
                System.out.print((input[index++] + input[index++]) + " ");
                break;
            case 'p':
                int n = input[index++];
                System.out.print((isPrime(n) ? 1 : 0) + " ");
                break;
        }
    }
}

public static boolean isPrime(long n) { //Taken from https://stackoverflow.com/a/2385999/4484294
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    long sqrtN = (long) Math.sqrt(n) + 1;
    for (long i = 6L; i <= sqrtN; i += 6) {
        if (n % (i - 1) == 0 || n % (i + 1) == 0) return false;
    }
    return true;
}

Note: Using the search query prime AND add AND interpret is:question, there do not appear to be any duplicates to this question. If there is one, sorry.

*/

#include <stdio.h>
#include <math.h>

int
isprime(int n)
{
	int i, l;

	if (n < 2)
		return 0;
	if (n == 2 || n == 3)
		return 1;
	if (!(n % 2) || !(n % 3))
		return 0;

	l = sqrt(n) + 1;
	for (i = 6; i <= l; i += 6) {
		if (!(n % (i - 1)) || !(n % (i + 1)))
			return 0;
	}
	return 1;
}

void
interpret(const char *s, int *p)
{
	size_t i, n;

	for (i = n = 0; s[i]; i++) {
		switch (s[i]) {
		case '+':
			printf("%d ", p[n] + p[n + 1]);
			n += 2;
			break;
		case 'p':
			printf("%d ", isprime(p[n]));
			n += 1;
			break;
		}
	}
	printf("\n");
}

int
main(void)
{
	int i1[] = {56, 50};
	int i2[] = {12};
	int i3[] = {13};
	int i4[] = {172, 120, 33, 58};
	int i5[] = {29};
	int i6[] = {176, 12};
	int i7[] = {32, 16, 69, 197, 73, 171, 21, 178, 72};
	int i8[] = {151, 27, 119, 189, 198, 107, 174, 15, 166, 106, 134, 108, 169, 55, 42};
	int i9[] = {143, 67, 30, 149, 178, 52, 112, 122, 55, 122, 142, 199, 20, 175, 138, 80, 116, 180, 50, 116, 15, 92, 74};
	int i10[] = {120, 177, 23, 116, 163, 52, 65, 98, 177, 16, 96, 131, 160, 48, 153, 0, 139, 33, 62, 49, 129, 86, 99, 135, 187, 80, 137, 130, 113, 136, 0, 1, 186, 100, 38, 153};
	int i11[] = {181, 169, 6, 84, 68, 171, 129, 107, 106, 114, 197, 58, 11, 88, 156, 169, 43, 77, 49, 43, 102, 78, 93, 51, 91, 37, 64, 93, 82, 126, 181, 81, 44};
	int i12[] = {131, 127, 115, 40, 113, 196, 83};
	int i13[] = {6, 9, 187, 168, 96, 167, 178, 139, 86, 148, 99, 103, 166, 18, 119, 15, 132, 77, 16, 88, 139, 34, 58, 90, 43, 69, 68, 152, 59, 106, 134, 49, 155, 100, 52, 55, 27, 188, 41, 77, 23, 49, 171, 23, 193, 84, 111, 165, 80, 18, 63, 23, 116, 112, 119};
	int i14[] = {156, 5, 34, 25, 117, 98, 139, 131, 88, 82, 191, 13, 1, 170, 51, 116, 144, 85, 92, 170, 25, 94, 149, 131, 19, 161, 115, 160, 8, 6, 195, 101, 11, 185, 87, 50, 33, 140, 188, 135, 164};

	interpret("+", i1);
	interpret("p", i2);
	interpret("p", i3);
	interpret("++", i4);
	interpret("p", i5);
	interpret("pp", i6);
	interpret("++++p", i7);
	interpret("pp+++p+pp+", i8);
	interpret("p+p+++++++pp+p", i9);
	interpret("++p++p+pp+++++p+p+pp++", i10);
	interpret("++p+++++p+p+++++++", i11);
	interpret("++p+", i12);
	interpret("+ppp++p+ppp+p++++++++p+p+++pp+ppp++", i13);
	interpret("++++++++p++++++++++++", i14);

	return 0;
}
