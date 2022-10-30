/*

Given a positive integer N>=4, output an RSA key pair (both the private and the public key) whose key length is N bits.

The RSA key generation algorithm is as follows:

Choose an N-bit semiprime n. Let the prime factors of n be p and q.
Compute λ(n)=LCM(p−1,q−1).
Choose an integer e
such that 1<e<λ(n) and GCD(e,λ(n))=1.
Compute d≡e−1(modλ(n)).

The public key is composed of n
and e. The private key is d.

Rules

    You may assume that there exists at least one semiprime n with bit length N.

Output may be in any consistent and unambiguous format.
e and n must be chosen from discrete uniform distributions.
You may assume that N is less than or equal to the maximum number of bits for integers representable in your language, if your language has such a restriction.

*/

#include <stdio.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>

int
genkeys(const char *pubfile, const char *privfile, int bits)
{
	RSA *rsa;
	BIGNUM *bn;
	BIO *pub, *priv;
	int r;

	pub = NULL;
	priv = NULL;
	rsa = NULL;
	bn = BN_new();
	r = BN_set_word(bn, RSA_F4);
	if (r != 1)
		goto out;

	rsa = RSA_new();
	r = RSA_generate_key_ex(rsa, bits, bn, NULL);
	if (r != 1)
		goto out;

	pub = BIO_new_file(pubfile, "w+");
	priv = BIO_new_file(privfile, "w+");

	r |= PEM_write_bio_RSAPublicKey(pub, rsa);
	r |= PEM_write_bio_RSAPrivateKey(priv, rsa, NULL, NULL, 0, NULL, NULL);
	if (r != 1)
		goto out;

out:
	BIO_free_all(pub);
	BIO_free_all(priv);
	RSA_free(rsa);
	BN_free(bn);

	return (r == 1) ? 0 : -1;
}

int
main(void)
{
	genkeys("public.pem", "private.pem", 8192);
	return 0;
}
