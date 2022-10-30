/*

Cryptographic hash functions are mathematical operations run on digital data; by comparing the computed hash (i.e., the output produced by executing a hashing algorithm) to a known and expected hash value, a person can determine the data's integrity. For example, computing the hash of a downloaded file and comparing the result to a previously published hash result can show whether the download has been modified or tampered with. In addition, cryptographic hash functions are extremely collision-resistant; in other words, it should be extremely difficult to produce the same hash output from two different input values using a cryptographic hash function.

Secure Hash Algorithm 2 (SHA-2) is a set of cryptographic hash functions designed by the National Security Agency (NSA). It consists of six identical hashing algorithms (i.e., SHA-256, SHA-512, SHA-224, SHA-384, SHA-512/224, SHA-512/256) with a variable digest size. SHA-256 is a 256-bit (32 byte) hashing algorithm which can calculate a hash code for an input of up to 264-1 bits. It undergoes  rounds of hashing and calculates a hash code that is a 64-digit hexadecimal number.

Given a string, s, print its SHA-256 hash value.

*/

import java.security.*;

public class Sha256 {
	public static void main(String[] args) {
		sha256("HelloWorld");
		sha256("Javarmi123");
		for (var arg : args)
			sha256(arg);
	}

	public static void sha256(String msg) {
		try {
			var md = MessageDigest.getInstance("SHA-256");
			var digest = md.digest(msg.getBytes());
			for (var i : digest)
				System.out.printf("%x", i);
			System.out.println();
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}
	}
};
