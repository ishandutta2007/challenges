/*

Description
In computational complexity theory, the 3SUM problem asks if a given set of n real numbers contains three elements that sum to zero.
A naive solution works in O(N^2) time, and research efforts have been exploring the lower complexity bound for some time now.

Input Example
You will be given a list of integers, one set per line. Example:

9 -6 -5 9 8 3 -4 8 1 7 -4 9 -9 1 9 -9 9 4 -6 -8
Output Example
Your program should emit triplets of numbers that sum to 0. Example:

-9 1 8
-8 1 7
-5 -4 9
-5 1 4
-4 1 3
-4 -4 8
Challenge Input
4 5 -1 -2 -7 2 -5 -3 -7 -3 1
-1 -6 -3 -7 5 -8 2 -8 1
-5 -1 -4 2 9 -9 -6 -1 -7
Challenge Output
-7 2 5
-5 1 4
-3 -2 5
-3 -1 4
-3 1 2

-7 2 5
-6 1 5
-3 1 2

-5 -4 9
-1 -1 2

*/

fn main() {
    assert_eq!(
        sum3(vec![
            9, -6, -5, 9, 8, 3, -4, 8, 1, 7, -4, 9, -9, 1, 9, -9, 9, 4, -6, -8
        ]),
        vec![
            [-9, 1, 8],
            [-8, 1, 7],
            [-5, -4, 9],
            [-5, 1, 4],
            [-4, -4, 8],
            [-4, 1, 3]
        ],
    );

    assert_eq!(
        sum3(vec![4, 5, -1, -2, -7, 2, -5, -3, -7, -3, 1]),
        vec![[-7, 2, 5], [-5, 1, 4], [-3, -2, 5], [-3, -1, 4], [-3, 1, 2]],
    );

    assert_eq!(
        sum3(vec![-1, -6, -3, -7, 5, -8, 2, -8, 1]),
        vec![[-7, 2, 5], [-6, 1, 5], [-3, 1, 2]],
    );

    assert_eq!(
        sum3(vec![-5, -1, -4, 2, 9, -9, -6, -1, -7]),
        vec![[-5, -4, 9], [-1, -1, 2]],
    );
}

fn sum3(a: Vec<isize>) -> Vec<[isize; 3]> {
    let mut r = vec![];
    let n = a.len();
    for i in 0..n {
        for j in i + 1..n {
            for k in j + 1..n {
                if a[i] + a[j] + a[k] == 0 {
                    let mut v = [a[i], a[j], a[k]];
                    v.sort();
                    if !r.contains(&v) {
                        r.push(v);
                    }
                }
            }
        }
    }
    r.sort();
    r
}
