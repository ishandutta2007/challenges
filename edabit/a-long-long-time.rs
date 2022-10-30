/*

Create a function that takes three values:

    h hours
    m minutes
    s seconds

Return the value that's the longest duration.
Examples

longestTime(1, 59, 3598) ➞ 1

longestTime(2, 300, 15000) ➞ 300

longestTime(15, 955, 59400) ➞ 59400

Notes

No two durations will be the same.

*/

fn main() {
    assert_eq!(longest_time(1, 59, 3598), 1);
    assert_eq!(longest_time(2, 300, 15000), 300);
    assert_eq!(longest_time(15, 955, 59400), 59400);
}

fn longest_time(h: usize, m: usize, s: usize) -> usize {
    let x = h*60*60;
    let y = m*60;
    if x > y && x > s {
        return h;
    }
    if y > x && y > s {
        return m;
    }
    return s;
}
