/*

A question that had popped up in my head once - how many NAND gates would it take to build a larger, "meta-NAND" gate?

Your task is to build a black-box circuit that takes two input wires A and B and returns one output wire that satisfies A NAND B, subject to the following restrictions:

You must use at least two NAND gates in this construction (and no gates other than NAND).
You may not have null configurations of gates - that is, systems of gates that are equivalent to a gateless wire. (For example, two NOT gates in series are a null configuration.)
You cannot have any stray wires (discarded values or constants).
Fewest gates wins.

*/

fn main() {
    for a in 0..2 {
        for b in 0..2 {
            assert_eq!(nand(a, b), meta_nand(a, b));
        }
    }
}

fn nand(a: isize, b: isize) -> isize {
    !(a & b) & 1
}

fn meta_nand(a: isize, b: isize) -> isize {
    nand(nand(nand(a, a), b), b)
}
