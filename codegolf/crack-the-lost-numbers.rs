/*

The Lost Numbers are 4, 8, 15, 16, 23, 42. Your goal is to create an expression to output them all.

Your allowed characters are 0123456789, ^+-* /, (), % for modulo and n as the single variable allowed. Modified PEMDAS ()^* /%+- is the precedence and / is normal division (3/2 = 1.5). 0^0 = 1 although division by 0 is undefined.

Create the shortest expression (in characters) such that for n = 0..5 (or 1..6 for 1-indexing) the nth Lost Number will be the result of the expression. Shortest expression wins.

*/

fn main() {
    for i in 1..7 {
        println!("{}", lost_numbers(i));
    }
}

fn lost_numbers(n: isize) -> isize {
    n*4 + 16%n*8%13%7*3
}
