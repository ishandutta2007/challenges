#!/usr/bin/env python

"""

I tried this contest: https://www.hackerrank.com/challenges/secret-language Well, the score in this contest said I made 30 out of 30 points. As the score is calculated with the formula 30*(1000-#chars)/1000 this is impossible. Here is my code:

import sys,string as s
b='anbycoduepfxgqhvirjzkslwmt'
a=s.letters
b+=b.upper()
t=s.translate
m=s.maketrans
for l in sys.stdin:
 print{'N':t(l[7:],m(a,b)),'E':t(l[7:],m(b,a)),'O':''}[l[1]],
The contest is over, so asking is no cheating but I would like to get some realistic score. I have 187 chars with newline and 195 with cr-lf. For pythoncode 24.39 (assuming newline) isn't so bad, but I think it can be done better.

For completeness here is the challenge:

Bob and Fred pass notes to each other in class all the time. However their teacher started intercepting their messages and reading the messages out loud to the class.
Undeterred, Bob and Fred decided to encode their messages before they pass them so that when the message is intercepted the teacher and class will not understand it.

They got together and decided on using a simple substitution cipher. The substition cipher they agreed upon is listed below:

Old Letter: ABCDEFGHIJKLMNOPQRSTUVWXYZ New Letter: ANBYCODUEPFXGQHVIRJZKSLWMT

Using this key (Case matters!), A is changed to A, a is changed to a, B is changed to N, b is changed to n, C is changed to B, c is changed to b, … . All other characters remain the same.

However after Bob and Fred started using this method of note transfer they quickly realized that they are very slow at encoding and decoding messages.
They have hired you to help them transfer messages faster by writing a program that will encode or decode messages using their substitution cipher. They want the code to be very portable so the smaller the source file is the better.

Input

Input will consist of several lines. Each line will begin with either the string “ENCODE”, “DECODE”, or “DONE”.
If the string is “ENCODE” or “DECODE” then a message will follow. This is the message that you will have to either encode (if the first string is “ENCODE”) or decode (if the first string is “DECODE”).
Messages will contain spaces and punctuation but will always be on the same line. If the string is “DONE” then this signifies that Bob and Fred are done exchanging messages.

Output

For each line that begins with “ENCODE” print the encoding of the message that follows.

For each line that begins with “DECODE” print the decoding of the message that follows.

Be sure to keep all capitolization and punctuation that is used in the message.

Sample Input

ENCODE This is a message. DECODE Zuej ej a gcjjadc. DONE

Sample Output

Zuej ej a gcjjadc. This is a message.

Scoring

Your score will be 30 * (1000 - #characters) / 1000. The minimum score a correct solution will receive is 0.03.

"""

ALPHABET1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
ALPHABET2 = "ANBYCODUEPFXGQHVIRJZKSLWMT"

def substitute(text, plain, cipher):
    m = {}
    n = min(len(plain), len(cipher))
    for i in range(n):
        a, b = plain[i].upper(), cipher[i].upper()
        c, d = plain[i].lower(), cipher[i].lower()
        m[a], m[c] = b, d
    
    s = ""
    for c in text:
        s += m.get(c, c)
    return s

def encode(text):
    return substitute(text, ALPHABET1, ALPHABET2)

def decode(text):
    return substitute(text, ALPHABET2, ALPHABET1)

def main():
    assert(encode("This is a message.") == "Zuej ej a gcjjadc.")
    assert(decode("Zuej ej a gcjjadc.") == "This is a message.")

main()
