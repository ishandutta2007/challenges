/*

Objective

Given a string with single Unicode vulgar fraction, parse it to a rational number.
Valid inputs

A valid input is one of:

    ¼ U+00BC; one quarter

    ½ U+00BD; one half

    ¾ U+00BE; three quarters

    ⅐ U+2150; one seventh

    ⅑ U+2151; one ninth

    ⅒ U+2152; one tenth

    ⅓ U+2153; one third

    ⅔ U+2154; two thirds

    ⅕ U+2155; one fifth

    ⅖ U+2156; two fifths

    ⅗ U+2157; three fifths

    ⅘ U+2158; four fifths

    ⅙ U+2159; one sixth

    ⅚ U+215A; five sixths

    ⅛ U+215B; one eighth

    ⅜ U+215C; three eighths

    ⅝ U+215D; five eighths

    ⅞ U+215E; seven eighths

    ⅟ (U+215F; fraction numerator one) followed by ASCII decimal digits (U+0030 – U+0039)

    ASCII decimal digits followed by ⁄(U+2044; fraction slash) followed by ASCII decimal digits

There are exceptions. See below.
Invalid inputs

If the denominator is zero, the parser must fall in an erroneous state. This includes:

    Monadic failing

    Returning an erroneous value

    Throwing an error

Rules

    Encoding of the input doesn't matter.

    Output type and format doesn't matter either. Though native rational number type is preferred, a pair of integers is permitted.

    Inputs that are neither valid nor invalid fall in don't care situation. This includes:

        Whole numbers

        Improper fractions

        Reducible fractions

        Fractions with zero numerator

        Negative fractions

Examples

⅛ (U+215B) parses to one eighth.

⅟13 (U+215F U+0031 U+0033) parses to one thirteenth.

24⁄247 (U+0032 U+0034 U+2044 U+0032 U+0034 U+0037) parses to twenty-four 247ths.

1⁄7 (U+0031 U+2044 U+0037) parses to one seventh. Note that ⅐ and ⅟7 will parse to the same.

0 (U+0030) falls in don't care situation. It's a whole number.

9⁄8 (U+0039 U+2044 U+0038) falls in don't care situation. It's an improper fraction.

4⁄8 (U+0034 U+2044 U+0038) falls in don't care situation. It's reducible to one half.

↉ (U+2189) falls in don't care situation. Its numerator is zero.

-½ (U+002D U+00BD) falls in don't care situation. It is negative.

1⁄0 (U+0031 U+2044 U+0030) must make the parser be in erroneous state. Its denominator is zero.
Ungolfed solution
Haskell

import Control.Monad
import Data.Ratio
import Text.ParserCombinators.ReadP as ReadP
import Text.Read
import Text.Read.Lex

fractionParser :: ReadP Rational
fractionParser = choice [
    char '¼' >> return (1 % 4),
    char '½' >> return (1 % 2),
    char '¾' >> return (3 % 4),
    char '⅐' >> return (1 % 7),
    char '⅑' >> return (1 % 9),
    char '⅒' >> return (1 % 10),
    char '⅓' >> return (1 % 3),
    char '⅔' >> return (2 % 3),
    char '⅕' >> return (1 % 5),
    char '⅖' >> return (2 % 5),
    char '⅗' >> return (3 % 5),
    char '⅘' >> return (4 % 5),
    char '⅙' >> return (1 % 6),
    char '⅚' >> return (5 % 6),
    char '⅛' >> return (1 % 8),
    char '⅜' >> return (3 % 8),
    char '⅝' >> return (5 % 8),
    char '⅞' >> return (7 % 8),
    char '⅟' >> do
        d <- readDecP
        guard (0 /= d)
        return (1 % d),
    do
        n <- readDecP
        char '⁄'
        d <- readDecP
        guard (0 /= d)
        return (n % d)
    ]

*/

package main

import (
	"fmt"
	"math/big"
	"unicode/utf8"
)

func main() {
	fmt.Println(fraction("⅑"))
	fmt.Println(fraction("⅟2"))
	fmt.Println(fraction("⅞"))
	fmt.Println(fraction("⅟0"))
}

func fraction(s string) (x *big.Rat, err error) {
	r, w := utf8.DecodeRuneInString(s)
	switch r {
	case '¼':
		x = big.NewRat(1, 4)
	case '½':
		x = big.NewRat(1, 2)
	case '¾':
		x = big.NewRat(3, 4)
	case '⅐':
		x = big.NewRat(1, 7)
	case '⅑':
		x = big.NewRat(1, 9)
	case '⅒':
		x = big.NewRat(1, 10)
	case '⅓':
		x = big.NewRat(1, 3)
	case '⅔':
		x = big.NewRat(2, 3)
	case '⅕':
		x = big.NewRat(1, 5)
	case '⅖':
		x = big.NewRat(2, 5)
	case '⅗':
		x = big.NewRat(3, 5)
	case '⅘':
		x = big.NewRat(4, 5)
	case '⅙':
		x = big.NewRat(1, 6)
	case '⅚':
		x = big.NewRat(5, 6)
	case '⅛':
		x = big.NewRat(1, 8)
	case '⅜':
		x = big.NewRat(3, 8)
	case '⅝':
		x = big.NewRat(5, 8)
	case '⅞':
		x = big.NewRat(7, 8)
	case '⅟':
		d, _ := utf8.DecodeRuneInString(s[w:])
		if '1' <= d && d <= '9' {
			x = big.NewRat(1, int64(d)-'0')
			break
		}
		fallthrough
	default:
		err = fmt.Errorf("invalid input: %q", s)
	}
	return
}
