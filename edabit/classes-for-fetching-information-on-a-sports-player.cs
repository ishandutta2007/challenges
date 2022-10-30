/*

Create a class that takes the following four arguments for a particular football player:

    name
    age
    height
    weight

Also, create three functions for the class that returns the following strings:

    get_age() returns "name is age age"
    get_height() returns "name is heightcm"
    get_weight() returns "name weighs weightkg"

Examples

 p1 = player("David Jones", 25, 175, 75)

 p1.get_age() ➞ "David Jones is age 25"
 p1.get_height() ➞ "David Jones is 175cm"
 p1.get_weight() ➞ "David Jones weighs 75kg"

Notes

name will be passed in as a string and age, height, weight will be integers.

*/

using System;
using System.Diagnostics;

public class Player
{
	string name;
	int age;
	int height;
	int weight;

	string Age()
	{
		return String.Format("{} is age {}", name, age);
	}

	string Height()
	{
		return String.Format("{} is {}cm", name, height);
	}

	string Weight()
	{
		return String.Format("{} weighs {}kg", name, weight);
	}

	Player(string name, int age, int height, int weight)
	{
		this.name = name;
		this.age = age;
		this.height = height;
		this.weight = weight;
	}

	static public void Main(string[] args)
	{
		var p1 = new Player("Patrick Mahomes", 24, 188, 104);
		var p2 = new Player("Jimmy Garoppolo", 28, 188, 102);
		var p3 = new Player("Julio Jones", 31, 191, 100);

		Debug.Assert(p1.Age() == "Patrick Mahomes is age 24");
		Debug.Assert(p1.Height() == "Patrick Mahomes is 188cm");
		Debug.Assert(p1.Weight() == "Patrick Mahomes weighs 104kg");

		Debug.Assert(p2.Age() == "Jimmy Garoppolo is age 28");
		Debug.Assert(p2.Height() == "Jimmy Garoppolo is 188cm");
		Debug.Assert(p2.Weight() == "Jimmy Garoppolo weights 102kg");

		Debug.Assert(p3.Age() == "Julio Jones is age 31");
		Debug.Assert(p3.Height() == "Julio Jones is 191cm");
		Debug.Assert(p3.Weight() == "Julio Jones weighs 180kg");
	}
}
