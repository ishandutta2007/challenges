/*

The goal is to create the Stack Overflow logo using ASCII characters.

It looks like this.

Stack Overflow

The exact output should look like this:

        \\
          \\
     \=    \\
       \=    \\
         \=   \\
           \==  \\
    ¯¯¯       \==
       ¯¯¯¯¯
   _______  ¯¯¯¯
          ____
| ____________ |
|              |
¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

It must be worth mentioning that it must represent the same form of the actual logo, wherein the lines' (which I would call sticks) layering should be aligned as the way of the one from the picture.
You can use either spaces or newlines to add another line for drawing the logo.

Remember, 5 sticks facing different angles and 1 tray holding them.

Can you draw it with the least bytes possible?

*/

#include <iostream>

using namespace std;

auto logo = R"(
        \\
          \\
     \=    \\
       \=    \\
         \=   \\
           \==  \\
    ¯¯¯       \==
       ¯¯¯¯¯
   _______  ¯¯¯¯
          ____
| ____________ |
|              |
¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
)";

int main()
{
	cout << logo << endl;
	return 0;
}
