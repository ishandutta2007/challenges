/*

Given a number N, output a NxN right angled triangle, where each row i is filled with numbers up to i.

Example

n = 0

(no output)

n = 4

1
1 2
1 2 3
1 2 3 4

n = 10

1
1 2
1 2 3
.
.
.
1 2 3 4 5 6 7 8 9 10

(no alignment needed)

n = N

1
1 2
1 2 3
.
.
.
1 2 3 4 .... N

There is no trailing space at the end of each line.

Least number of bytes wins, and standard loopholes are not allowed.

*/

fn main() {
    triangle(0);
    triangle(4);
    triangle(10);
}

fn triangle(n: usize) {
    println!("n={}", n);
    for i in 1..n+1 {
        for j in 1..i+1 {
            print!("{}", j);
            if j+1 < i+1 {
                print!(" ");
            }
        }
        println!();
    }
    println!();
}
