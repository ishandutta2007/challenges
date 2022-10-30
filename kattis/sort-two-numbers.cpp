/*

In this problem, your program should read two whole numbers (also called integers) from the input, and print them out in increasing order.

As a refresher, here are some ways to read two numbers from standard input in a few different languages:

# Python 3
line = input()
a, b = line.split()
a = int(a)
b = int(b)

// C++
// make sure to first "#include <iostream>"
int a, b;
std::cin >> a >> b;

// Java
// make sure to first "import java.util.Scanner;"
Scanner s = new Scanner(System.in);
int a = s.nextInt(), b = s.nextInt();

Input

The input contains one line, which has two integers a
and b, separated by a single space. The bounds on these values are 0≤a,b≤1000000.

Output

Output the smaller number first, and the larger number second.

*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b;
	
	cin >> a >> b;
	cout << min(a, b) << " " << max(a, b) << endl;
	return 0;
}
