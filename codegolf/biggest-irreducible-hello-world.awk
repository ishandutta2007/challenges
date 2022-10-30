#!/usr/bin/awk -f

# Create a program that outputs Hello, World!
#
# The winner is the source code that is the biggest, subject to the constraint that it is irreducible
#
# For this challenge, irreducible means there does not exist a program that outputs Hello, World! that can be constructed by removing characters from the original program.
#
# For example
#
# console.log(`Hello, ` + `World!`);
#
# can have the the bracketed characters removed
#
# console.log(`Hello, [` + `]World!`)[;] -> console.log(`Hello, World!`)
#
# And it will still output Hello, World, so it is not irreducible.
#
# Extra Rules:
#
#    Whitespace is ignored with regards to both irreducibility and size.
#    Unary or anything that operates in a similar fashion (I'll make this more clear if I have to) is banned.

BEGIN {
	print "Hello, World!";
}
