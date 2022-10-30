/*

Most programmers will tell you that one of the ways to improve your performance in competitive programming is to practice a lot of problems.

Our Chef took the above advice very seriously and decided to set a target for himself.

Chef decides to solve at least 10 problems every week for 4 weeks.

Given the number of problems he actually solved in each week over 4 weeks as P1,P2,P3, and P4, output the number of weeks in which Chef met his target.

Input Format

There is a single line of input, with 4 integers P1,P2,P3, and P4. These are the number of problems solved by Chef in each of the 4 weeks.

Output Format

Output a single integer in a single line - the number of weeks in which Chef solved at least 10 problems.

Constraints
1≤P1,P2,P3,P4≤100

*/

fn main() {
    assert_eq!(weeks(12, 15, 8, 10), 3);
}

fn weeks(p1: isize, p2: isize, p3: isize, p4: isize) -> isize {
    let mut c = 0;
    for p in vec![p1, p2, p3, p4] {
        if p >= 10 {
            c += 1
        }
    }
    c
}
