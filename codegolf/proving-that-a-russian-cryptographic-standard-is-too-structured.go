/*

The aim of this challenge is to find an impossibly short implementation of the following function p, in the langage of your choosing. Here is C code implementing it (see this TIO link that also prints its outputs) and a wikipedia page containing it.

unsigned char pi[] = {
    252,238,221,17,207,110,49,22,251,196,250,218,35,197,4,77,
    233,119,240,219,147,46,153,186,23,54,241,187,20,205,95,193,
    249,24,101,90,226,92,239,33,129,28,60,66,139,1,142,79,
    5,132,2,174,227,106,143,160,6,11,237,152,127,212,211,31,
    235,52,44,81,234,200,72,171,242,42,104,162,253,58,206,204,
    181,112,14,86,8,12,118,18,191,114,19,71,156,183,93,135,
    21,161,150,41,16,123,154,199,243,145,120,111,157,158,178,177,
    50,117,25,61,255,53,138,126,109,84,198,128,195,189,13,87,
    223,245,36,169,62,168,67,201,215,121,214,246,124,34,185,3,
    224,15,236,222,122,148,176,188,220,232,40,80,78,51,10,74,
    167,151,96,115,30,0,98,68,26,184,56,130,100,159,38,65,
    173,69,70,146,39,94,85,47,140,163,165,125,105,213,149,59,
    7,88,179,64,134,172,29,247,48,55,107,228,136,217,231,137,
    225,27,131,73,76,63,248,254,141,83,170,144,202,216,133,97,
    32,113,103,164,45,43,9,91,203,155,37,208,190,229,108,82,
    89,166,116,210,230,244,180,192,209,102,175,194,57,75,99,182,
};

unsigned char p(unsigned char x) {
     return pi[x];
}

What is p

p is a component of two Russian cryptographic standards, namely the hash function Streebog and the block cipher Kuznyechik.
In this article (and during ISO meetings), the designers of these algorithms claimed that they generated the array pi by picking random 8-bit permutations.
"Impossible" implementations

There are 256!≈21684

permutations on 8 bits. Hence, for a given random permutation, a program that implement it shall not be expected to need fewer than 1683 bits.

However, we have found multiple abnormally small implementations (which we list here), for example the following C program:

p(x){unsigned char*k="@`rFTDVbpPBvdtfR@\xacp?\xe2>4\xa6\xe9{z\xe3q5\xa7\xe8",l=0,b=17;while(--l&&x^1)x=2*x^x/128*285;return l%b?k[l%b]^k[b+l/b]^b:k[l/b]^188;}

which contains only 158 characters and thus fits in 1264 bits. Click here to see that it works.

We talk about an "impossibly" short implementation because, if the permutation was the output of a random process (as claimed by its designers), then a program this short would not exist (see this page for more details).
Reference implementation

A more readable version of the previous C code is:

unsigned char p(unsigned char x){
     unsigned char
         s[]={1,221,146,79,147,153,11,68,214,215,78,220,152,10,69},
         k[]={0,32,50,6,20,4,22,34,48,16,2,54,36,52,38,18,0};
     if(x != 0) {
         unsigned char l=1, a=2;
         while(a!=x) {
             a=(a<<1)^(a>>7)*29;
             l++;
         }
         unsigned char i = l % 17, j = l / 17;
         if (i != 0) return 252^k[i]^s[j];
         else return 252^k[j];
     }
     else return 252;
}

The table k is such that k[x] = L(16-x), where L is linear in the sense that L(x^y)==L(x)^L(y), and where, like in C, ^ denotes the XOR.
However, we did not manage to leverage this property to shorten our implementation. We are not aware of any structure in s that could allow a simpler implementation---its output is always in the subfield though, i.e. s[x]16=s[x]

where the exponentiation is done in the finite field. Of course, you are absolutely free to use a simpler expression of s should you find one!

The while loop corresponds to the evaluation of a discrete logarithm in the finite field with 256 elements.
It works via a simple brute-force search: the dummy variable a is set to be a generator of the finite field, and it is multiplied by this generator until the result is equal to x.
When it is the case, we have that l is the discrete log of x. This function is not defined in 0, hence the special case corresponding to the if statement.

The multiplication by the generator can be seen as a multiplication by X in F2[X] which is then reduced modulo the polynomial X8+X4+X3+X2+1.
The role of the unsigned char is to ensure that the variable a stays on 8 bits.
Alternatively, we could use a=(a<<1)^(a>>7)*(256^29), in which case a could be an int (or any other integer type).
On the other hand, it is necessary to start with l=1,a=2 as we need to have l=255 when x is equal to 1.

More details on the properties of p are presented in our paper, with a writeup of most of our optimizations to obtain the previous short implementation.
Rules

Propose a program that implements the function p in less than 1683 bits. As the shorter the program, the more abnormal it is, for a given language, shorter is better. If your language happens to have Kuznyechik, Streebog or p as a builtin, you cannot use them.

The metric we use to determine the best implementation is the program length in bytes. We use the bit-length in our academic paper but we stick to bytes here for the sake of simplicity.

If your language does not have a clear notion of function, argument or output, the encoding is up to you to define, but tricks like encoding the value pi[x] as x are obviously forbidden.

We have already submitted a research paper with our findings on this topic. It is available here. However, should it be published in a scientific venue, we will gladly acknowledge the authors of the best implementations.

By the way, thanks to xnor for his help when drafting this question!

*/

