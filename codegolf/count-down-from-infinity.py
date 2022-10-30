"""

Seems like an impossible task right? Well, it's actually not that hard. If we write the word Infinity as 8-bit binary ASCII code, we'll get:

01001001 01101110 01100110 01101001 01101110 01101001 01110100 01111001

This can be concatenated, and converted to the decimal value 5291279215216915577. Now that's a number we can work with...

The way you'll count down is:

    Output the original string as a decimal number (as shown above)
    Remove leading 0s in its binary representation (if any)
    Toggle the bits in the binary representation (1->0, 0->1)
    Output the number in decimal
    Repeat steps 2-4 as until you reach 0.

Challenge:

Create a program or function that takes a string as input, and outputs (on any suitable format) the numbers you'll get when performing the procedure above.

Test case:

I think the challenge will be fairly easy to understand, even though it's only one test case. I'll use Inf instead of Infinity to keep this fairly short.

Inf
4812390  (10010010110111001100110)
3576217  ( 1101101001000110011001)
618086   (   10010110111001100110)
430489   (    1101001000110011001)
93798    (      10110111001100110)
37273    (       1001000110011001)
28262    (        110111001100110)
4505     (          1000110011001)
3686     (           111001100110)
409      (              110011001)
102      (                1100110)
25       (                  11001)
6        (                    110)
1        (                      1)
0        (                      0)

Input: Inf 
Output:
4812390, 3576217, 618086, 430489, 93798, 37273, 28262, 4505, 3686, 409, 102, 25, 6, 1, 0 

Input: Infinity
Output:
5291279215216915577, 3932092821637860230, 679593196789527673, 473328307817319302, 103132444486104185, 40982743589751686, 31074850448176249, 4953946570787718, 4053252683953273, 450346943417222, 112603010004089, 28134478351238, 7049893737593, 1746199284614, 452823970937, 96931842950, 40507110521, 28212366214, 6147372153, 2442562438, 1852404857, 295078790, 241792121, 26643334, 6911097, 1477510, 619641, 428934, 95353, 35718, 29817, 2950, 1145, 902, 121, 6, 1, 0

Your code must support strings that can be represented as a binary number up to the limit of your language. All strings will only contain printable ASCII-characters from 32-126 (space to tilde).

"""

def strnum(s):
    v = 0
    for c in s:
        v = (v << 8) | ord(c)
    return v

def mask(n):
    return (1 << len(bin(n)[2:])) - 1

def countdown(s):
    l = []
    v = strnum(s)
    while True:
        l.append(v)
        if v == 0:
            break
        v = ~v & mask(v)
    return l

def main():
    assert(countdown("Inf") == [4812390, 3576217, 618086, 430489, 93798, 37273, 28262, 4505, 3686, 409, 102, 25, 6, 1, 0])
    assert(countdown("Infinity") == [5291279215216915577, 3932092821637860230, 679593196789527673, 473328307817319302, 103132444486104185, 40982743589751686, 31074850448176249, 4953946570787718, 4053252683953273, 450346943417222, 112603010004089, 28134478351238, 7049893737593, 1746199284614, 452823970937, 96931842950, 40507110521, 28212366214, 6147372153, 2442562438, 1852404857, 295078790, 241792121, 26643334, 6911097, 1477510, 619641, 428934, 95353, 35718, 29817, 2950, 1145, 902, 121, 6, 1, 0])

main()
