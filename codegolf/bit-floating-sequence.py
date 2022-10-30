#!/usr/bin/env python

"""

A bit floats from the LSB to the MSB moving one position each time until it floats to the top of the container:

0000
0001
0010
0100
1000
Once one bit floats to the top, another bit begins its journey and it stops when it meets other bit:

1001
1010
1100
This happens until the container is filled with bits:

1101
1110
1111
Challenge
Given an integer number, output the "Bit floating sequence" for a container of that number of bits.

Each term of the sequence can be separated by any separator of your choice.
Edit: Sequence must be shown as decimal integer numbers, starting by the first therm: 0.
The container size sould be greater than zero and up to the number of bits of the bigest integer suported by the language of your choice. You can assume that the input always match this requirement.
Examples
Only the numeric sequence is required, binary representation is shown as example:

For 1: 0 1

0 -> 0
1 -> 1
For 3: 0 1 2 4 5 6 7

000 -> 0
001 -> 1
010 -> 2
100 -> 4
101 -> 5
110 -> 6
111 -> 7
For 4: 0 1 2 4 8 9 10 12 13 14 15

0000 -> 0
0001 -> 1
0010 -> 2
0100 -> 4
1000 -> 8
1001 -> 9
1010 -> 10
1100 -> 12
1101 -> 13
1110 -> 14
1111 -> 15
For 8: 0 1 2 4 8 16 32 64 128 129 130 132 136 144 160 192 193 194 196 200 208 224 225 226 228 232 240 241 242 244 248 249 250 252 253 254 255

00000000 -> 0
00000001 -> 1
00000010 -> 2
00000100 -> 4
00001000 -> 8
…
…
…
11111000 -> 248
11111001 -> 249
11111010 -> 250
11111100 -> 252
11111101 -> 253
11111110 -> 254
11111111 -> 255

"""

def gen(n):
    if n < 1:
        return []
    
    r = [0]
    a = 0
    for i in range(n):
        b = 1
        for j in range(n - i):
            r.append(a | b)
            b <<= 1
        a |= (b >> 1)
    return r

def main():
    assert(gen(1) == [0, 1])
    assert(gen(3) == [0, 1, 2, 4, 5, 6, 7])
    assert(gen(4) == [0, 1, 2, 4, 8, 9, 10, 12, 13, 14, 15])
    assert(gen(8) == [0, 1, 2, 4, 8, 16, 32, 64, 128, 129, 130, 132, 136, 144, 160, 192, 193, 194, 196, 200, 208, 224, 225, 226, 228, 232, 240, 241, 242, 244, 248, 249, 250, 252, 253, 254, 255])

main()
