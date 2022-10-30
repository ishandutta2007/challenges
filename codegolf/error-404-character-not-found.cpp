/*

Scenario
One of your friends is struggling on a homework assignment. He needs a simple program which prints the first 404 natural numbers:

1 2 3 4 5 6 7 8 9 10 11 ... 401 402 403 404
Your challenge is simple: write this program for him.

However, your connection is terrible, so 1 random character is lost every time you send the program.
To prevent this from breaking your program, you must make it so that removing any single character will have no effect: the program works, regardless.
(The original program must also work.)

Because the connection is too poor to send large files, your code must be as short as possible.

TL:DR - make a radiation hardened program to output the numbers 1 to 404

Rules/Details
The output may be a list of integers in any reasonable format (separated by spaces, newlines, commas, etc). However, your output must be consistent and not change when the program is modified.
Command line flags that contain logic, execute actual code, generate the number list, and so on, are banned.
This is code-golf, so the shortest submission (in bytes) wins!

*/

#include <iostream>

using namespace std;

int main()
{
	for (auto i = 1; i <= 404; i++)
		cout << i << endl;

	return 0;
}
