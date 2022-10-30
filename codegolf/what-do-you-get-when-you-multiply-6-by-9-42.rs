/*

I love math. But I can't find a single calculator that can multiply correctly. They seem to get everything right except 6*9 (It's the question to life, the universe, and everything!
How could they get that wrong?!). So I want you all to write a function for me that can multiply 2 numbers correctly (and 6*9 equals 42 instead of 54. 9*6 equals 54 still).

Oh, and I'm going to have to build the source in Minecraft so... fewest bytes win!

Recap

    Take 2 numbers as input (type doesn't matter, but only 2 items will be passed, and order must be consistent. So streams, and arrays are ok as long as they preserve the order they where passed in. I.e., a map won't work because it doesn't preserve the order)
    Output multiple of both numbers except if they are 6 and 9, then output 42 (order matters!)
    PS. I never was really good with counting, so I think only integers from 0 to 99 are real numbers (type used doesn't matter)
    Fewest bytes per language wins!

*/

fn main() {
    assert_eq!(mul(6, 9), 42);
    assert_eq!(mul(9, 6), 54);
}

fn mul(x: isize, y: isize) -> isize {
    if x == 6 && y == 9 {
        42
    } else {
        x*y
    }
}
