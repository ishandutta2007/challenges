/*

One day, little Mirko came across a funny looking machine! It consisted of a very very large screen and a single button. When he found the machine, the screen displayed only the letter A.
After he pressed the button, the letter changed to B. The next few times he pressed the button, the word transformed from B to BA, then to BAB, then to BABBA...
When he saw this, Mirko realized that the machine alters the word in a way that all the letters B get transformed to BA and all the letters A get transformed to B.

Amused by the machine, Mirko asked you a very difficult question! After K times of pressing the button, how many letters A and how much letters B will be displayed on the screen?

Input

The first line of input contains the integer K (1≤K≤45), the number of times Mirko pressed the button.

Output

The first and only line of output must contain two space-separated integers, the number of letters A and the number of letter B.

*/

fn main() {
    assert_eq!(letters(1), (0, 1));
    assert_eq!(letters(4), (2, 3));
    assert_eq!(letters(10), (34, 55));
}

fn letters(n: u128) -> (u128, u128) {
    return (fib(n - 1), fib(n));
}

fn fib(n: u128) -> u128 {
    let (mut a, mut b) = (0, 1);
    for _ in 0..n {
        let c = a + b;
        a = b;
        b = c;
    }
    a
}
