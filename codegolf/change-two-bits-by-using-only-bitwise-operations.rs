/*

try to write shortest possible variant of logic which converts binary input by this table:

00 -> 00
01 -> 10
10 -> 01
11 -> 11
You can use only bitwise and bitshift operations. I calculate only operations and don't care brackets, spaces, constants and etc. But you can't use any control (if, while, ternary) and arithmetic operations.

If you are using bitwise and bitshift operations, your operations number will be multipled by two:

op_num = (your_op_num << types_of_operation_num) >> 1
edit: sorry, this is not real code-golf, because I calculate operations in logic, not characters.

*/

fn main() {
    assert_eq!(change(0b00), 0b00);
    assert_eq!(change(0b01), 0b10);
    assert_eq!(change(0b10), 0b01);
    assert_eq!(change(0b11), 0b11);
}

fn change(x: usize) -> usize {
    (x & !3) | ((x >> 1) & 1) | ((x << 1) & 2)
}
