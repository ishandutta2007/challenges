#!/bin/bash
# Given a list of countries, each on a new line, your task is to read them into an array.
# Then, concatenate the array with itself (twice) - 
# so that you have a total of three repetitions of the original array -
# and then display the entire concatenated array, with a space between each of the countries' names.

readarray -t values
values=( "${values[@]}" "${values[@]}" "${values[@]}" )
echo ${values[@]}
