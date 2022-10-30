class Loop2 {
	public static void main(String[] args) {
		printSequence(0, 2, 10);
		printSequence(5, 3, 5);
	}

	static void printSequence(int a, int b, int n) {
		int s = a + b;
		for (int i = 0; i < n; i++) {
			System.out.print(s + " ");
			b *= 2;
			s += b;
		}
		System.out.println();
	}
};
