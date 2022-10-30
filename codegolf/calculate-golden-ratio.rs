/*

Write the shortest code, in number of bytes, to display, return, or evaluate to the golden ratio (that is, the positive root of the quadratic equation: x2−x−1=0, approximately 1.618033988749895), to at least 15 significant figures.
No input will be given to your program.

Sample in Stutsk programming language:

1 100 { 1 + 1 swp / } repeat print

*/

fn main() {
    println!("{}", phi());
}

fn phi() -> f64 {
    1.61803398874989484820458683436563811772030917980576286213544862270526046281890
}
