#!/bin/bash

# Given two integers X and Y, find their sum, difference, product, and quotient

function number_world
{
	x=$1
	y=$2
	echo $((x + y))
	echo $((x - y))
	echo $((x * y))
	if [[ $y != 0 ]]
	then
		echo $((x / y))
	fi
}

number_world 5 2
