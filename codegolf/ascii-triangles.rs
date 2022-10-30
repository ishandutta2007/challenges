/*

Your task is to write a program or a function that prints an ASCII triangle. They look like this:

|\
| \
|  \
----
Your program will take a single numeric input n, with the constraints 0 <= n <= 1000. The above triangle had a value of n=3.

The ASCII triangle will have n backslashes (\) and vertical bars (|), n+1 lines and dashes (-), and each line will have an amount of spaces equal to the line number (0-based, ie first line is line 0) besides the ultimate line.

Examples:
Input:

4
Output:

|\
| \
|  \
|   \
-----
Input:

0
Output:


In this test case, the output must be empty. No whitespace.

Input:

1
Output:

|\
--
Input & output must be exactly how I specified.

This is code-golf, so aim for the shortest code possible!

*/

fn main() {
    for i in 0..11 {
        triangle(i);
    }
}

fn triangle(n: isize) {
    println!("n={}", n);
    for i in 0..n {
        print!("|");
        repeat(' ', i);
        print!("\\\n");
    }
    if n > 0 {
        repeat('-', n + 1);
    }
    println!("\n");
}

fn repeat(c: char, n: isize) {
    for _ in 0..n {
        print!("{}", c);
    }
}
