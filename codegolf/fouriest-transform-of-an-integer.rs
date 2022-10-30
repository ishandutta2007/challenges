/*

Challenge

Inspired by this SMBC comic, discussed on reddit, math.stackexchange, and calculus7, the challenge is to return the lowest base such that a number is "fouriest."
Description

    [From the comic]

    "It's called a Fourier Transform when you take a number and convert it to the base system where it has more fours, thus making it 'fourier.' If you pick the base with the most fours, the number is said to be 'fouriest.'"

The challenge is: given an integer greater than four, return the lowest base in which it is "fouriest."
Rules

    The solution may be either a function or a full program, whose input and output are of integral type (Int, Long, etc.)
    If your language has a function to convert base systems or solve this challenge for a number other than four, it is disallowed
    I will not accept my own solution
    Solution with the lowest number of bytes wins!

Test Cases

f(17)      = 13
f(72)      = 17
f(176)     = 43
f(708)     = 176
f(500)     = 124
f(2004)    = 500
f(1004)    = 250
f(4020)    = 1004
f(1004)    = 250
f(4020)    = 1004
f(4076)    = 1018
f(16308)   = 4076
f(8156)    = 2038
f(32628)   = 8156
f(3444443) = 10
f(9440449) = 5

Aside: Except for the final two test cases (which are palindromic primes), each one is a record in this sequence such that its position is an additional record.

You may also note that (the position)/(the record) is around four, and I conjecture that this ratio converges to four.

Test Implementations:

Mathematica:

Maxnum4s[x_] := Block[{thisbest = 0, best = 0, bestpos = 4},
  Do[thisbest = num4s[x, pos]; 
   If[thisbest > best, best = thisbest; bestpos = pos, 0], {pos, 5, x - 1}]; {bestpos, best}]

Python3:

def foursCount(x0,b):
    count = 0
    x     = x0
    while x > 0:
        if x % b == 4:
            count += 1
        x = x // b
    return count

def fouriest(x):
    bestpos = 4
    best    = 0
    this    = 0
    for pos in range(4,x):
        this = foursCount(x,pos)
        if this > best:
            best    = this
            bestpos = pos
    return bestpos

C:

int foursCount(int x0, int b){
    int count = 0;
    int     x = x0;
    while (x > 0) {
        if (x % b == 4) {
            count++;
        }
        x = x / b;
    }return count;
}
int fouriest(int x){
    int pos     = 5;
    int this    = 0;
    int best    = 0;
    int bestpos = 0;
    while (pos < x) {
        this = foursCount(x, pos);
        if (this > best) {
            bestpos = pos;
            best    = this;
        }
        pos++;
    }
    return bestpos;
}

If you're curious, just for fun:

Mathematica:            77.042 s
Python:                  8.596 s
Haskell (Interpreted): 579.270 s
Haskell (compiled):      4.223 s
C:                       0.129 s

*/

fn main() {
    assert_eq!(fouriest(17), 13);
    assert_eq!(fouriest(72), 17);
    assert_eq!(fouriest(176), 43);
    assert_eq!(fouriest(708), 176);
    assert_eq!(fouriest(500), 124);
    assert_eq!(fouriest(2004), 500);
    assert_eq!(fouriest(1004), 250);
    assert_eq!(fouriest(4020), 1004);
    assert_eq!(fouriest(1004), 250);
    assert_eq!(fouriest(4020), 1004);
    assert_eq!(fouriest(4076), 1018);
    assert_eq!(fouriest(16308), 4076);
    assert_eq!(fouriest(8156), 2038);
    assert_eq!(fouriest(32628), 8156);
    assert_eq!(fouriest(3444443), 10);
    assert_eq!(fouriest(9440449), 5);
}

fn fours(mut x: isize, b: isize) -> isize {
    let mut c = 0;
    while x > 0 {
        if x%b == 4 {
            c += 1;
        }
        x /= b;
    }
    c
}

fn fouriest(x: isize) -> isize {
    let (mut l, mut m) = (0, 0);
    for i in 5..x {
        let v = fours(x, i);
        if v > m {
            l = i;
            m = v;
        }
    }
    l
}