package main

func main() {
	for i := range pi {
		assert(pi[i] == p(uint8(i)))
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

var pi = []uint8{
	252, 238, 221, 17, 207, 110, 49, 22, 251, 196, 250, 218, 35, 197, 4, 77,
	233, 119, 240, 219, 147, 46, 153, 186, 23, 54, 241, 187, 20, 205, 95, 193,
	249, 24, 101, 90, 226, 92, 239, 33, 129, 28, 60, 66, 139, 1, 142, 79,
	5, 132, 2, 174, 227, 106, 143, 160, 6, 11, 237, 152, 127, 212, 211, 31,
	235, 52, 44, 81, 234, 200, 72, 171, 242, 42, 104, 162, 253, 58, 206, 204,
	181, 112, 14, 86, 8, 12, 118, 18, 191, 114, 19, 71, 156, 183, 93, 135,
	21, 161, 150, 41, 16, 123, 154, 199, 243, 145, 120, 111, 157, 158, 178, 177,
	50, 117, 25, 61, 255, 53, 138, 126, 109, 84, 198, 128, 195, 189, 13, 87,
	223, 245, 36, 169, 62, 168, 67, 201, 215, 121, 214, 246, 124, 34, 185, 3,
	224, 15, 236, 222, 122, 148, 176, 188, 220, 232, 40, 80, 78, 51, 10, 74,
	167, 151, 96, 115, 30, 0, 98, 68, 26, 184, 56, 130, 100, 159, 38, 65,
	173, 69, 70, 146, 39, 94, 85, 47, 140, 163, 165, 125, 105, 213, 149, 59,
	7, 88, 179, 64, 134, 172, 29, 247, 48, 55, 107, 228, 136, 217, 231, 137,
	225, 27, 131, 73, 76, 63, 248, 254, 141, 83, 170, 144, 202, 216, 133, 97,
	32, 113, 103, 164, 45, 43, 9, 91, 203, 155, 37, 208, 190, 229, 108, 82,
	89, 166, 116, 210, 230, 244, 180, 192, 209, 102, 175, 194, 57, 75, 99, 182,
}

func p(x uint8) uint8 {
	s := []uint8{1, 221, 146, 79, 147, 153, 11, 68, 214, 215, 78, 220, 152, 10, 69}
	k := []uint8{0, 32, 50, 6, 20, 4, 22, 34, 48, 16, 2, 54, 36, 52, 38, 18, 0}
	if x == 0 {
		return 252
	}

	l := uint8(1)
	a := uint8(2)
	for a != x {
		a = (a << 1) ^ (a>>7)*29
		l++
	}
	i := l % 17
	j := l / 17
	if i != 0 {
		return 252 ^ k[i] ^ s[j]
	}
	return 252 ^ k[j]
}
