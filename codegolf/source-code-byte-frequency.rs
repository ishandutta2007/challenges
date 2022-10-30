/*

Write a program that get a single byte character as an input and prints the frequency of that byte in the program's source code as an output.

Examples:

Assuming my program is: ab#cd%b then the output of the program should be (each line is a separate execution):

input         output
-----         ------
  a           0.1428571428571429
  b           28.57%
  #           14.2857143%
  c           1/7
  B           0

Rules:
The format of the proportion does not need to be consistent across all inputs, e.g. a fraction for one, decimal for another, percent for a third, plain zero for non-existent byte, etc...
If a proportion is represented as decimal, the result must be accurate to at least 4 decimal places.
Source code should be at least 1 byte long.

Scoring:
This is code-golf - the shortest code (≥1) wins.

(It would also be fun to get the shortest code in every language, so don't hesitate to post multiple entries)

*/

fn main() {
    println!("{}", chfq("ab#cd%b", 'a'));
    println!("{}", chfq("ab#cd%b", 'b'));
    println!("{}", chfq("ab#cd%b", '#'));
    println!("{}", chfq("ab#cd%b", 'c'));
    println!("{}", chfq("ab#cd%b", 'B'));
}

fn chfq(s: &str, c: char) -> f64 {
    let (mut i, mut n) = (0, 0);
    for ch in s.chars() {
        if c == ch {
            i += 1;
        }
        n += 1;
    }
    i as f64 / n as f64
}
