/*

Print a cross pattern using the * (asterisk) and . (dot) characters.

Input
The first line contains an integer t, the number of test cases. The next t lines contain four integers separated by spaces: m, n, ci, cj.

Output
For each test case print a cross on an m-by-n grid centered at row ci and column cj, as shown in the example.

Constraints
1 ≤ t ≤ 100
1 ≤ m,n ≤ 100
1 ≤ ci ≤ m
1 ≤ cj ≤ n

Example

Input:

3
1 1 1 1
5 5 3 3
8 13 3 5

Output:

*

..*..
..*..
*****
..*..
..*..

....*........
....*........
*************
....*........
....*........
....*........
....*........
....*........

*/

fn main() {
    cross(1, 1, 1, 1);
    cross(5, 5, 3, 3);
    cross(8, 13, 3, 5);
}

fn cross(m: isize, n: isize, r: isize, c: isize) {
    for i in 1..m + 1 {
        for j in 1..n + 1 {
            if i == r || j == c {
                print!("*");
            } else {
                print!(".");
            }
        }
        println!();
    }
    println!();
}
