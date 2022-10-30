#!/bin/awk -f

# Write a script that outputs A to stdout infinitely.
# There shold be no newlines or seperators between the characters
# Standard loopholes apply
# This is code-golf. The shortest solution in each language wins.

BEGIN {
	while (1)
		printf "A";
}
