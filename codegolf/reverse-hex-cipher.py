#!/usr/bin/env python

"""

Characters in strings are sometimes represented as their ASCII hexadecimal codes. Printable characters have two hex digits in their representation. Swapping those digits leads to another character, which will be our output.

The table of relevant character codes can be found on Wikipedia.

Details
Take a string as input.
For each character:
Find corresponding hex value of ASCII code.
Swap (reverse) the hex digits.
Convert back to character.
Output the new string.

Rules
To make thinks easier, let's consider only characters "reversible" within standard printable ASCII range - that is codepoints (in hex): 22-27,32-37,42-47,52-57,62-67,72-77 or characters: "#$%&'234567BCDEFGRSTUVWbcdefgrstuvw.
Input and output should be strings or closest equivalent in your language of choice.
You may assume the input is non-empty.
This is code-golf, the usual rules apply.

Example

input: debug
hex codes: 64 65 62 75 67
reversed: 46 56 26 57 76
output: FV&Wv

Test cases
bcd <-> &6F
234 <-> #3C
screw <-> 76'Vw
debug <-> FV&Wv
BEEF <-> $TTd
7W66V77 <-> success
"#$%&'234567BCDEFGRSTUVWbcdefgrstuvw <-> "2BRbr#3CScs$4DTdt%5EUeu&6FVfv'7GWgw

"""

def rev(n):
    r = 0
    while n > 0:
        r = (r * 16) + (n % 16)
        n //= 16
    return chr(r)

def hexr(s):
    r = ""
    for c in s:
        r += rev(ord(c))
    return r

def main():
    assert(hexr("bcd") == "&6F")
    assert(hexr("234") == "#3C")
    assert(hexr("screw") == "76'Vw")
    assert(hexr("debug") == "FV&Wv")
    assert(hexr("BEEF") == "$TTd")
    assert(hexr("7W66V77") == "success")
    assert(hexr("\"#$%&'234567BCDEFGRSTUVWbcdefgrstuvw") == "\"2BRbr#3CScs$4DTdt%5EUeu&6FVfv'7GWgw")

main()
