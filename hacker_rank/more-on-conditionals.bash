#!/bin/bash

# Given three integers (X, Y, and Z) representing the three sides of a triangle,
# identify whether the triangle is Scalene, Isosceles, or Equilateral.

function triangle_type()
{
	if [[ $1 == $2 ]] && [[ $2 == $3 ]]
	then
		echo "EQUILATERAL"
	elif [[ $1 == $2 ]] || [[ $1 == $3 ]] || [[ $2 == $3 ]]
	then
		echo "ISOCELES"
	else
		echo "SCALENE"
	fi
}

triangle_type 2 3 4
triangle_type 3 3 3
triangle_type 1 1 2
