#!/bin/awk -f

# You are given a string. Output the string with one space per words.
# Challenge
#
# Input will be a string (not null or empty), surrounded with quotes(") sent via the stdin.
# Remove leading and trailing spaces from it. Also, if there are more than one space between two words (or symbols or whatever), trim it to just one space.
# Output the modified string with the quotes.
# Rules
#
#    The string will not be longer than 100 characters and will only contain ASCII characters in range (space) to ~(tilde) (character codes 0x20 to 0x7E, inclusive) except ",i.e, the string will not contain quotes(")
#    and other characters outside the range specified above. See ASCII table for reference.
#    You must take input from the stdin( or closest alternative ).
#    The output must contain quotes(").
#    You can write a full program, or a function which takes input (from stdin), and outputs the final string
#
# Test Cases
#
# "this  is  a    string   "         --> "this is a string"
#
# "  blah blah    blah "             --> "blah blah blah"
#
# "abcdefg"                          --> "abcdefg"
#
# "           "                      --> ""
#
# "12 34  ~5 6   (7, 8) - 9 -  "     --> "12 34 ~5 6 (7, 8) - 9 -"
#
# Scoring
# 
# This is code golf, so the shortest submission (in bytes) wins.

{
	gsub(/^[ \t]+|[ \t]+$/, "");
	print
}
