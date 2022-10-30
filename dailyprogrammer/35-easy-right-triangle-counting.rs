/*

Write a program that will take a number and print a right triangle attempting to use all numbers from 1 to that number.

Sample Run:

Enter number: 10

Output:

7 8 9 10

4 5 6

2 3

1

Enter number: 6

Output:

4 5 6

2 3

1

Enter number: 3

Output:

2 3

1

Enter number: 12

Output:

7 8 9 10

4 5 6

2 3

1

*/

fn main() {
    right_triangle(10);
    right_triangle(6);
    right_triangle(3);
    right_triangle(12);
}

fn right_triangle(n: isize) {
    let mut l = quadratic(1.0, 1.0, -2.0*n as f64) as isize;
    let mut m = l*(l+1)/2;
    while m > 0 {
        for i in 1..l+1 {
            print!("{}", m-l+i);
            if i+1 < l+1 {
                print!(" ");
            }
        }
        println!();
        m -= l;
        l -= 1;
    }
    println!();
}

fn quadratic(a: f64, b: f64, c: f64) -> f64 {
    let d = b*b - 4.0*a*c;
    if d < 0.0 {
        return -1.0;
    }
    return (-b + d.sqrt()) / (2.0*a);
}
