/*

Today your goal is to decrypt a secret message using AES. Given a ciphertext and key you will decrypt and print the message.

    Your program may be in any language. It will be run with input on stdin, and its output on stdout will be checked for correctness.

    The first line of input on stdin will be the 16 byte key, encoded in hexadecimal. The second line of input on stdin will be the 16 byte ciphertext, encoded in hexadecimal.

    The output of the program must be the 16 byte message after decrypting the ciphertext using AES-128 with the given key. You must output the result interpreted as ASCII octets. You may assume that any result is valid ASCII after decrypting.

    You may not use any library/built-in features that implement AES. You may use such features to convert between hex/binary/ASCII encodings.

Shortest code in bytes wins.

Example input and output:

bd8ab53f10b3d38576a1b9a15cf03834
02c0ee126cae50ba938a8b16f0e04d23

    Attack tomorrow.

And another:

f4af804ad097ba832906db0deb7569e3
38794338dafcb09d6b32b04357f64d4d

    Congratulations.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

typedef unsigned char uchar;
typedef unsigned int uint;

void
hex2bin(const char *s, uchar *b)
{
	size_t i, j;
	uint v;

	for (i = j = 0; s[i] && s[i + 1]; i += 2) {
		sscanf(s + i, "%02x", &v);
		b[j++] = v;
	}
}

void
test(const char *k, const char *s, const char *r)
{
	uchar key[16], cipher[16], text[16];
	AES_KEY dec;

	memset(key, 0, sizeof(key));
	memset(cipher, 0, sizeof(cipher));

	hex2bin(k, key);
	hex2bin(s, cipher);

	AES_set_decrypt_key(key, 128, &dec);
	AES_decrypt(cipher, text, &dec);
	assert(!memcmp(r, text, sizeof(text)));
}

int
main(void)
{
	test("bd8ab53f10b3d38576a1b9a15cf03834", "02c0ee126cae50ba938a8b16f0e04d23", "Attack tomorrow.");
	test("f4af804ad097ba832906db0deb7569e3", "38794338dafcb09d6b32b04357f64d4d", "Congratulations.");

	return 0;
}
