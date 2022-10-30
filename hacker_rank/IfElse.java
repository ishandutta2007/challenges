/*

Given an integer, n, perform the following conditional actions:

If n is odd, print Weird
If n is even and in the inclusive range of 2 to 5, print Not Weird
If n is even and in the inclusive range of 6 to 20, print Weird
If n is even and greater than 20, print Not Weird
Complete the stub code provided in your editor to print whether or not n is weird.

*/

public class IfElse {
	public static void main(String[] args) {
		System.out.println(isWeird(3));
		System.out.println(isWeird(24));
	}

	public static String isWeird(int n) {
		if (n%2 != 0)
			return "Weird";
		if (2 <= n && n <= 5)
			return "Not Weird";
		if (6 <= n && n <= 20)
			return "Weird";
		return "Not Weird";
	}
};
