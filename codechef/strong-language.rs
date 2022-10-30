/*

A string is said to be using strong language if it contains at least K consecutive characters '*'.

You are given a string S with length N. Determine whether it uses strong language or not.

Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and K.
The second line contains a single string S with length N.

Output

Print a single line containing the string "YES" if the string contains strong language or "NO" if it does not (without quotes).
You may print each character of each string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
1≤T≤10
1≤K≤N≤10^6
S contains only lowercase English letters and characters '*'
Sum of N over all testcases is at most 10^6.

*/

fn main() {
    assert_eq!(strong("*a*b*", 2), false);
    assert_eq!(strong("*a**b", 2), true);
    assert_eq!(strong("abcde", 1), false);
}

fn strong(s: &'static str, k: isize) -> bool {
    let mut c = 0;
    for r in s.chars() {
        match r {
            '*' => c += 1,
            _   => c = 0,
        }
        
        if c >= k {
            return true;
        }
    }
    return false;
}
