/*

This is tangentially related to my quest to invent an esoteric programming language.

A table of the binary numbers 0 .. 15 can be used to implement a Universal Binary Function using indexing operations.
Given two 1-bit inputs X and Y, all 16 possible functions can be encoded in a 4-bit opcode.

X Y  F|0 1 2 3 4 5 6 7 8 9 A B C D E F
- -    - - - - - - - - - - - - - - - -  
0 0    0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1
0 1    0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1
1 0    0 0 0 0 1 1 1 1 0 0 0 0 1 1 1 1
1 1    0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1
       -     -   - -   -   -   -   - -
       0    ~X  ~Y ^   &   Y   X   | 1
      ZERO    NOT-Y   AND         OR
          NOT-X   XOR              ONE
So this set of 16 functions can be applied to binary inputs as the function

U(f,x,y): (f >> ((x<<1) | y)) & 1,

or

U(f,x,y): (f / 2^(x×2 + y)) % 2,

or with indexing or matrix partitioning.

It will be useful to know the most compact way to represent or generate such a table of values for any possible languages to be built upon this type of binary operation.

The goal:
Generate this exact text output:

0101010101010101
0011001100110011
0000111100001111
0000000011111111

That's it! Shortest-code wins.

*/

fn main() {
    println!("{:016b}", 0x5555);
    println!("{:016b}", 0x3333);
    println!("{:016b}", 0x0f0f);
    println!("{:016b}", 0x00ff);
}
