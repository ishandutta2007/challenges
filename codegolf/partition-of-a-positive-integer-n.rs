/*

Find the number of partitions of a positive integer n. Hope someone uses the explicit finite formula for the partition function defined in Jan Hendrik Brunier and Ken Ono paper here.

Sample Input
8
Sample Output
22
N is less than or equal to 1000. Write the complete program. More than anything I would like to see the different approaches.

*/

fn main() {
    let tab = vec![
        1, 1, 2, 3, 5, 7, 11, 15, 22, 30, 42, 56, 77, 101, 135, 176, 231, 297, 385, 490, 627, 792,
        1002, 1255, 1575, 1958, 2436, 3010, 3718, 4565, 5604,
    ];
    for (i, v) in tab.iter().enumerate() {
        assert_eq!(partition(i), *v);
    }
}

// https://oeis.org/A000041
fn partition(n: usize) -> isize {
    if n == 0 {
        return 1;
    }

    let mut a = alloc(n + 1);
    for i in 0..n + 1 {
        a[i][0] = 0;
        a[0][i] = 1;
    }

    for i in 1..n + 1 {
        a[i][1] = 1;
        for j in 2..n + 1 {
            a[i][j] = a[i][j - 1];
            if i >= j {
                a[i][j] += a[i - j][j];
            }
        }
    }
    return a[n][n - 1] + 1;
}

fn alloc(n: usize) -> Vec<Vec<isize>> {
    let mut a = Vec::new();
    for _ in 0..n {
        a.push(vec![0; n]);
    }
    return a;
}
