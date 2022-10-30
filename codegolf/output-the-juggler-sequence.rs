/*

The Juggler sequence is described as follows. Beginning with an input a1, the next term is defined by the recurrence relation

a[k+1] = a[k]^0.5 if a[k] is even
         a[k]^1.5 if a[k] is odd

The sequence terminates when it reaches 1, as all subsequent terms would then be 1.

Task
Given an input n greater than or equal to 2, write a program/function/generator/etc. that outputs/returns the respective juggler sequence.
The output can be in any reasonable form. You may not use a built-in that computes the juggler sequence, or any built-in that directly yields the result.
You may assume that the sequence terminates in 1.

Test Cases
Input: output
2: 2, 1
3: 3, 5, 11, 36, 6, 2, 1
4: 4, 2, 1
5: 5, 11, 36, 6, 2, 1

*/

fn main() {
    assert_eq!(juggler(2), vec![2, 1]);
    assert_eq!(juggler(3), vec![3, 5, 11, 36, 6, 2, 1]);
    assert_eq!(juggler(4), vec![4, 2, 1]);
    assert_eq!(juggler(5), vec![5, 11, 36, 6, 2, 1]);
}

fn juggler(mut x: isize) -> Vec<isize> {
    let mut r = vec![];
    loop {
        r.push(x);
        if x == 1 {
            break;
        }

        let a = x as f64;
        let b = (x & 1) as f64 + 0.5;
        x = a.powf(b).floor() as isize;
    }
    r
}
