#!/usr/bin/env python

"""

Introduction

During work with BMP (bitmap) generator I face problem of converting number to little endian hex string. Here is function which I create in JavaScript - but wonder how small code can works similarly

let liEnd= num => num.toString(16).padStart(8,'0').match(/../g).reverse().join``;
console.log(liEnd(304767)) // 304767 dec = 0x4a67f hex

Challenge

Write function which will take 32bit unsigned integer number on input, and produce 8-digit hexadecimal string with little endian order. The example algorithm which do the job:

convert numb to hex string e.g: 304767 -> '4a67f'
add padding zeros to get 8-char string: '0004a67f'
split string to four 2-char pieces: '00','04','a6','7f'
reverse order of pieces '7f','a6','04','00'
join pieces and return as result: '7fa60400'
Example Input and Output
Input number (or string with dec number) is on the left of ->, output hex string is on the right

2141586432 -> 0004a67f
304767     -> 7fa60400

"""

def value(n):
    s = ("%08x" % (n))
    t = s[6:8] + s[4:6] + s[2:4] + s[0:2]
    return t

def main():
    assert(value(2141586432) == '0004a67f')
    assert(value(304767) == '7fa60400')

main()
