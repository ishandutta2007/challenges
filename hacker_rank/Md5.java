/*

MD5 (Message-Digest algorithm 5) is a widely-used cryptographic hash function with a 128-bit hash value. Here are some common uses for MD5:

To store a one-way hash of a password.
To provide some assurance that a transferred file has arrived intact.
MD5 is one in a series of message digest algorithms designed by Professor Ronald Rivest of MIT (Rivest, 1994);
however, the security of MD5 has been severely compromised, most infamously by the Flame malware in 2011.
The CMU Software Engineering Institute essentially considers MD5 to be "cryptographically broken and unsuitable for further use".

Given an alphanumeric string, s, denoting a password, compute and print its MD5 encryption value.

*/

import java.security.*;

public class Md5 {
	public static void main(String[] args) {
		md5("HelloWorld");
		md5("Javarmi123");
		for (var arg : args)
			md5(arg);
	}

	public static void md5(String msg) {
		try {
			var md = MessageDigest.getInstance("MD5");
			var digest = md.digest(msg.getBytes());
			for (var i : digest)
				System.out.printf("%x", i);
			System.out.println();
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}
	}
};
