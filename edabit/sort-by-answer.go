/*

Given an array of math expressions, create a function which sorts the array by their answer. It should be sorted in ascending order.
Examples

sortByAnswer(["1 + 1", "1 + 7", "1 + 5", "1 + 4"]) ➞ ["1 + 1", "1 + 4", "1 + 5", "1 + 7"]

sortByAnswer(["4 - 4", "2 - 2", "5 - 5", "10 - 10"]) ➞ ["4 - 4", "2 - 2", "5 - 5", "10 - 10"]

sortByAnswer(["2 + 2", "2 - 2", "2 x 1"]) ➞ ["2 - 2", "2 x 1", "2 + 2"]

Notes

    If multiple expressions have the same answer, put them in the order of which they appear (see example #2).
    You won't need to worry about divisions by zero.

*/

package main

import (
	"fmt"
	"go/ast"
	"go/parser"
	"go/token"
	"sort"
	"strconv"
	"strings"
)

func main() {
	test([]string{"1 + 1", "1 + 7", "1 + 5", "1 + 4"}, []string{"1 + 1", "1 + 4", "1 + 5", "1 + 7"})
	test([]string{"2 + 2", "2 - 2", "2 x 2", "2 / 2"}, []string{"2 - 2", "2 / 2", "2 + 2", "2 x 2"})
	test([]string{"1 x 1", "3 x 3", "-1 x -1", "-3 x -3"}, []string{"1 x 1", "-1 x -1", "3 x 3", "-3 x -3"})
	test([]string{"4 - 4", "2 - 2", "5 - 5", "10 - 10"}, []string{"4 - 4", "2 - 2", "5 - 5", "10 - 10"})
	test([]string{"2 + 2", "2 - 2", "2 x 1"}, []string{"2 - 2", "2 x 1", "2 + 2"})
	test([]string{"4 - 4", "2 - 2", "5 + 5", "10 - 10"}, []string{"4 - 4", "2 - 2", "10 - 10", "5 + 5"})
	test([]string{"49 x -6", "21 - 25", "-11 / 26", "6 + -37", "1 / 49", "22 x -46", "-7 / 10", "16 + -34", "-37 x -27", "23 / -41"}, []string{"22 x -46", "49 x -6", "6 + -37", "16 + -34", "21 - 25", "-7 / 10", "23 / -41", "-11 / 26", "1 / 49", "-37 x -27"})
	test([]string{"18 / -13", "41 + -14", "6 x 19", "-7 x 3", "44 + 37", "-13 + -32", "47 + -15"}, []string{"-13 + -32", "-7 x 3", "18 / -13", "41 + -14", "47 + -15", "44 + 37", "6 x 19"})
	test([]string{"-45 - 30", "-6 / 21", "-31 x 40"}, []string{"-31 x 40", "-45 - 30", "-6 / 21"})
	test([]string{"4 + 13", "14 + 42", "-25 / 39", "-18 / 49", "34 + 41", "21 / -32", "3 / -17", "-38 + 38", "22 + 15", "-11 x 33", "-20 x -25", "3 / -28", "44 - 15", "26 / -29", "-23 - 43", "4 / 26", "8 + -45", "-4 + 28", "0 / 46", "8 x -9"}, []string{"-11 x 33", "8 x -9", "-23 - 43", "8 + -45", "26 / -29", "21 / -32", "-25 / 39", "-18 / 49", "3 / -17", "3 / -28", "-38 + 38", "0 / 46", "4 / 26", "4 + 13", "-4 + 28", "44 - 15", "22 + 15", "14 + 42", "34 + 41", "-20 x -25"})
	test([]string{"-42 - 47", "7 x 17", "-36 + -30"}, []string{"-42 - 47", "-36 + -30", "7 x 17"})
	test([]string{"-45 / 7", "44 - 49", "-17 x 49", "-22 + -40"}, []string{"-17 x 49", "-22 + -40", "-45 / 7", "44 - 49"})
	test([]string{"2 + -18", "-22 + 11", "-49 + -31", "32 / -20", "-10 x 5", "35 x -3"}, []string{"35 x -3", "-49 + -31", "-10 x 5", "2 + -18", "-22 + 11", "32 / -20"})
	test([]string{"-35 - 27", "38 - 41", "47 x -44", "-6 x -38"}, []string{"47 x -44", "-35 - 27", "38 - 41", "-6 x -38"})
	test([]string{"23 / 33", "-5 / 26", "36 + -1", "-35 / 26", "3 / 4", "-44 - 42", "-30 - 20", "-12 - 9", "33 - 23", "14 + 12", "-28 + 10", "14 + -24", "48 x -47", "35 x 47", "-28 x 9", "-26 + 2"}, []string{"48 x -47", "-28 x 9", "-44 - 42", "-30 - 20", "-26 + 2", "-12 - 9", "-28 + 10", "14 + -24", "-35 / 26", "-5 / 26", "23 / 33", "3 / 4", "33 - 23", "14 + 12", "36 + -1", "35 x 47"})
	test([]string{"-26 / -27", "31 / -5", "-20 / -39", "-41 x 37", "14 x 6", "-2 - 13", "-5 - 14", "22 + 45", "4 + 2", "35 + 43", "46 + -11", "19 / 45", "-27 + -43", "-30 + -10", "-6 x -36", "-2 - 37", "4 - 41", "27 / -30"}, []string{"-41 x 37", "-27 + -43", "-30 + -10", "-2 - 37", "4 - 41", "-5 - 14", "-2 - 13", "31 / -5", "27 / -30", "19 / 45", "-20 / -39", "-26 / -27", "4 + 2", "46 + -11", "22 + 45", "35 + 43", "14 x 6", "-6 x -36"})
	test([]string{"-5 / 25", "0 / 24", "-17 x 28", "-22 x 49"}, []string{"-22 x 49", "-17 x 28", "-5 / 25", "0 / 24"})
	test([]string{"-37 / -24", "-21 - 34", "40 x -7", "19 x 40", "-40 / -5"}, []string{"40 x -7", "-21 - 34", "-37 / -24", "-40 / -5", "19 x 40"})
	test([]string{"13 / 47", "31 - 27", "-47 - 46", "-1 / -1", "28 + -23", "-23 + 15", "34 / -8", "-36 + 25", "-24 x -26", "-12 + 33", "2 + 17", "-36 + 12"}, []string{"-47 - 46", "-36 + 12", "-36 + 25", "-23 + 15", "34 / -8", "13 / 47", "-1 / -1", "31 - 27", "28 + -23", "2 + 17", "-12 + 33", "-24 x -26"})
	test([]string{"31 x 21", "-31 x 4", "-48 x -20", "-26 x -36", "-38 - 18", "-42 / -42", "42 - 38"}, []string{"-31 x 4", "-38 - 18", "-42 / -42", "42 - 38", "31 x 21", "-26 x -36", "-48 x -20"})
	test([]string{"30 - 0", "23 x -31", "25 + 33", "42 + 5", "38 x 36", "22 / -23", "12 - 13", "47 x -48", "16 + -31"}, []string{"47 x -48", "23 x -31", "16 + -31", "12 - 13", "22 / -23", "30 - 0", "42 + 5", "25 + 33", "38 x 36"})
	test([]string{"33 / -38", "50 x 0", "-50 x -43", "-34 x -15", "-26 - 11", "2 / 26", "-17 x -47", "-34 x -36", "-14 / -46", "10 - 10", "25 + 4"}, []string{"-26 - 11", "33 / -38", "50 x 0", "10 - 10", "2 / 26", "-14 / -46", "25 + 4", "-34 x -15", "-17 x -47", "-34 x -36", "-50 x -43"})
	test([]string{"-24 / 27"}, []string{"-24 / 27"})
	test([]string{"41 - 41", "31 x -22", "-25 + -1", "-47 - 23", "-41 x 0"}, []string{"31 x -22", "-47 - 23", "-25 + -1", "41 - 41", "-41 x 0"})
	test([]string{"-19 + -6", "-44 + -20", "2 / 5", "39 - 5", "-43 x 23"}, []string{"-43 x 23", "-44 + -20", "-19 + -6", "2 / 5", "39 - 5"})
	test([]string{"1 + 6", "-11 + 31", "-15 - 32", "39 / -42", "38 / 6", "15 - 41"}, []string{"-15 - 32", "15 - 41", "39 / -42", "38 / 6", "1 + 6", "-11 + 31"})
	test([]string{"27 + -19", "43 + -33", "-5 - 9", "-44 x 27", "-2 / -22", "-18 / -32", "13 / 47", "-34 / 27", "0 - 42", "2 x 27", "9 x -15"}, []string{"-44 x 27", "9 x -15", "0 - 42", "-5 - 9", "-34 / 27", "-2 / -22", "13 / 47", "-18 / -32", "27 + -19", "43 + -33", "2 x 27"})
	test([]string{"23 / 31", "33 + 49", "-15 / -15", "0 / -5", "32 - 31", "37 / -38", "0 + 40", "-10 x 1", "-13 x 34", "32 - 32", "18 x 12", "15 x 2", "-33 - 3", "49 x -24", "-31 / 29", "-3 / 39"}, []string{"49 x -24", "-13 x 34", "-33 - 3", "-10 x 1", "-31 / 29", "37 / -38", "-3 / 39", "0 / -5", "32 - 32", "23 / 31", "-15 / -15", "32 - 31", "15 x 2", "0 + 40", "33 + 49", "18 x 12"})
	test([]string{"-6 - 24", "6 - 49", "15 - 8", "11 + 0", "44 - 49", "3 - 10", "45 + 16", "-37 x 6"}, []string{"-37 x 6", "6 - 49", "-6 - 24", "3 - 10", "44 - 49", "15 - 8", "11 + 0", "45 + 16"})
	test([]string{"-27 / 6", "-21 x -39", "-21 x 40", "-49 x -45", "39 / 43", "-37 x 45", "-36 + -11"}, []string{"-37 x 45", "-21 x 40", "-36 + -11", "-27 / 6", "39 / 43", "-21 x -39", "-49 x -45"})
	test([]string{"-8 / -8", "-27 / -6", "-31 - 43", "2 x -21", "7 x 49", "26 x 16", "-32 - 5", "-4 + -36", "-30 + 21", "-44 / 39", "-21 - 8", "30 - 20", "17 / -1", "-49 / 22", "-48 + 48"}, []string{"-31 - 43", "2 x -21", "-4 + -36", "-32 - 5", "-21 - 8", "17 / -1", "-30 + 21", "-49 / 22", "-44 / 39", "-48 + 48", "-8 / -8", "-27 / -6", "30 - 20", "7 x 49", "26 x 16"})
	test([]string{"48 + -49", "8 x 46", "-47 - 34", "17 + -41", "-40 + -28", "27 / 27", "22 - 44", "-32 / 27", "-27 / -11", "50 / 10", "38 + 32", "-1 x -10", "-15 + -29", "-9 - 37", "-42 x -43", "-19 x -21", "7 - 10", "-27 - 14", "-39 + -7", "20 - 45"}, []string{"-47 - 34", "-40 + -28", "-9 - 37", "-39 + -7", "-15 + -29", "-27 - 14", "20 - 45", "17 + -41", "22 - 44", "7 - 10", "-32 / 27", "48 + -49", "27 / 27", "-27 / -11", "50 / 10", "-1 x -10", "38 + 32", "8 x 46", "-19 x -21", "-42 x -43"})
	test([]string{"35 / 23", "-27 + -26", "1 - 39", "42 / 45", "-35 - 37", "-34 x -11"}, []string{"-35 - 37", "-27 + -26", "1 - 39", "42 / 45", "35 / 23", "-34 x -11"})
	test([]string{"-33 + -6", "-9 x -1", "43 + 18", "-12 - 44", "-27 x 49", "42 + 17", "34 + 17"}, []string{"-27 x 49", "-12 - 44", "-33 + -6", "-9 x -1", "34 + 17", "42 + 17", "43 + 18"})
	test([]string{"-1 / 12", "21 + 19", "6 + 22", "7 - 1", "-29 x 1", "-46 / 26", "1 x 50", "12 + 18", "8 + 40", "-23 - 34", "-12 x -28", "-19 + -17", "34 + 22", "3 / -32", "0 / -9", "-39 - 37", "-39 + 26"}, []string{"-39 - 37", "-23 - 34", "-19 + -17", "-29 x 1", "-39 + 26", "-46 / 26", "3 / -32", "-1 / 12", "0 / -9", "7 - 1", "6 + 22", "12 + 18", "21 + 19", "8 + 40", "1 x 50", "34 + 22", "-12 x -28"})
	test([]string{"11 + -17", "14 / -1", "19 - 48", "-5 - 33", "37 / 3", "-47 + 47", "24 - 37", "-18 / -6", "22 + 3", "41 x 31", "-13 - 1", "-26 + 41", "-12 - 36", "-32 + 7", "-28 / -15", "-50 / -35"}, []string{"-12 - 36", "-5 - 33", "19 - 48", "-32 + 7", "14 / -1", "-13 - 1", "24 - 37", "11 + -17", "-47 + 47", "-50 / -35", "-28 / -15", "-18 / -6", "37 / 3", "-26 + 41", "22 + 3", "41 x 31"})
	test([]string{"7 / -29", "-46 x -9", "-44 / 35", "-38 + 31", "-12 + 39", "-35 + 6", "41 + 20", "-24 - 20", "33 - 2", "18 - 14", "-18 + 33", "23 x -14", "-31 - 33", "22 + 31", "-35 + -36", "35 + 25", "-19 / 22"}, []string{"23 x -14", "-35 + -36", "-31 - 33", "-24 - 20", "-35 + 6", "-38 + 31", "-44 / 35", "-19 / 22", "7 / -29", "18 - 14", "-18 + 33", "-12 + 39", "33 - 2", "22 + 31", "35 + 25", "41 + 20", "-46 x -9"})
	test([]string{"3 / -10", "36 x -10", "32 - 26", "21 + 49", "11 - 30", "-10 - 38", "-4 - 37", "-8 - 46", "-50 x 31", "29 x 23", "-15 / 9", "-10 + 22", "15 + -36", "40 + -28", "41 x 18", "-36 + -32", "27 / -47", "34 x -4"}, []string{"-50 x 31", "36 x -10", "34 x -4", "-36 + -32", "-8 - 46", "-10 - 38", "-4 - 37", "15 + -36", "11 - 30", "-15 / 9", "27 / -47", "3 / -10", "32 - 26", "-10 + 22", "40 + -28", "21 + 49", "29 x 23", "41 x 18"})
	test([]string{"-38 - 19", "1 / -46", "5 x -1", "-43 / -33", "-41 / -33", "-50 x 35", "2 / -26", "29 / -47", "14 - 1", "8 + 44", "6 / -10", "6 - 42", "-4 / 49", "-3 x 46", "13 / -19", "-24 / -35", "9 / -25", "-1 x 42", "36 x -24"}, []string{"-50 x 35", "36 x -24", "-3 x 46", "-38 - 19", "-1 x 42", "6 - 42", "5 x -1", "13 / -19", "29 / -47", "6 / -10", "9 / -25", "-4 / 49", "2 / -26", "1 / -46", "-24 / -35", "-41 / -33", "-43 / -33", "14 - 1", "8 + 44"})
	test([]string{"-33 - 13", "21 - 10", "19 x -20", "-39 x -1", "-21 x -13", "5 + 36", "7 - 11", "-19 - 22", "-28 + 49", "11 - 38", "26 x -48", "-22 / 17", "-13 / 33"}, []string{"26 x -48", "19 x -20", "-33 - 13", "-19 - 22", "11 - 38", "7 - 11", "-22 / 17", "-13 / 33", "21 - 10", "-28 + 49", "-39 x -1", "5 + 36", "-21 x -13"})
	test([]string{"-31 - 24", "31 x -28", "-41 - 32", "-8 - 32", "-6 / 40", "26 - 0", "-26 x -4", "21 + 11", "2 x -36", "42 x 34", "-34 x 40", "-8 - 33"}, []string{"-34 x 40", "31 x -28", "-41 - 32", "2 x -36", "-31 - 24", "-8 - 33", "-8 - 32", "-6 / 40", "26 - 0", "21 + 11", "-26 x -4", "42 x 34"})
	test([]string{"30 x 14"}, []string{"30 x 14"})
	test([]string{"-41 + 45", "42 + -48", "34 - 8", "-45 + 41", "-46 + 21"}, []string{"-46 + 21", "42 + -48", "-45 + 41", "-41 + 45", "34 - 8"})
	test([]string{"-35 - 48", "21 - 45", "-10 x -13", "-42 + 39", "-49 x -17", "-1 / 20", "-19 x -23", "-25 x -37", "44 + -3", "-27 - 3", "-46 / 31", "-24 - 2", "-15 - 10", "-14 + -31", "-6 / 30", "-43 - 27", "-45 x 39", "-36 / 28", "-23 + -6", "46 + -18"}, []string{"-45 x 39", "-35 - 48", "-43 - 27", "-14 + -31", "-27 - 3", "-23 + -6", "-24 - 2", "-15 - 10", "21 - 45", "-42 + 39", "-46 / 31", "-36 / 28", "-6 / 30", "-1 / 20", "46 + -18", "44 + -3", "-10 x -13", "-19 x -23", "-49 x -17", "-25 x -37"})
	test([]string{"-20 / -24", "-25 + -18", "41 - 20", "-19 x -13", "-48 / -18", "-40 - 38", "-33 + -37"}, []string{"-40 - 38", "-33 + -37", "-25 + -18", "-20 / -24", "-48 / -18", "41 - 20", "-19 x -13"})
	test([]string{"36 + 46", "-15 - 23", "-40 x -39", "43 / 1", "21 x 20", "49 x -22", "-48 / 12", "-32 x -4", "22 x 49", "34 / -13", "-21 - 15", "-36 + 19", "-42 + 40", "-31 x -12", "37 x 22", "-3 + 33", "19 - 29", "22 / -34", "-19 / 39"}, []string{"49 x -22", "-15 - 23", "-21 - 15", "-36 + 19", "19 - 29", "-48 / 12", "34 / -13", "-42 + 40", "22 / -34", "-19 / 39", "-3 + 33", "43 / 1", "36 + 46", "-32 x -4", "-31 x -12", "21 x 20", "37 x 22", "22 x 49", "-40 x -39"})
	test([]string{"31 / 8", "-16 - 28", "49 / -11", "-14 x -50", "-25 - 9", "-30 + 9", "20 x 4", "-48 / 39", "46 x 20", "-25 - 47", "40 + -30", "-37 - 3", "-41 / -3"}, []string{"-25 - 47", "-16 - 28", "-37 - 3", "-25 - 9", "-30 + 9", "49 / -11", "-48 / 39", "31 / 8", "40 + -30", "-41 / -3", "20 x 4", "-14 x -50", "46 x 20"})
	test([]string{"22 x 42", "-41 / -8", "-46 - 47", "25 x 50", "21 / -35", "3 + -36", "-9 x 3", "39 - 26", "13 - 24", "-22 - 39", "5 - 40", "-47 + -29", "-17 / -16", "29 / 14", "24 / 6", "-17 - 23"}, []string{"-46 - 47", "-47 + -29", "-22 - 39", "-17 - 23", "5 - 40", "3 + -36", "-9 x 3", "13 - 24", "21 / -35", "-17 / -16", "29 / 14", "24 / 6", "-41 / -8", "39 - 26", "22 x 42", "25 x 50"})
	test([]string{"37 x 14", "33 - 16"}, []string{"33 - 16", "37 x 14"})
	test([]string{"-15 + 37", "26 / 5", "1 - 8", "-2 - 49", "-41 - 12", "17 - 7", "-15 - 24", "34 - 7", "-9 - 17"}, []string{"-41 - 12", "-2 - 49", "-15 - 24", "-9 - 17", "1 - 8", "26 / 5", "17 - 7", "-15 + 37", "34 - 7"})
	test([]string{"30 / 48", "-32 / 18", "-41 - 49", "41 / 13", "0 / 26", "-41 / 38", "-9 + 18", "25 + -1"}, []string{"-41 - 49", "-32 / 18", "-41 / 38", "0 / 26", "30 / 48", "41 / 13", "-9 + 18", "25 + -1"})
	test([]string{"20 - 36", "-14 / 6", "4 - 32", "39 x 36", "29 / 32", "-38 / -23", "9 x 30", "-27 + -2", "-8 + -8", "9 + 37"}, []string{"-27 + -2", "4 - 32", "20 - 36", "-8 + -8", "-14 / 6", "29 / 32", "-38 / -23", "9 + 37", "9 x 30", "39 x 36"})
	test([]string{"-24 / -16", "22 / -26", "-35 x -17", "31 - 50", "-41 x 50", "-50 + -5", "-47 / 12", "13 / -48", "22 x -3", "27 + 37", "8 - 18", "8 / -48", "-17 / -37", "-18 + -34", "-17 + -22", "-25 x 47", "-4 - 45", "-50 - 5", "-28 x 19", "-23 + -28"}, []string{"-41 x 50", "-25 x 47", "-28 x 19", "22 x -3", "-50 + -5", "-50 - 5", "-18 + -34", "-23 + -28", "-4 - 45", "-17 + -22", "31 - 50", "8 - 18", "-47 / 12", "22 / -26", "13 / -48", "8 / -48", "-17 / -37", "-24 / -16", "27 + 37", "-35 x -17"})
	test([]string{"27 - 2", "-34 x -21", "-49 / 41", "-3 / -6", "-11 / 6", "-30 / 29", "4 + 39", "-5 + 43", "12 + -33", "-34 + 3", "-2 - 45", "10 / -36"}, []string{"-2 - 45", "-34 + 3", "12 + -33", "-11 / 6", "-49 / 41", "-30 / 29", "10 / -36", "-3 / -6", "27 - 2", "-5 + 43", "4 + 39", "-34 x -21"})
	test([]string{"-28 - 45", "-10 x 33", "0 + -10", "-26 / 38", "-23 - 36", "-7 / -22"}, []string{"-10 x 33", "-28 - 45", "-23 - 36", "0 + -10", "-26 / 38", "-7 / -22"})
	test([]string{"-50 / 1", "3 / 32", "-46 + -37", "4 / -4", "-44 - 50", "12 / -19", "-11 / 37", "-7 + 37", "-15 / -10", "-31 + 8"}, []string{"-44 - 50", "-46 + -37", "-50 / 1", "-31 + 8", "4 / -4", "12 / -19", "-11 / 37", "3 / 32", "-15 / -10", "-7 + 37"})
}

