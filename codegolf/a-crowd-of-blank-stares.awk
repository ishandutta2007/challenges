#!/usr/bin/env awk

# Problem
# 
# Given no input write a program or a function that outputs or returns the following string:
#
# (<(<>(<>.(<>.<(<>.<>(<>.<>)<>.<>)>.<>).<>)<>)>)
# Rules
#
#    Shortest program wins.
#    Trailing whitespace allowed.
#    Trailing newlines allowed.
#    Unused parameters for functions allowed.

BEGIN {
	print("(<(<>(<>.(<>.<(<>.<>(<>.<>)<>.<>)>.<>).<>)<>)>)");
}
