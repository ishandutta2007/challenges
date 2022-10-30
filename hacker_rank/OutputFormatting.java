import java.util.ArrayList;

public class OutputFormatting {
	public static class Language {
		String name;
		int value;

		Language(String name, int value) {
			this.name = name;
			this.value = value;
		}
	};

	public static void main(String[] args) {
		var languages = new ArrayList<Language>();
		languages.add(new Language("java", 100));
		languages.add(new Language("cpp", 65));
		languages.add(new Language("python", 50));
		printLanguages(languages);
	}

	public static void printLanguages(ArrayList<Language> list) {
		System.out.println("================================");
		for (Language l : list)
			System.out.printf("%-15s %03d\n", l.name, l.value);
		System.out.println("================================");
	}
};
