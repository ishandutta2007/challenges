/*

Make a program that simulates the basic logic gates.

Input: An all-caps word followed by 2 1 digit binary numbers, separated by spaces, such as OR 1 0. The gates OR, AND, NOR, NAND, XOR, and XNOR are needed.

Output: What the output of the entered logic gate would be given the two numbers: either 1 or 0.

Examples:
AND 1 0 becomes 0
XOR 0 1 becomes 1
OR 1 1 becomes 1
NAND 1 1 becomes 0

This is codegolf, so the shortest code wins.

*/

fn main() {
    assert_eq!(logic("AND", 1, 0), 0);
    assert_eq!(logic("XOR", 0, 1), 1);
    assert_eq!(logic("OR", 1, 1), 1);
    assert_eq!(logic("NAND", 1, 1), 0);
    assert_eq!(logic("NOR", 1, 1), 0);
    assert_eq!(logic("XNOR", 1, 1), 1);
}

fn logic(op: &str, x: isize, y: isize) -> isize {
    let r = match op {
        "AND" => x & y,
        "XOR" => x ^ y,
        "OR" => x | y,
        "NAND" => !(x & y),
        "NOR" => !(x | y),
        "XNOR" => !(x ^ y),
        _ => 0
    };
    r&1
}
