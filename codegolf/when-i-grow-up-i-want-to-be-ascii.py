#!/usr/bin/env python

"""

Task

Your task is to take a character in:

AÁÀÃÂBCÇDEÉÊFGHIÍJKLMNOÕÓÔPQRSTUÚVWXYZaáàãâbcçdeéêfghiíjklmnoõóôpqrstuúvwxyz

and turn it into a characters in:

AAAAABCCDEEEFGHIIJKLMNOOOOPQRSTUUVWXYZaaaaabccdeeefghiijklmnoooopqrstuuvwxyz

by the obvious operation: dropping the accents in the letters.
Input

A character in any sensible format, including but not limited to:

    A string with only one character;
    A unicode codepoint.

Output

The transformed char in any sensible format, which includes:

    A string with only one char;
    A unicode codepoint.

Test cases

'A' -> 'A'
'Á' -> 'A'
'À' -> 'A'
'Ã' -> 'A'
'Â' -> 'A'
'B' -> 'B'
'C' -> 'C'
'Ç' -> 'C'
'D' -> 'D'
'E' -> 'E'
'É' -> 'E'
'Ê' -> 'E'
'F' -> 'F'
'G' -> 'G'
'H' -> 'H'
'I' -> 'I'
'Í' -> 'I'
'J' -> 'J'
'K' -> 'K'
'L' -> 'L'
'M' -> 'M'
'N' -> 'N'
'O' -> 'O'
'Õ' -> 'O'
'Ó' -> 'O'
'Ô' -> 'O'
'P' -> 'P'
'Q' -> 'Q'
'R' -> 'R'
'S' -> 'S'
'T' -> 'T'
'U' -> 'U'
'Ú' -> 'U'
'V' -> 'V'
'W' -> 'W'
'X' -> 'X'
'Y' -> 'Y'
'Z' -> 'Z'
'a' -> 'a'
'á' -> 'a'
'à' -> 'a'
'ã' -> 'a'
'â' -> 'a'
'b' -> 'b'
'c' -> 'c'
'ç' -> 'c'
'd' -> 'd'
'e' -> 'e'
'é' -> 'e'
'ê' -> 'e'
'f' -> 'f'
'g' -> 'g'
'h' -> 'h'
'i' -> 'i'
'í' -> 'i'
'j' -> 'j'
'k' -> 'k'
'l' -> 'l'
'm' -> 'm'
'n' -> 'n'
'o' -> 'o'
'õ' -> 'o'
'ó' -> 'o'
'ô' -> 'o'
'p' -> 'p'
'q' -> 'q'
'r' -> 'r'
's' -> 's'
't' -> 't'
'u' -> 'u'
'ú' -> 'u'
'v' -> 'v'
'w' -> 'w'
'x' -> 'x'
'y' -> 'y'
'z' -> 'z'

You can check here for a Python reference implementation without regexes.

This is code-golf so shortest submission in bytes, wins! If you liked this challenge, consider upvoting it... And happy golfing!

"""

import unicodedata

def normalize(s):
    f = unicodedata.normalize('NFD', s)
    a = f.encode('ascii', 'ignore')
    u = a.decode('utf-8')
    return u

print(normalize("AÁÀÃÂBCÇDEÉÊFGHIÍJKLMNOÕÓÔPQRSTUÚVWXYZaáàãâbcçdeéêfghiíjklmnoõóôpqrstuúvwxyz"))
