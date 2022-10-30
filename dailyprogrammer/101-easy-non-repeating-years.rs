/*

This challenge comes to us from user skeeto

Write a program to count the number years in an inclusive range of years that have no repeated digits.

For example, 2012 has a repeated digit (2) while 2013 does not. Given the range [1980, 1987], your program would return 7 (1980, 1982, 1983, 1984, 1985, 1986, 1987).

Bonus: Compute the longest run of years of repeated digits and the longest run of years of non-repeated digits for [1000, 2013].

*/

fn main() {
    non_repeating_years(1980, 1987);
    non_repeating_years(1000, 2013);
}

fn non_repeating_years(a: usize, b: usize) {
    for y in a..b+1 {
        if unique_digits(y) {
            println!("{}", y);
        }
    }
    println!();
}

fn unique_digits(mut n: usize) -> bool {
    let mut h: [usize; 10] = [0; 10];
    while n != 0 {
        let i = n % 10;
        h[i] += 1;
        if h[i] >= 2 {
            return false;
        }
        n /= 10;
    }
    return true;
}
