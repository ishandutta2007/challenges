/*

A factor chain is an array where each previous element is a factor of the next consecutive element. The following is a factor chain:

[3, 6, 12, 36]

// 3 is a factor of 6
// 6 is a factor of 12
// 12 is a factor of 36

Create a function that determines whether or not an array is a factor chain.
Examples

factorChain([1, 2, 4, 8, 16, 32]) ➞ true

factorChain([1, 1, 1, 1, 1, 1]) ➞ true

factorChain([2, 4, 6, 7, 12]) ➞ false

factorChain([10, 1]) ➞ false

*/

fn main() {
    assert_eq!(factor_chain(&vec![1, 2, 4, 8, 16, 32]), true);
    assert_eq!(factor_chain(&vec![1, 1, 1, 1, 1, 1]), true);
    assert_eq!(factor_chain(&vec![2, 4, 6, 7, 12]), false);
    assert_eq!(factor_chain(&vec![10, 1]), false);
    assert_eq!(factor_chain(&vec![10, 20, 30, 40]), false);
    assert_eq!(factor_chain(&vec![10, 20, 40]), true);
    assert_eq!(factor_chain(&vec![1, 1, 1, 1, 7, 49]), true);
}

fn factor_chain(p: &Vec<isize>) -> bool {
    for i in 1..p.len() {
        if p[i]%p[i-1] != 0 {
            return false;
        }
    }
    return true;
}
