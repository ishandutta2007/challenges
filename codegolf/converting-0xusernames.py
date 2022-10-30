#!/usr/bin/env python

"""

0xUsernames

There's so many people using a messaging service that they're running out of space to store all the usernames! To fix this, they are going to start storing usernames as hexadecimal, where possible.

If a username consists of only the characters 0123456789ABCDEF (case insensitive), it can be converted to a hexadecimal and stored as an integer. For example, the username ba5eba11 can be interpreted as 0xBA5EBA11, a hexadecimal integer.

But what about 05AB1E? That's got a leading zero, which would be lost. So, whenever we convert a username, we make sure to prepend a 1 before reading it as an integer.

The Challenge
Your task is to write a program or function which, given a non-empty username as a string, 'hexa-compresses' the username:

If it can be interpreted as a hexadecimal integer, prepend a 1, interpret as hexadecimal, and then print the result as base 10.
Otherwise, just return the string unmodified.
This is code-golf, so the shortest solution (in bytes) wins! Built-in base conversion functions are permitted.

Test Cases
You can assume that any resulting integers with be within your language's standard integer range.

As with usernames on most messaging systems, the input strings will only contain alphanumerics and underscores.

Remember, you always need to add a leading 1 before conversion!

"ba5eba11" -> 7421737489
"05AB1E"   -> 17148702
"dec0de"   -> 31375582
"Beef"     -> 114415
"da7aba5e" -> 7960443486
"500"      -> 5376

"DENNIS" -> "DENNIS"
"Garth"  -> "Garth"
"A_B_C"  -> "A_B_C"
"0x000"  -> "0x000"
For reference, here is a Python 3 implementation I used for the test cases (ungolfed):

import re

def convert_name(name):
    if re.fullmatch('^[0-9A-Fa-f]+$', name):
        return int('1' + name.upper(), base = 16)
    else:
        return name

"""

import re

def convert(name):
    if re.fullmatch('^[0-9A-Fa-f]+$', name):
        return int('1' + name.upper(), base=16)
    return name

def main():
    assert(convert("ba5eba11") == 7421737489)
    assert(convert("05AB1E") == 17148702)
    assert(convert("dec0de") == 31375582)
    assert(convert("Beef") == 114415)
    assert(convert("da7aba5e") == 7960443486)
    assert(convert("500") == 5376)

    assert(convert("DENNIS") == "DENNIS")
    assert(convert("Garth") == "Garth")
    assert(convert("A_B_C") == "A_B_C")
    assert(convert("0x000") == "0x000")

main()
