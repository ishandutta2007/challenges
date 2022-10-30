/*

The goal of this challenge is to use Euler's method to approximate the solution of a differential equation of the form f(n)(x) = c.†

The input will be a list of integers in which the nth value represents the value of f(n)(0). The first integer is f(0), the second is f'(0), and so on. The last integer in this list is the constant and will always remain the same.

Also provided as input will be a positive (nonzero) integer x, which represents the target value (you are trying to estimate f(x)). The step size for Euler's method will always be 1. Thus, you will need to take x steps total.

If you are unfamliar with Euler's method, here is a detailed example with an explanation for the input [4, -5, 3, -1], x = 8.

x       f(x)      f'(x)     f''(x)    f'''(x)
0          4         -5          3         -1
1   4-5 = -1  -5+3 = -2   3-1 =  2         -1
2  -1-2 = -3  -2+2 =  0   2-1 =  1         -1
3  -3+0 = -3   0+1 =  1   1-1 =  0         -1
4  -3+1 = -2   1+0 =  1   0-1 = -1         -1
5  -2+1 = -1   1-1 =  0  -1-1 = -2         -1
6  -1+0 = -1   0-2 = -2  -2-1 = -3         -1
7  -1-2 = -3  -2-3 = -5  -3-1 = -4         -1
8  -3-5 = -8
Essentially, each cell in the generated table is the sum of the cell above it and the cell above and to the right. So, f(a) = f(a-1) + f'(a-1); f'(a) = f'(a-1) + f''(a-1); and f''(a) = f''(a-1) + f'''(a-1). The final answer is f(8) ≈ -8.††

The input list will always contain 2 or more elements, all of which will have absolute values less than 10. x ≥ 1 is also guaranteed.
The output is a single integer, the approximation of f(x). Input may be taken in either order (the list before x, or x before the list). x may also be the first or last element of the list, if desired.

Test cases:

[4, -5, 3, -1], x = 8 => -8
[1, 2, 3, 4, 5, 6], x = 10 => 3198
[1, 3, 3, 7], x = 20 => 8611
[-3, 3, -3, 3, -3, 3, -3, 3, -3], x = 15 => -9009
[1, 1], x = 1 => 2
†: it is notable that using an approximation method in this situation is, in fact, stupid. however, the simplest possible function was chosen for the purposes of this challenge.

††: the actual value happens to be -25⅓, which would qualify this approximation as "not very good."

*/

fn main() {
    assert_eq!(euler(vec![4, -5, 3, -1], 8), -8);
    assert_eq!(euler(vec![1, 2, 3, 4, 5, 6], 10), 3198);
    assert_eq!(euler(vec![1, 3, 3, 7], 20), 8611);
    assert_eq!(euler(vec![-3, 3, -3, 3, -3, 3, -3, 3, -3], 15), -9009);
    assert_eq!(euler(vec![1, 1], 1), 2);
}

fn euler(a: Vec<isize>, x: isize) -> isize {
    let n = a.len();
    if n == 0 {
        return 0;
    }

    let mut v = a.clone();
    for _ in 0..x {
        for j in 0..n - 1 {
            v[j] += v[j + 1];
        }
    }
    return v[0];
}
