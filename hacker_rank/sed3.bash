#!/bin/bash

# Given an input file, in each line, highlight all the occurrences of 'thy' by wrapping them up in brace brackets.
# The search should be case-insensitive.
while read line
do
	echo $line | sed -e 's/\<thy\>/{&}/gI'
done
