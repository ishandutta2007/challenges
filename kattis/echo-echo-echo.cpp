/*

If you have ever visited a canyon or a cave, you may have yelled and heard the echo of your own voice. In this problem, you should simulate that effect:
Hello! Hello! Hello!

Your program will be given as input a single word, and it should print out that word three times, separating the words with spaces.

As a refresher, here are some ways to read a single word from standard input (when the first line of input contains a single word), in a few different languages:

# Python 3
# input() reads a whole line, and strip() removes trailing whitespace/newline
word = input().strip()

// C++
// make sure to first "#include <iostream>"
std::string word;
std::cin >> word;

// Java
// make sure to first "import java.util.Scanner;"
Scanner s = new Scanner(System.in);
String word = s.next();

*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string word;
	cin >> word;
	cout << word << " " << word << " " << word << " " << endl;

	return 0;
}
