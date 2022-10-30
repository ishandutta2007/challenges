/*
Java allows for Covariant Return Types, which means you can vary your return type as long you are returning a subclass of your specified return type.

Method Overriding allows a subclass to override the behavior of an existing superclass method and
specify a return type that is some subclass of the original return type.
It is best practice to use the @Override annotation when overriding a superclass method.

Implement the classes and methods detailed in the diagram below:

You will be given a partially completed code in the editor where the main method takes the name of a state (i.e., WestBengal, or AndhraPradesh)
and prints the national flower of that state using the classes and methods written by you.

Note: Do not use access modifiers in your class declarations.
*/

import java.io.*;

class Flower {
	String whatsYourName() {
		return "I have many names and types";
	}
};

class Jasmine extends Flower {
	@Override
	String whatsYourName() {
		return "Jasmine";
	}
};

class Lily extends Flower {
	@Override
	String whatsYourName() {
		return "Lily";
	}
};

class Region {
	Flower yourNationalFlower() {
		return new Flower();
	}
};

class WestBengal extends Region {
	@Override
	Flower yourNationalFlower() {
		return new Jasmine();
	}
};

class AndhraPradesh extends Region {
	@Override
	Flower yourNationalFlower() {
		return new Lily();
	}
};

public class Covariance {
	public static void main(String []args) {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		String s;
		try {
			s = reader.readLine().trim();
		} catch(Exception e) {
			s = "";
		}
		Region region = null;
		switch (s) {
		case "WestBengal":
			region = new WestBengal();
			break;
		case "AndraPradesh":
			region = new AndhraPradesh();
			break;
		default:
			region = new Region();
			break;
		}
		Flower flower = region.yourNationalFlower();
		System.out.println(flower.whatsYourName());
	}
};
