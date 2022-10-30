/*

Little Mirko wrote into his math notebook an equation containing three positive integers, the equals sign and one of the four basic arithmetic operations (addition, subtraction, multiplication and division).

During another class, his friend Slavko erased the equals sign and the operations from Mirko’s notebook. Help Mirko by reconstructing the equation from the three integers

Input

The first line of input contains three integers less than 100, separated by spaces. The input data will guarantee that a solution, although not necessarily unique, will always exist.

Output

On a single line, output a valid equation containing the three integers (in the same order), an equals sign and one of the four operations. If there are multiple solutions, output any of them.

*/

fn main() {
    tri(5, 3, 8);
    tri(5, 15, 3);
}

fn tri(a: isize, b: isize, c: isize) {
    let (mut p, mut q) = (check(a, b, c), '=');
    if p == ' ' {
        p = '=';
        q = check(b, c, a);
    }

    println!("{}{}{}{}{}", a, p, b, q, c);
}

fn check(a: isize, b: isize, c: isize) -> char {
    if a+b == c {
        return '+';
    }
    if a-b == c {
        return '-';
    }
    if a*b == c {
        return '*';
    }
    if b != 0 && a%b == 0 && a/b == c {
        return '/';
    }
    return ' ';
}
