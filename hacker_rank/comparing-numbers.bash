#!/bin/bash

# Given two integers, X and Y, identify whether X < Y or X > Y or X = Y.
# Exactly one of the following lines: 
# - X is less than Y 
# - X is greater than Y 
#- X is equal to Y

function compare
{
	if [[ $# != 2 ]]
	then
		echo "invalid number of arguments"
		return
	fi

	if [[ $1 > $2 ]]
	then
		echo "X is greater than Y"
	elif [[ $1 == $2 ]]
	then
		echo "X is equal to Y"
	elif [[ $1 < $2 ]]
	then
		echo "X is less than Y"
	fi
}

compare 5 2
compare 2 2
compare 2 3
