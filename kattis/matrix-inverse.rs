/*

Given a square n×n matrix A, the definition of its inverse B=A^-1 is the matrix that fulfills the equality:

AB = I

where B and I are nxn matrices, and I is the identity matrix with ones along the diagonals, and zeros everywhere else.

For this problem, you should implement a matrix inverse solver for 2×2 matrices.

Input

Each test case is described by two lines of input. Each line has two integers with absolute value at most 100, and the integers given in order a, b, c, d

represent the values of the matrix to invert:
A=[a b
   c d]

A blank line follows each test case, and the input is terminated by end-of-file. There are at most 5 test cases.

Output

For each case, display the case number followed by two lines containing the inverse of the given matrix. Each test case is guaranteed to have an inverse (i.e. no matrix is singular), and that inverse is integer-valued. Follow the format of the sample output.

*/

type Mat2 = [[f64; 2]; 2];

fn main() {
    dump2x2(&inv2x2(&[[1.0, 0.0], [0.0, 1.0]]));
    dump2x2(&inv2x2(&[[30.0, 29.0], [1.0, 1.0]]));
    dump2x2(&inv2x2(&[[-7.0, -16.0], [4.0, 9.0]]));
}

fn dump2x2(m: &Mat2) {
    println!("{} {}", m[0][0], m[0][1]);
    println!("{} {}", m[1][0], m[1][1]);
    println!();
}

fn inv2x2(m: &Mat2) -> Mat2 {
    let mut d = m[0][0]*m[1][1] - m[0][1]*m[1][0];
    if d != 0.0 {
        d = 1.0 / d;
    }

    let mut r = Mat2::default();
    r[0][0] = m[1][1] * d;
    r[0][1] = -m[0][1] * d;
    r[1][0] = -m[1][0] * d;
    r[1][1] = m[0][0] * d;

    r
}
