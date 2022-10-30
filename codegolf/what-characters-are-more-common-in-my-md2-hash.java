/*

The challenge is simple

Write a script that, when given a string input, will hash the string using the MD2 hashing algorithm, and then return either a positive integer or negative integer output based on which character set below is more common in the resulting hash as a hexadecimal string:

01234567 - (positive)
89abcdef - (negative)

    The input will always be a string, but may be of any length up to 65535
    The entire input, whitespace and all, must be hashed
    For the purposes of this challenge, the integer 0 is considered neither positive nor negative (see tie output)
    The more common set is the one who's characters are more common within the 32 character hexadecimal hash string
    Your output may contain trailing whitespace of any kind, as long as the only non-whitespace characters are a valid truthy or falsey output
    In the event of a tie, where the hexadecimal string contains exactly 16 characters from each set, the program should output a 0

I/O Examples

Input: "" (Empty String)
Hash: 8350e5a3e24c153df2275c9f80692773
Output: 1

Input: "The quick brown fox jumps over the lazy cog" (Without quotes)
Hash: 6b890c9292668cdbbfda00a4ebf31f05
Output: -1

Input: "m" (Without quotes)
Hash: f720d455eab8b92f03ddc7868a934417
Output: 0

Winning Criterion

This is code-golf, fewest bytes wins!

*/

import java.security.*;
import java.lang.System.*;

class MD2Classify {
	public static void main(String[] args) {
		assert(common("") == 1);
		assert(common("The quick brown fox jumps over the lazy cog") == -1);
		assert(common("m") == 0);
	}

	public static int common(String str) {
		int ret = 0;
		try {
			MessageDigest md = MessageDigest.getInstance("MD2");
			byte[] buf = md.digest(str.getBytes());
			String hex = hexify(buf);
			ret = count(hex);
		} catch (Exception e) {
			ret = -2;
		}
		return ret;
	}

	public static String hexify(byte []buf) {
		String str = "";
		for (int i = 0; i < buf.length; i++)
			str += String.format("%02x", buf[i]);
		return str;
	}

	public static int count(String str) {
		int cnt = 0;
		for (char c : str.toCharArray()) {
			if ('0' <= c && c <= '7')
				cnt++;
			else if (('8' <= c && c <= '9') || ('a' <= c && c <= 'f'))
				cnt--;
		}
		if (cnt < 0)
			return -1;
		if (cnt > 0)
			return 1;
		return 0;
	}
}
