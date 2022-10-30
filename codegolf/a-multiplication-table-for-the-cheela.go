/*

The Cheela (from the book Dragon's Egg by Robert L. Forward) are creatures that live on the surface of a neutron star. Their body is flat and circular with twelve eyes on the perimeter, so they naturally use a base-12 numbering system.

Among the Cheela, care of the hatchlings and education of the young are tasks carried out by the Old Ones. Since young Cheela need to be taught how to multiply, the Old Ones could use a multiplication table.

Your task is to produce a 12x12 multiplication table in base 12, like the following. Uppercase letters A and B are used for digits corresponding to decimal 10 and 11 respectively.

  1   2   3   4   5   6   7   8   9   A   B  10
  2   4   6   8   A  10  12  14  16  18  1A  20
  3   6   9  10  13  16  19  20  23  26  29  30
  4   8  10  14  18  20  24  28  30  34  38  40
  5   A  13  18  21  26  2B  34  39  42  47  50
  6  10  16  20  26  30  36  40  46  50  56  60
  7  12  19  24  2B  36  41  48  53  5A  65  70
  8  14  20  28  34  40  48  54  60  68  74  80
  9  16  23  30  39  46  53  60  69  76  83  90
  A  18  26  34  42  50  5A  68  76  84  92  A0
  B  1A  29  38  47  56  65  74  83  92  A1  B0
 10  20  30  40  50  60  70  80  90  A0  B0 100
The output shoud be printed on screen. The format should be as follows:

Numbers should be aligned to the right within each column.
Leading spaces before the first column, trailing spaces after the last column, or a trailing new line after the last row are allowed.
Separation between columns can be one space (as shown above) or more than one space, but the number of spaces should be consistent between columns.
To measure column separation, consider that displayed numbers include any leading spaces that may have been necessary fo fulfill requirement 1 (so each number occupies three characters, the first of which may be spaces).
For example, the table with two-space separation would be as follows:

  1    2    3    4    5    6    7    8    9    A    B   10
  2    4    6    8    A   10   12   14   16   18   1A   20
  3    6    9   10   13   16   19   20   23   26   29   30
  4    8   10   14   18   20   24   28   30   34   38   40
  5    A   13   18   21   26   2B   34   39   42   47   50
  6   10   16   20   26   30   36   40   46   50   56   60
  7   12   19   24   2B   36   41   48   53   5A   65   70
  8   14   20   28   34   40   48   54   60   68   74   80
  9   16   23   30   39   46   53   60   69   76   83   90
  A   18   26   34   42   50   5A   68   76   84   92   A0
  B   1A   29   38   47   56   65   74   83   92   A1   B0
 10   20   30   40   50   60   70   80   90   A0   B0  100
Computer storage on a neutron star is really expensive, so your code should use as few bytes as possible.

Extended challenge and bonus
Ideally your code should be reused in other parts of the universe, where other numbering systems may be in use.
To that end, the challenge is optionally extended as follows: Your code accepts a number N as input and generates an NxN multiplication table in base N, with the above format.

Input may be from keyboard or as a function argument. The program or function should work for 2 ≤ N ≤ 36, using as digits the first N characters of the sequence 0, 1, ..., 9, A, B, ..., Z (uppercase letters)

This extended challenge is optional. If you follow this route, take 20% off your byte count (no need to round to an integer number).

*/

package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	table(12)
}

func table(n int64) {
	l := math.Log10(float64(n)) + 2
	l = math.Ceil(l)
	for a := int64(1); a <= n; a++ {
		for b := int64(1); b <= n; b++ {
			s := strconv.FormatInt(a*b, int(n))
			s = strings.ToUpper(s)
			fmt.Printf("%*s", int(l), s)
		}
		fmt.Println()
	}
}
