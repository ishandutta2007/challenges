/*

Given two non empty lists of integers, your submission should calculate and return the discrete convolution of the two.
Interestingly, if you consider the list elements as coefficients of polynomials, the convolution of the two lists represents the coefficients of the product of the two polynomials.

Definition
Given the lists A=[a(0),a(1),a(2),...,a(n)] and B=[b(0),b(1),b(2),...,b(m)] (setting a(k)=0 for k<0 and k>n and b(k)=0 for k<0 and k>m) then the
convolution of the two is defined as A*B=[c(0),c(1),...,c(m+n)] where c(k) = sum [ a(x)*b(y) for all integers x y such that x+y=k]

Rules
Any convenient input and output formatting for your language is allowed.
Built-ins for convolution, creating convolution matrices, correlation and polynomial multiplication are not allowed.
Examples
[1,1]*[1] = [1,1]
[1,1]*[1,1] = [1,2,1]
[1,1]*[1,2,1] = [1,3,3,1]
[1,1]*[1,3,3,1] = [1,4,6,4,1]
[1,1]*[1,4,6,4,1] = [1,5,10,10,5,1]

[1,-1]*[1,1,1,1,1] = [1,0,0,0,0,-1]
[80085,1337]*[-24319,406] = [-1947587115,7,542822]

*/

fn main() {
    assert_eq!(conv1d(vec![1, 1], vec![1]), vec![1, 1]);
    assert_eq!(conv1d(vec![1, 1], vec![1, 1]), vec![1, 2, 1]);
    assert_eq!(conv1d(vec![1, 1], vec![1, 2, 1]), vec![1, 3, 3, 1]);
    assert_eq!(conv1d(vec![1, 1], vec![1, 3, 3, 1]), vec![1, 4, 6, 4, 1]);
    assert_eq!(
        conv1d(vec![1, 1], vec![1, 4, 6, 4, 1]),
        vec![1, 5, 10, 10, 5, 1]
    );
    assert_eq!(
        conv1d(vec![1, -1], vec![1, 1, 1, 1, 1]),
        vec![1, 0, 0, 0, 0, -1]
    );
    assert_eq!(
        conv1d(vec![80085, 1337], vec![-24319, 406]),
        vec![-1947587115, 7, 542822]
    );
    assert_eq!(conv1d(vec![], vec![]), vec![]);
}

fn conv1d(a: Vec<isize>, b: Vec<isize>) -> Vec<isize> {
    let n = a.len();
    let m = b.len();
    if n == 0 && m == 0 {
        return vec![];
    }

    let mut c = vec![0; n + m - 1];
    for i in 0..n {
        for j in 0..m {
            c[i + j] += a[i] * b[j];
        }
    }
    return c;
}
