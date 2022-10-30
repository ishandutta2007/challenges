#!/usr/bin/env python

"""

Inspired by the bugged output in @Carcigenicate's Clojure answer for the Print this diamond challenge.

Print this exact text:
1        2        3        4        5        6        7        8        9        0
1       2       3       4       5       6       7       8       9       0
1      2      3      4      5      6      7      8      9      0
1     2     3     4     5     6     7     8     9     0
1    2    3    4    5    6    7    8    9    0
1   2   3   4   5   6   7   8   9   0
1  2  3  4  5  6  7  8  9  0
1 2 3 4 5 6 7 8 9 0
1234567890
1 2 3 4 5 6 7 8 9 0
1  2  3  4  5  6  7  8  9  0
1   2   3   4   5   6   7   8   9   0
1    2    3    4    5    6    7    8    9    0
1     2     3     4     5     6     7     8     9     0
1      2      3      4      5      6      7      8      9      0
1       2       3       4       5       6       7       8       9       0
1        2        3        4        5        6        7        8        9        0
(From the middle outward in both directions, each digit is separated by one more space than the previous line.)

Challenge rules:
There will be no input (or an empty unused input).
Trailing spaces are optional.
A single trailing new-line is optional.
Leading spaces or new-lines are not allowed.
Returning a string-array isn't allowed. You should either output the text, or have a function which returns a single string with correct result.
General rules:
This is code-golf, so shortest answer in bytes wins.
Don't let code-golf languages discourage you from posting answers with non-codegolfing languages. Try to come up with an as short as possible answer for 'any' programming language.
Standard rules apply for your answer, so you are allowed to use STDIN/STDOUT, functions/method with the proper parameters and return-type, full programs. Your call.
Default Loopholes are forbidden.
If possible, please add a link with a test for your code.
Also, please add an explanation if necessary.

"""

text = """

1        2        3        4        5        6        7        8        9        0
1       2       3       4       5       6       7       8       9       0
1      2      3      4      5      6      7      8      9      0
1     2     3     4     5     6     7     8     9     0
1    2    3    4    5    6    7    8    9    0
1   2   3   4   5   6   7   8   9   0
1  2  3  4  5  6  7  8  9  0
1 2 3 4 5 6 7 8 9 0
1234567890
1 2 3 4 5 6 7 8 9 0
1  2  3  4  5  6  7  8  9  0
1   2   3   4   5   6   7   8   9   0
1    2    3    4    5    6    7    8    9    0
1     2     3     4     5     6     7     8     9     0
1      2      3      4      5      6      7      8      9      0
1       2       3       4       5       6       7       8       9       0
1        2        3        4        5        6        7        8        9        0

"""

def main():
    print(text)

main()
