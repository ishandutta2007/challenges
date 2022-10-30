/*

NOTE FROM TRANSLATOR:

This code is a direct translation from the Python version of this challenge to a Java version. However, because of the differences between the languages and how they function, the Java code is much harder to understand

For example, the short, easy to read statment in Python int(userScore[:-1]) becomes Integer.parseInt(userScore.substring(0,userScore.length()) in Java.
END TRANSLATOR'S NOTE

Here is a trainwreck of a photo:

You FAILEDPASSED the Exam Required mark is 85% Your score 85%

The challenge is to fix all of the bugs in this incredibly messy code, which the code in the image might've actually looked like (probably not)! The code given will output the same middle two lines as in the image shown above.

    First parameter is the user's score.
    Second parameter is the required score.

Examples

grade_percentage("85%", "85%") ➞ "You PASSED the Exam"

grade_percentage("99%", "85%") ➞ "You PASSED the Exam"

grade_percentage("65%", "90%") ➞ "You FAILED the Exam"

Notes

    Note that inputs will be given as a string percentage number.
    Maintain all capitalization.
    Feel free to declutter and refactor code if it helps!

*/

package main

import "fmt"

func main() {
	test("85%", "85%", "You PASSED the Exam")
	test("99%", "85%", "You PASSED the Exam")
	test("65%", "90%", "You FAILED the Exam")
	test("65%", "66%", "You FAILED the Exam")
	test("5%", "5%", "You PASSED the Exam")
	test("5%", "6%", "You FAILED the Exam")
	test("9%", "5%", "You PASSED the Exam")
}

func test(u, r, p string) {
	assert(grade(u, r) == p)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func grade(u, r string) string {
	var x, y int
	n, _ := fmt.Sscanf(u, "%d", &x)
	m, _ := fmt.Sscanf(r, "%d", &y)
	if n != 1 || m != 1 {
		return "Invalid input grades"
	}
	if x >= y {
		return "You PASSED the Exam"
	}
	return "You FAILED the Exam"
}
