/*

Little Jóna needs a program. The program should read integers and print them in reverse order. Jóna asks for your help.
Input

The first line of input contains the integer n. Then comes a list of n

integers, each on its own line.
Output

The list should be printed in reverse order of input.

*/

fn main() {
    reverse(&vec![1, 2, 3, 4, 5]);
    reverse(&vec![10, 12, 9]);
}

fn reverse(a: &Vec<isize>) {
    let l = a.len();
    for i in 0..l {
        println!("{}", a[l-i-1]);
    }
    println!();
}
