/*

The Illuminati commands you (with their mind control) to output the following string:

         ^
        /_\
       /_|_\
      /_|_|_\
     /_|/o\|_\
    /_|_\_/_|_\
   /_|_|_|_|_|_\
  /_|_|_|_|_|_|_\
 /_|_|_|_|_|_|_|_\
/_|_|_|_|_|_|_|_|_\

Rules:

    Trailing spaces are allowed for each line.
    Leading spaces in each line are required.
    Trailing whitespace is allowed after the full required output.
    Since this is a code-golf challenge, the winner shall be the shortest program in bytes.
    Since this is a kolmogorov-complexity challenge, hardcoded output is allowed.
    Standard Loopholes apply.
    Update: You may use tabs instead of spaces, with each tab counting as 4 spaces. If you want for some reason.

*/

#include <iostream>

using namespace std;

int main()
{
	static auto text = R"(
         ^
        /_\
       /_|_\
      /_|_|_\
     /_|/o\|_\
    /_|_\_/_|_\
   /_|_|_|_|_|_\
  /_|_|_|_|_|_|_\
 /_|_|_|_|_|_|_|_\
/_|_|_|_|_|_|_|_|_\
)";

	cout << text << endl;
	return 0;
}
