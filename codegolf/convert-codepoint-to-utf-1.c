/*

UTF-1 is one of the methods to transform ISO/IEC 10646 and Unicode into a sequence of bytes. It was originally for ISO 10646.

The UTF-1 encodes every character with variable length of byte sequence, just like UTF-8 does. It was designed to avoid control codes. But it was not designed to avoid duplication of a slash character ('/'), which is path delimiter for many operating systems. Additionally it takes a bit long to process the algorithm, because it is based on modulo 190, which is not power of two. Eventually UTF-8 was better than that.

In this challenge we are reviving UTF-1.
How it works

Every constant value in tables on this section is represented in hexadecimal value.

The symbol / is the integer division operator, % is the integer modulo operator, and ^ means power. The precedence of operators is ^ first, / second, % third, and others last. Here is how to convert each codepoint to UTF-1:
codepoint x 	UTF-1
U+0000 to U+009F 	(x)
U+00A0 to U+00FF 	(A0,x)
U+0100 to U+4015 	y=x-100 in (A1+y/BE,T(y%BE))
U+4016 to U+38E2D 	y=x-4016 in (F6+y/BE^2,T(y/BE%BE),T(y%BE))
U+38E2E to U+7FFFFFFF 	y=x-38E2E in (FC+y/BE^4,T(y/BE^3%BE),T(y/BE^2%BE),T(y/BE%BE),T(y%BE))

T(z) is a function such that:
z 	T(z)
0 to 5D 	z+21
5E to BD 	z+42
BE to DE 	z-BE
DF to FF 	z-60
Challenge

Your task is to implement a program or a function or a subroutine that takes one integer, who represents the codepoint of a character, to return a sequence of integers that represents its corresponding UTF-1 value.
Constraints

Input shall be an nonnegative integer up to 0x7FFFFFFF.
Rules

    Standard loopholes apply.
    Standard I/O rules apply.
    Shortest code wins.

Test cases

Taken from the Wikipedia article.

    U+007F  7F
    U+0080  80
    U+009F  9F
    U+00A0  A0 A0
    U+00BF  A0 BF
    U+00C0  A0 C0
    U+00FF  A0 FF
    U+0100  A1 21
    U+015D  A1 7E
    U+015E  A1 A0
    U+01BD  A1 FF
    U+01BE  A2 21
    U+07FF  AA 72
    U+0800  AA 73
    U+0FFF  B5 48
    U+1000  B5 49
    U+4015  F5 FF
    U+4016  F6 21 21
    U+D7FF  F7 2F C3
    U+E000  F7 3A 79
    U+F8FF  F7 5C 3C
    U+FDD0  F7 62 BA
    U+FDEF  F7 62 D9
    U+FEFF  F7 64 4C
    U+FFFD  F7 65 AD
    U+FFFE  F7 65 AE
    U+FFFF  F7 65 AF
   U+10000  F7 65 B0
   U+38E2D  FB FF FF
   U+38E2E  FC 21 21 21 21
   U+FFFFF  FC 21 37 B2 7A
  U+100000  FC 21 37 B2 7B
  U+10FFFF  FC 21 39 6E 6C
U+7FFFFFFF  FD BD 2B B9 40

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef long rune;

unsigned
tz(unsigned z)
{
	if (z <= 0x5d)
		return z + 0x21;
	if (z <= 0xbd)
		return z + 0x42;
	if (z <= 0xde)
		return z - 0xbe;
	if (z <= 0xff)
		return z - 0x60;
	return 0;
}

size_t
utf1enc(rune r, unsigned char *b)
{
	static const rune m = 0xbe;
	rune t;

	if (r < 0)
		return 0;

	if (r <= 0x9f) {
		b[0] = r;
		return 1;
	}

	if (r <= 0xff) {
		b[0] = 0xa0;
		b[1] = r;
		return 2;
	}

	if (r <= 0x4015) {
		t = r - 0x100;
		b[0] = 0xa1 + t / m;
		b[1] = tz(t % m);
		return 2;
	}

	if (r <= 0x38e2d) {
		t = r - 0x4016;
		b[0] = 0xf6 + t / (m * m);
		b[1] = tz((t / m) % m);
		b[2] = tz(t % m);
		return 3;
	}

	if (r <= 0x7fffffff) {
		t = r - 0x38e2e;
		b[0] = (0xfc + t / (m * m * m * m));
		b[1] = tz((t / (m * m * m)) % m);
		b[2] = tz((t / (m * m)) % m);
		b[3] = tz((t / m) % m);
		b[4] = tz(t % m);
		return 5;
	}

	return 0;
}

void
test(rune r, unsigned char *p, size_t n)
{
	unsigned char b[128];
	size_t i, m;

	printf("%lX: ", r);
	m = utf1enc(r, b);
	for (i = 0; i < m; i++)
		printf("%X ", b[i]);
	printf("\n");

	assert(m == n);
	assert(!memcmp(b, p, n));
}

int
main(void)
{
	unsigned char r1[] = {0x7F};
	unsigned char r2[] = {0x80};
	unsigned char r3[] = {0x9F};
	unsigned char r4[] = {0xA0, 0xA0};
	unsigned char r5[] = {0xA0, 0xBF};
	unsigned char r6[] = {0xA0, 0xC0};
	unsigned char r7[] = {0xA0, 0xFF};
	unsigned char r8[] = {0xA1, 0x21};
	unsigned char r9[] = {0xA1, 0x7E};
	unsigned char r10[] = {0xA1, 0xA0};
	unsigned char r11[] = {0xA1, 0xFF};
	unsigned char r12[] = {0xA2, 0x21};
	unsigned char r13[] = {0xAA, 0x72};
	unsigned char r14[] = {0xAA, 0x73};
	unsigned char r15[] = {0xB5, 0x48};
	unsigned char r16[] = {0xB5, 0x49};
	unsigned char r17[] = {0xF5, 0xFF};
	unsigned char r18[] = {0xF6, 0x21, 0x21};
	unsigned char r19[] = {0xF7, 0x2F, 0xC3};
	unsigned char r20[] = {0xF7, 0x3A, 0x79};
	unsigned char r21[] = {0xF7, 0x5C, 0x3C};
	unsigned char r22[] = {0xF7, 0x62, 0xBA};
	unsigned char r23[] = {0xF7, 0x62, 0xD9};
	unsigned char r24[] = {0xF7, 0x64, 0x4C};
	unsigned char r25[] = {0xF7, 0x65, 0xAD};
	unsigned char r26[] = {0xF7, 0x65, 0xAE};
	unsigned char r27[] = {0xF7, 0x65, 0xAF};
	unsigned char r28[] = {0xF7, 0x65, 0xB0};
	unsigned char r29[] = {0xFB, 0xFF, 0xFF};
	unsigned char r30[] = {0xFC, 0x21, 0x21, 0x21, 0x21};
	unsigned char r31[] = {0xFC, 0x21, 0x37, 0xB2, 0x7A};
	unsigned char r32[] = {0xFC, 0x21, 0x37, 0xB2, 0x7B};
	unsigned char r33[] = {0xFC, 0x21, 0x39, 0x6E, 0x6C};
	unsigned char r34[] = {0xFD, 0xBD, 0x2B, 0xB9, 0x40};

	test(0x7F, r1, sizeof(r1));
	test(0x80, r2, sizeof(r2));
	test(0x9F, r3, sizeof(r3));
	test(0xA0, r4, sizeof(r4));
	test(0xBF, r5, sizeof(r5));
	test(0xC0, r6, sizeof(r6));
	test(0xFF, r7, sizeof(r7));
	test(0x100, r8, sizeof(r8));
	test(0x15D, r9, sizeof(r9));
	test(0x15E, r10, sizeof(r10));
	test(0x1BD, r11, sizeof(r11));
	test(0x1BE, r12, sizeof(r12));
	test(0x7FF, r13, sizeof(r13));
	test(0x800, r14, sizeof(r14));
	test(0xFFF, r15, sizeof(r15));
	test(0x1000, r16, sizeof(r16));
	test(0x4015, r17, sizeof(r17));
	test(0x4016, r18, sizeof(r18));
	test(0xD7FF, r19, sizeof(r19));
	test(0xE000, r20, sizeof(r20));
	test(0xF8FF, r21, sizeof(r21));
	test(0xFDD0, r22, sizeof(r22));
	test(0xFDEF, r23, sizeof(r23));
	test(0xFEFF, r24, sizeof(r24));
	test(0xFFFD, r25, sizeof(r25));
	test(0xFFFE, r26, sizeof(r26));
	test(0xFFFF, r27, sizeof(r27));
	test(0x10000, r28, sizeof(r28));
	test(0x38E2D, r29, sizeof(r29));
	test(0x38E2E, r30, sizeof(r30));
	test(0xFFFFF, r31, sizeof(r31));
	test(0x100000, r32, sizeof(r32));
	test(0x10FFFF, r33, sizeof(r33));
	test(0x7FFFFFFF, r34, sizeof(r34));

	return 0;
}
