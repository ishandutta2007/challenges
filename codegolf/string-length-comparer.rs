/*

this program has to take two strings and compare their length, then tell you which one is longer (string-a or string-b) and by how much

rules:

    no using .length or other built-in length checking methods (duh!)
    no using addition or subtraction, this includes improvised addition/subtraction, in case you find some sort of weird improvisation.
    no > / < (greater then/less then) inside if / if-else statements (you can use them in loops though), this obviously includes >= etc. and no cheating (bool = a > b;if(bool))
    emphasis is on short rather then efficient code
    oh yeah almost forgot... good luck!

*/

fn main() {
    assert_eq!(strcmp("hello", "world"), (0, 0));
    assert_eq!(strcmp("he", "she"), (1, 1));
    assert_eq!(strcmp("they", "she"), (0, 1));
}

fn strcmp(a: &str, b: &str) -> (usize, usize) {
    let n = a.chars().count();
    let m = b.chars().count();
    if n >= m {
        (0, n-m)
    } else {
        (1, m-n)
    }
}
