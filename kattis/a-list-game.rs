/*

You are playing the following simple game with a friend:

    The first player picks a positive integer X.

    The second player gives a list of k positive integers Y1,…,Yk such that (Y1+1)(Y2+1)⋯(Yk+1)=X, and gets k points.

Write a program that plays the second player.

Input

The input consists of a single integer X satisfying 103≤X≤109, giving the number picked by the first player.

Output

Write a single integer k, giving the number of points obtained by the second player, assuming she plays as good as possible.

*/

fn main() {
    assert_eq!(factors(65536), 16);
    assert_eq!(factors(127381), 3);
}

fn factors(mut n: usize) -> usize {
    let (mut c, mut i) = (1, 2);
    while i*i <= n {
        if n%i == 0 {
            n /= i;
            c += 1;
        } else {
            i += 1;
        }
    }
    c
}
