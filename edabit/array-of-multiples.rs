/*

Create a function that takes two numbers as arguments (num, length) and returns an array of multiples of num up to length.
Examples

arrayOfMultiples(7, 5) ➞ [7, 14, 21, 28, 35]

arrayOfMultiples(12, 10) ➞ [12, 24, 36, 48, 60, 72, 84, 96, 108, 120]

arrayOfMultiples(17, 6) ➞ [17, 34, 51, 68, 85, 102]

Notes

Notice that num is also included in the returned array.

*/

fn main() {
    assert_eq!(array_of_multiples(7, 5), vec![7, 14, 21, 28, 35]);
    assert_eq!(array_of_multiples(12, 10), vec![12, 24, 36, 48, 60, 72, 84, 96, 108, 120]);
    assert_eq!(array_of_multiples(17, 7), vec![17, 34, 51, 68, 85, 102, 119]);
    assert_eq!(array_of_multiples(630, 14), vec![630, 1260, 1890, 2520, 3150, 3780, 4410, 5040, 5670, 6300, 6930, 7560, 8190, 8820]);
    assert_eq!(array_of_multiples(140, 3), vec![140, 280, 420]);
    assert_eq!(array_of_multiples(7, 8), vec![7, 14, 21, 28, 35, 42, 49, 56]);
    assert_eq!(array_of_multiples(11, 21), vec![11, 22, 33, 44, 55, 66, 77, 88, 99, 110, 121, 132, 143, 154, 165, 176, 187, 198, 209, 220, 231]);
}

fn array_of_multiples(x: isize, n: isize) -> Vec<isize> {
    let mut p = vec![];
    for i in 1..n+1 {
        p.push(x*i);
    }
    return p;
}