func test(s, t []string) {
	s, err := sortbyanswer(s)
	assert(err == nil)
	for i := range s {
		assert(s[i] == t[i])
	}
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func sortbyanswer(s []string) ([]string, error) {
	m := make(map[string]float64)
	for _, s := range s {
		v, err := eval(s)
		if err != nil {
			return nil, err
		}
		m[s] = v
	}
	sort.SliceStable(s, func(i, j int) bool {
		return m[s[i]] < m[s[j]]
	})
	return s, nil
}

func eval(s string) (float64, error) {
	s = strings.Replace(s, "x", "*", -1)
	e, err := parser.ParseExpr(s)
	if err != nil {
		return 0, err
	}
	return walk(e)
}

func walk(e ast.Expr) (float64, error) {
eval:
	switch e := e.(type) {
	case *ast.BasicLit:
		switch e.Kind {
		case token.INT:
			return strconv.ParseFloat(e.Value, 64)
		}

	case *ast.BinaryExpr:
		x, xe := walk(e.X)
		y, ye := walk(e.Y)
		if xe != nil || ye != nil {
			break eval
		}

		switch e.Op {
		case token.ADD:
			return x + y, nil
		case token.SUB:
			return x - y, nil
		case token.MUL:
			return x * y, nil
		case token.QUO:
			if y == 0 {
				break eval
			}
			return x / y, nil
		}

	case *ast.UnaryExpr:
		x, err := walk(e.X)
		if err != nil {
			break eval
		}

		switch e.Op {
		case token.ADD:
			return x, nil
		case token.SUB:
			return -x, nil
		}
	}

	return 0, fmt.Errorf("invalid expression")
}
