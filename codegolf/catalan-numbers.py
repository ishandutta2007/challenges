#!/usr/bin/env python

"""

The Catalan numbers (OEIS) are a sequence of natural numbers often appearing in combinatorics.

The nth Catalan number is the number of Dyck words (balanced strings of parenthesis or brackets such as [[][]]; formally defined as a string using two characters a and b such that any substring starting from the beginning has number of a characters greater than or equal to number of b characters, and the entire string has the same number of a and b characters) with length 2n. The nth Catalan number (for n >= 0) is also explicitly defined as:

Starting from n = 0, the first 20 Catalan numbers are:

1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700, 1767263190...

Challenge

Write a full program or function that takes a non-negative integer n via STDIN or an acceptable alternative, and outputs the nth Catalan number. Your program must work at minimum for inputs 0-19.
I/O
Input

Your program must take input from STDIN, function arguments or any of the acceptable alternatives per this meta post. You can read the inputted number as its standard decimal represention, unary representation, or bytes.

    If (and only if) your language cannot take input from STDIN or any acceptable alternative, it may take input from a hardcoded variable or suitable equivalent in the program.

Output

Your program must output the nth Catalan number to STDOUT, function result or any of the acceptable alternatives per this meta post. You can output the Catalan number in its standard decimal representation, unary representation or bytes.

The output should consist of the approriate Catalan number, optionally followed by one or more newlines. No other output can be generated, except constant output of your language's interpreter that cannot be suppressed (such as a greeting, ANSI color codes or indentation).

This is not about finding the language that is the shortest. This is about finding the shortest program in every language. Therefore, I will not accept an answer.

In this challenge, languages newer than the challenge are acceptable as long as they have an implementation. It is allowed (and even encouraged) to write this interpreter yourself for a previously unimplemented language. Other than that, all the standard rules of code-golf must be obeyed. Submissions in most languages will be scored in bytes in an appropriate preexisting encoding (usually UTF-8). Note also that built-ins for calculating the nth Catalan number are allowed.
Catalog

The Stack Snippet at the bottom of this post generates the catalogue from the answers a) as a list of shortest solution per language and b) as an overall leaderboard.

To make sure that your answer shows up, please start your answer with a headline, using the following Markdown template:

## Language Name, N bytes

where N is the size of your submission. If you improve your score, you can keep old scores in the headline, by striking them through. For instance:

## Ruby, <s>104</s> <s>101</s> 96 bytes

If there you want to include multiple numbers in your header (e.g. because your score is the sum of two files or you want to list interpreter flag penalties separately), make sure that the actual score is the last number in the header:

## Perl, 43 + 2 (-p flag) = 45 bytes

You can also make the language name a link which will then show up in the snippet:

## [><>](http://esolangs.org/wiki/Fish), 121 bytes

"""

import math

def catalan(n):
    return math.comb(2*n, n) / (n+1)

def main():
    tab = [1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700, 1767263190]
    for i in range(len(tab)):
        assert(catalan(i) == tab[i])

main()
