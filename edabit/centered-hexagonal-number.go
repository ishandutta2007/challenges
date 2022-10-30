/*

As stated on the On-Line Encyclopedia of Integer Sequences:

    The hexagonal lattice is the familiar 2-dimensional lattice in which each point has 6 neighbors.

A centered hexagonal number is a centered figurate number that represents a hexagon with a dot in the center and all other dots surrounding the center dot in a hexagonal lattice.

At the end of that web page the following illustration is shown:

Illustration of initial terms:
.
.                                 o o o o
.                   o o o        o o o o o
.         o o      o o o o      o o o o o o
.   o    o o o    o o o o o    o o o o o o o
.         o o      o o o o      o o o o o o
.                   o o o        o o o o o
.                                 o o o o
.
.   1      7          19             37
.

Write a function that takes an integer n and returns "Invalid" if n is not a centered hexagonal number or its illustration as a multiline rectangular string otherwise.
Examples

hex_lattice(1) ➞ " o "
# o

hex_lattice(7) ➞ "  o o  \n o o o \n  o o  "
#  o o
# o o o
#  o o

hex_lattice(19) ➞ "   o o o   \n  o o o o  \n o o o o o \n  o o o o  \n   o o o   "
#   o o o
#  o o o o
# o o o o o
#  o o o o
#   o o o

hex_lattice(21) ➞ "Invalid"

Notes

N/A

*/

package main

import (
	"bytes"
	"fmt"
	"math"
	"strings"
)

func main() {
	test(1, " o ")
	test(2, "Invalid")
	test(4, "Invalid")
	test(6, "Invalid")
	test(7, "  o o  \n o o o \n  o o  ")
	test(10, "Invalid")
	test(18, "Invalid")
	test(19, "   o o o   \n  o o o o  \n o o o o o \n  o o o o  \n   o o o   ")
	test(37, "    o o o o    \n   o o o o o   \n  o o o o o o  \n o o o o o o o \n  o o o o o o  \n   o o o o o   \n    o o o o    ")
	test(45, "Invalid")
	test(1387, "                      o o o o o o o o o o o o o o o o o o o o o o                      \n                     o o o o o o o o o o o o o o o o o o o o o o o                     \n                    o o o o o o o o o o o o o o o o o o o o o o o o                    \n                   o o o o o o o o o o o o o o o o o o o o o o o o o                   \n                  o o o o o o o o o o o o o o o o o o o o o o o o o o                  \n                 o o o o o o o o o o o o o o o o o o o o o o o o o o o                 \n                o o o o o o o o o o o o o o o o o o o o o o o o o o o o                \n               o o o o o o o o o o o o o o o o o o o o o o o o o o o o o               \n              o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o              \n             o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o             \n            o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o            \n           o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o           \n          o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o          \n         o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o         \n        o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o        \n       o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o       \n      o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o      \n     o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o     \n    o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o    \n   o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o   \n  o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o  \n o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o \n  o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o  \n   o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o   \n    o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o    \n     o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o     \n      o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o      \n       o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o       \n        o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o        \n         o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o         \n          o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o          \n           o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o           \n            o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o            \n             o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o             \n              o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o              \n               o o o o o o o o o o o o o o o o o o o o o o o o o o o o o               \n                o o o o o o o o o o o o o o o o o o o o o o o o o o o o                \n                 o o o o o o o o o o o o o o o o o o o o o o o o o o o                 \n                  o o o o o o o o o o o o o o o o o o o o o o o o o o                  \n                   o o o o o o o o o o o o o o o o o o o o o o o o o                   \n                    o o o o o o o o o o o o o o o o o o o o o o o o                    \n                     o o o o o o o o o o o o o o o o o o o o o o o                     \n                      o o o o o o o o o o o o o o o o o o o o o o                      ")
	test(1500, "Invalid")
	test(6487, "                                               o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                               \n                                              o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                              \n                                             o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                             \n                                            o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                            \n                                           o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                           \n                                          o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                          \n                                         o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                         \n                                        o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                        \n                                       o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                       \n                                      o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                      \n                                     o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                     \n                                    o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                    \n                                   o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                   \n                                  o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                  \n                                 o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                 \n                                o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                \n                               o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                               \n                              o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                              \n                             o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                             \n                            o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                            \n                           o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                           \n                          o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                          \n                         o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                         \n                        o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                        \n                       o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                       \n                      o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                      \n                     o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                     \n                    o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                    \n                   o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                   \n                  o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                  \n                 o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                 \n                o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                \n               o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o               \n              o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o              \n             o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o             \n            o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o            \n           o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o           \n          o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o          \n         o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o         \n        o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o        \n       o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o       \n      o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o      \n     o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o     \n    o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o    \n   o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o   \n  o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o  \n o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o \n  o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o  \n   o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o   \n    o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o    \n     o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o     \n      o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o      \n       o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o       \n        o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o        \n         o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o         \n          o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o          \n           o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o           \n            o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o            \n             o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o             \n              o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o              \n               o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o               \n                o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                \n                 o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                 \n                  o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                  \n                   o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                   \n                    o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                    \n                     o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                     \n                      o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                      \n                       o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                       \n                        o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                        \n                         o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                         \n                          o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                          \n                           o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                           \n                            o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                            \n                             o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                             \n                              o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                              \n                               o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                               \n                                o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                \n                                 o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                 \n                                  o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                  \n                                   o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                   \n                                    o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                    \n                                     o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                     \n                                      o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                      \n                                       o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                       \n                                        o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                        \n                                         o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                         \n                                          o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                          \n                                           o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                           \n                                            o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                            \n                                             o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                             \n                                              o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                              \n                                               o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o o                                               ")
	test(7777, "Invalid")
}

func test(n int, r string) {
	p := hexlattice(n)
	fmt.Println(n)
	fmt.Println(p)
	fmt.Println()
	assert(p == r)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

// https://oeis.org/A003215
func hexlattice(n int) string {
	r, f := quadratic(3, 3, float64(1-n))
	x := int(r[0])
	if !f || 3*x*(x+1)+1 != n {
		return "Invalid"
	}

	w := new(bytes.Buffer)
	for i := -x; i <= x; i++ {
		j := 2*x + 1 - abs(i)

		fmt.Fprintf(w, strings.Repeat(" ", 2*x+2-j))
		for k := 0; k < j; k++ {
			fmt.Fprintf(w, "o")
			if k+1 < j {
				fmt.Fprintf(w, " ")
			}
		}
		fmt.Fprintf(w, strings.Repeat(" ", 2*x+2-j))
		fmt.Fprintf(w, "\n")
	}
	s := w.String()
	return s[:len(s)-1]
}

func quadratic(a, b, c float64) ([2]float64, bool) {
	var r [2]float64
	d := b*b - 4*a*c
	if d < 0 {
		return r, false
	}

	s := math.Sqrt(d)
	r[0] = (-b + s) / (2 * a)
	r[1] = (-b - s) / (2 * a)
	return r, true
}

func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
}
