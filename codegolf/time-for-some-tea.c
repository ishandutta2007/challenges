/*

Introduction
A while back I stumbled across the tiny encryption algorithm (TEA) and since then I have recommended it whenever special cryptographic security properties were un-needed and a self-implementation was a requirement.
Now today, we want to take the name *tiny* encryption algorithm literally and your task will be to implement the tiniest encryption algorithm!

Specification
Input
The input is a list of 8 bytes (or your language equivalent), this is the plaintext, and another list of 16 bytes (or your language equivalent), this is the key.
Input conversion from decimal, hexadecimal, octal or binary is allowed.
Reading 1 64-bit, 2 32-bit or 4 16-bit integers as output (optionally as a list) is allowed (for the plaintext, double the numbers for the key)

Output
The output is a list of 8 bytes (or your language equivalent), this is the ciphertext.
Output conversion to decimal, hexadecimal, octal or binary is allowed, but not mandatory.
Writing 1 64-bit, 2 32-bit or 4 16-bit integers as output (optionally as a list) is allowed.

What to do?
Your task is to implement the encryption direction of the tiny encryption algorithm (TEA), note XTEA and XXTEA are other algorithms.
Wikipedia has a C-code example and a list of references to some implementations in other languages, this is the original description (PDF).

More Formally:
Let k1, k2, k3, k4, v1, v2, sum be unsigned 32-bit integers.
(k1,k2,k3,k4) <- key input
(v1,v2) <- plaintext input
sum <- 0
repeat 32 times:
    sum <- ( sum + 0x9e3779b9 ) mod 2^32
    v0  <- ( v0 + ( ((v1 << 4) + k0) XOR (v1 + sum) XOR ((v1 >> 5) + k1) ) ) mod 2^32
    v1  <- ( v1 + ( ((v0 << 4) + k2) XOR (v0 + sum) XOR ((v0 >> 5) + k3) ) ) mod 2^32
output <- (v0,v1)

where 0x9e3779b9 is a hexadecimal constant and
"<<" denotes logical left shift and ">>" denotes logical right shift.
Potential corner cases
\0 is a valid character and you may not shorten your input nor output.
Integer encoding is assumed to be little-endian (e.g. what you probably already have).

Who wins?
This is code-golf so the shortest answer in bytes wins!
Standard rules apply of course.

Test-cases
Test vectors were generated using the Wikipedia C code example.

Key: all zero (16x \0)
Plaintext -> Ciphertext (all values as two 32-bit hexadecimal words)
00000000 00000000 -> 41ea3a0a 94baa940
3778001e 2bf2226f -> 96269d3e 82680480
48da9c6a fbcbe120 -> 2cc31f2e 228ad143
9bf3ceb8 1e076ffd -> 4931fc15 22550a01
ac6dd615 9c593455 -> 392eabb4 505e0755
ebad4b59 7b962f3c -> b0dbe165 cfdba177
ca2d9099 a18d3188 -> d4641d84 a4bccce6
b495318a 23a1d131 -> 39f73ca0 bda2d96c
bd7ce8da b69267bf -> e80efb71 84336af3
235eaa32 c670cdcf -> 80e59ecd 6944f065
762f9c23 f767ea2c -> 3f370ca2 23def34c
Here are some self-generated test vectors with non-zero keys:

format: ( 4x 32-bit word key , 2x 32-bit word plaintext ) -> ( 2x 32-bit word ciphertext )
(all in hexadecimal)

( 4300e123 e39877ae 7c4d7a3c 98335923 , a9afc671 79dcdb73 ) -> ( 5d357799 2ac30c80 )
( 4332fe8f 3a127ee4 a9ca9de9 dad404ad , d1fe145a c84694ee ) -> ( a70b1d53 e7a9c00e )
( 7f62ac9b 2a0771f4 647db7f8 62619859 , 618f1ac2 67c3e795 ) -> ( 0780b34d 2ca7d378 )
( 0462183a ce7edfc6 27abbd9a a634d96e , 887a585d a3f83ef2 ) -> ( d246366c 81b87462 )
( 34c7b65d 78aa9068 599d1582 c42b7e33 , 4e81fa1b 3d22ecd8 ) -> ( 9d5ecc3b 947fa620 )
( f36c977a 0606b8a0 9e3fe947 6e46237b , 5d8e0fbe 2d3b259a ) -> ( f974c6b3 67e2decf )
( cd4b3820 b2f1e5a2 485dc7b3 843690d0 , 48db41bb 5ad77d7a ) -> ( b4add44a 0c401e70 )
( ee2744ac ef5f53ec 7dab871d d58b3f70 , 70c94e92 802f6c66 ) -> ( 61e14e3f 89408981 )
( 58fda015 c4ce0afb 49c71f9c 7e0a16f0 , 6ecdfbfa a705a912 ) -> ( 8c2a9f0c 2f56c18e )
( 87132255 41623986 bcc3fb61 7e6142ce , 9d0eff09 55ac6631 ) -> ( 8919ea55 c7d430c6 )

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long ulong;

void
tea(ulong k[4], ulong v[2])
{
	static const ulong mask = 0xfffffffful;
	ulong i, s;

	for (i = s = 0; i < 32; i++) {
		s = (s + 0x9e3779b9ul) & mask;
		v[0] = (v[0] + (((v[1] << 4) + k[0]) ^ (v[1] + s) ^ ((v[1] >> 5) + k[1]))) & mask;
		v[1] = (v[1] + (((v[0] << 4) + k[2]) ^ (v[0] + s) ^ ((v[0] >> 5) + k[3]))) & mask;
	}
}

void
test(ulong k[4], ulong p[2], ulong c[2])
{
	tea(k, p);
	printf("%lx %lx\n", p[0], p[1]);
	assert(p[0] == c[0]);
	assert(p[1] == c[1]);
}

int
main(void)
{
	ulong kz[] = {0, 0, 0, 0};

	ulong p1[] = {0, 0};
	ulong c1[] = {0x41ea3a0aul, 0x94baa940ul};

	ulong p2[] = {0x3778001eul, 0x2bf2226ful};
	ulong c2[] = {0x96269d3eul, 0x82680480ul};

	ulong p3[] = {0x48da9c6aul, 0xfbcbe120ul};
	ulong c3[] = {0x2cc31f2eul, 0x228ad143ul};

	ulong p4[] = {0x9bf3ceb8ul, 0x1e076ffdul};
	ulong c4[] = {0x4931fc15ul, 0x22550a01ul};

	ulong p5[] = {0xac6dd615ul, 0x9c593455ul};
	ulong c5[] = {0x392eabb4ul, 0x505e0755ul};

	ulong p6[] = {0xebad4b59ul, 0x7b962f3cul};
	ulong c6[] = {0xb0dbe165ul, 0xcfdba177ul};

	ulong p7[] = {0xca2d9099ul, 0xa18d3188ul};
	ulong c7[] = {0xd4641d84ul, 0xa4bccce6ul};

	ulong p8[] = {0xb495318aul, 0x23a1d131ul};
	ulong c8[] = {0x39f73ca0ul, 0xbda2d96cul};

	ulong p9[] = {0xbd7ce8daul, 0xb69267bful};
	ulong c9[] = {0xe80efb71ul, 0x84336af3ul};

	ulong p10[] = {0x235eaa32ul, 0xc670cdcful};
	ulong c10[] = {0x80e59ecdul, 0x6944f065ul};

	ulong p11[] = {0x762f9c23ul, 0xf767ea2cul};
	ulong c11[] = {0x3f370ca2ul, 0x23def34cul};

	ulong k12[] = {0x4300e123ul, 0xe39877aeul, 0x7c4d7a3cul, 0x98335923ul};
	ulong p12[] = {0xa9afc671ul, 0x79dcdb73ul};
	ulong c12[] = {0x5d357799ul, 0x2ac30c80ul};

	ulong k13[] = {0x4332fe8ful, 0x3a127ee4ul, 0xa9ca9de9ul, 0xdad404adul};
	ulong p13[] = {0xd1fe145aul, 0xc84694eeul};
	ulong c13[] = {0xa70b1d53ul, 0xe7a9c00eul};

	ulong k14[] = {0x7f62ac9bul, 0x2a0771f4ul, 0x647db7f8ul, 0x62619859ul};
	ulong p14[] = {0x618f1ac2ul, 0x67c3e795ul};
	ulong c14[] = {0x0780b34dul, 0x2ca7d378ul};

	ulong k15[] = {0x0462183aul, 0xce7edfc6ul, 0x27abbd9aul, 0xa634d96eul};
	ulong p15[] = {0x887a585dul, 0xa3f83ef2ul};
	ulong c15[] = {0xd246366cul, 0x81b87462ul};

	ulong k16[] = {0x34c7b65dul, 0x78aa9068ul, 0x599d1582ul, 0xc42b7e33ul};
	ulong p16[] = {0x4e81fa1bul, 0x3d22ecd8ul};
	ulong c16[] = {0x9d5ecc3bul, 0x947fa620ul};

	ulong k17[] = {0xf36c977aul, 0x0606b8a0ul, 0x9e3fe947ul, 0x6e46237bul};
	ulong p17[] = {0x5d8e0fbeul, 0x2d3b259aul};
	ulong c17[] = {0xf974c6b3ul, 0x67e2decful};

	ulong k18[] = {0xcd4b3820ul, 0xb2f1e5a2ul, 0x485dc7b3ul, 0x843690d0ul};
	ulong p18[] = {0x48db41bbul, 0x5ad77d7aul};
	ulong c18[] = {0xb4add44aul, 0x0c401e70ul};

	ulong k19[] = {0xee2744acul, 0xef5f53ecul, 0x7dab871dul, 0xd58b3f70ul};
	ulong p19[] = {0x70c94e92ul, 0x802f6c66ul};
	ulong c19[] = {0x61e14e3ful, 0x89408981ul};

	ulong k20[] = {0x58fda015ul, 0xc4ce0afbul, 0x49c71f9cul, 0x7e0a16f0ul};
	ulong p20[] = {0x6ecdfbfaul, 0xa705a912ul};
	ulong c20[] = {0x8c2a9f0cul, 0x2f56c18eul};

	ulong k21[] = {0x87132255ul, 0x41623986ul, 0xbcc3fb61ul, 0x7e6142ceul};
	ulong p21[] = {0x9d0eff09ul, 0x55ac6631ul};
	ulong c21[] = {0x8919ea55ul, 0xc7d430c6ul};

	test(kz, p1, c1);
	test(kz, p2, c2);
	test(kz, p3, c3);
	test(kz, p4, c4);
	test(kz, p5, c5);
	test(kz, p6, c6);
	test(kz, p7, c7);
	test(kz, p8, c8);
	test(kz, p9, c9);
	test(kz, p10, c10);
	test(kz, p11, c11);
	test(k12, p12, c12);
	test(k13, p13, c13);
	test(k14, p14, c14);
	test(k15, p15, c15);
	test(k16, p16, c16);
	test(k17, p17, c17);
	test(k18, p18, c18);
	test(k19, p19, c19);
	test(k20, p20, c20);
	test(k21, p21, c21);

	return 0;
}
