class Loop1 {
	public static void main(String[] args) {
		printSequence(2);
	}

	static void printSequence(int n) {
		for (int i = 1; i <= 10; i++) {
			System.out.printf("%d x %d = %d\n", n, i, n * i);
		}
	}
};
