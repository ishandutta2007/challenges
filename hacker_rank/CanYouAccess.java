/*

You are given a class Solution and an inner class Inner.Private. The main method of class Solution takes an integer as input.
The powerof2 in class Inner.Private checks whether a number is a power of 2. 
You have to call the method powerof2 of the class Inner.Private from the main method of the class Solution.

*/

public class CanYouAccess {
	static class Inner {
		private class Private {
			private String powerof2(int num) {
				return (num > 0 && (num & (num-1)) == 0) ? "power of 2" : "not a power of 2";
			}
		}
	};
	
	public static void main(String []args) {
		for (int i = 0; i < 32; i++) {
			test(i);
		}
	}

	public static void test(int num) {
		CanYouAccess.Inner.Private o = new Inner().new Private();
		System.out.println(num + " is " + o.powerof2(num));
		System.out.println("An instance of class: " + o.getClass().getCanonicalName() + " has been created");
	}
};
