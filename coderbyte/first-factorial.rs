/*

Have the function FirstFactorial(num) take the num parameter being passed and return the factorial of it. For example: if num = 4, then your program should return (4 * 3 * 2 * 1) = 24. For the test cases, the range will be between 1 and 18 and the input will always be an integer. 

*/

fn main() {
    for i in 0..10 {
        println!("{}: {}", i, first_factorial(i));
    }
}

fn first_factorial(n: usize) -> usize {
    let mut x = 1;
    for v in 2..n+1 {
        x *= v;
    }
    return x;
}
