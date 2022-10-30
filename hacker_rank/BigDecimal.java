import java.math.*;
import java.util.*;

public class BigDecimal {
	static class Value {
		String number;
		java.math.BigDecimal decimal;
	};

	static class Sorter implements Comparator<Value> {
		public int compare(Value a, Value b) {
			return b.decimal.compareTo(a.decimal);
		}
	};

	public static void main(String[] args) {
		String[] numbers = {"9", "-100", "50", "0", "56.6", "90", "0.12", ".12", "02.34", "000.000"};
		decilize(numbers);
	}

	static void decilize(String[] numbers) {
		var values = new ArrayList<Value>();
		for (var number : numbers) {
			var value = new Value();
			value.number = number;
			value.decimal = new java.math.BigDecimal(number);
			values.add(value);
		}
		Collections.sort(values, new Sorter());
		for (var value : values)
			System.out.println(value.number);
	}
};
