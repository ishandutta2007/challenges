/*

Hexadecimal is a base 16 counting system that goes from 0 to f. Your job is to make a counter that will display these numbers.

Example:

$ python counter.py
1 2 3 4 5 6 7 8 9 a b c d e f 10 11 12 13 14 15 16 17 18 19 1a 1b 1c 1d 1e 1f 20 21 22 23 24 25 26 27 28 29 2a 2b 2c 2d 2e 2f 30
Rules:

The numbers may be separated by spaces, tabs, or new lines.
The minimum number you must go to is 30 (48 in decimal).
You may also make the program print numbers forever until it is stopped.
Letters may be in uppercase or lowercase (A or a).
No built in functions allowed (that directly affect hexadecimal conversions/counting).
Leading zeros are allowed
It may start from 1 or 0
Shortest code wins!

*/

fn main() {
    hexprint(0x00, 0x30);
}

fn hexprint(a: isize, b: isize) {
    for c in a..b+1 {
        print!("{:x} ", c);
    }
    println!();
}
