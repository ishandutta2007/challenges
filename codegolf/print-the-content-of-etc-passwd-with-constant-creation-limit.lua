#!/usr/bin/env lua

--[[

Rules/Objectives:

The program must be executed using ./program-name without shell parameter/arguments.

the program-name may not contain any of characters in /etc/passwd, that is acdepstw

You may not open any other file, including own's source code, only /etc/passwd that should be read.

The program must print the content the /etc/passwd file.

Total score of the code equal to number of characters in the code added with constant literal declaration point.
Each byte of constant declaration literal equal to +100 to the score, after 3 declaration, each byte adds +200 to the score.
So the program should not contain too many constant declaration, but you may use predeclared constants (M_PI for example) or exploit the reflection of the function/variable/class name (function, variable or class names in this case are not considered as constant).
Counting example:

int x = 12;       // counted as 1 byte (12 can fit to 8-bit)
x += 345;         // counted as 2 bytes (345 can fit to 16-bit)
#define Y 'e'     // counted as 1 byte ('e')
#define X Y       // counted as 0 (not considered as constant)
string s = "abc"; // counted as 3 bytes ("abc")
:foo              // counted as 3 bytes (:foo)
                  //  ^ EACH characters in atom (Elixir, etc)
                  //    or characters in symbol (Ruby, etc)
                  //    are counted as 1 byte constant
''                // counted as 0 (not considered as constant)
[0xAC, 12, 114]   // counted as 3 bytes (0xAC, 12, 114)
Clarification:

things that counted as constant literal:

numbers, each byte, depends on size
strings/symbols, each character = 1 byte
chars, one byte
things that not counted as constant literal:

class declaration
function declaration
variable declaration
operators, brackets
predefined symbols
predefined constants

--]]

for line in io.lines("/etc/passwd") do
	print(line)
end
