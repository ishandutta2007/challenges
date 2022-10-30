/*

Hash algorithms are easy to do one way, but essentially impossible to do in reverse. For example, if you hash something simple, like password123, it will give you a long code, unique to that word or phrase.
Ideally, there's no way to do this in reverse. You can't take the hash code and go back to the word or phrase you started with.

Make a function that returns the SHA-256 secure hash for a given string. The hash should be formatted in a hexadecimal digit string.

Notes

Bonus if you can do it without importing any libraries ;)

*/

#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

char *
sha256(const char *s, char b[SHA256_DIGEST_LENGTH * 2 + 1])
{
	unsigned char h[SHA256_DIGEST_LENGTH];
	SHA256_CTX c;
	size_t i;

	SHA256_Init(&c);
	SHA256_Update(&c, s, strlen(s));
	SHA256_Final(h, &c);

	for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
		sprintf(b + (i * 2), "%02x", h[i]);
	b[SHA256_DIGEST_LENGTH * 2] = '\0';

	return b;
}

int
main(void)
{
	char b[SHA256_DIGEST_LENGTH * 2 + 1];

	printf("%s\n", sha256("password123", b));
	printf("%s\n", sha256("Fluffy@home", b));
	printf("%s\n", sha256("Hey dude!", b));
	printf("%s\n", sha256("hi", b));
	printf("%s\n", sha256("password123", b));
	printf("%s\n", sha256("don't use easy passwords", b));
	return 0;
}
