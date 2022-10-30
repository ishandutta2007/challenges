#!/bin/awk -f

# It's strange this question hasn't been asked yet, so here it is:
#
# Calculate the length of a string given through STDIN
#
# Rules
# As said, your string will be given through STDIN, not via command line arguments
#
# Print the length of the string to STDOUT
#
# Only ASCII chars will be given, and all printable ASCII chars count!
#
# This is a code-golf, so the answer with the shortest length wins!
# Good Luck and have fun!

{
	print length($0);
}
