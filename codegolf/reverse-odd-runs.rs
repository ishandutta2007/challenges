/*

Inspiration.
https://codegolf.stackexchange.com/questions/59299/math-in-manhattan

Task
Reverse runs of odd numbers in a given list of 2 to 215 non-negative integers.

Examples
0 1 → 0 1
1 3 → 3 1
1 2 3 → 1 2 3
1 3 2 → 3 1 2
10 7 9 6 8 9 → 10 9 7 6 8 9
23 12 32 23 25 27 → 23 12 32 27 25 23
123 123 345 0 1 9 → 345 123 123 0 9 1

*/

fn main() {
    assert_eq!(ror(&mut vec![0, 1]), &vec![0, 1]);
    assert_eq!(ror(&mut vec![1, 3]), &vec![3, 1]);
    assert_eq!(ror(&mut vec![1, 2, 3]), &vec![1, 2, 3]);
    assert_eq!(ror(&mut vec![1, 3, 2]), &vec![3, 1, 2]);
    assert_eq!(ror(&mut vec![10, 7, 9, 6, 8, 9]), &vec![10, 9, 7, 6, 8, 9]);
    assert_eq!(
        ror(&mut vec![23, 12, 32, 23, 25, 27]),
        &vec![23, 12, 32, 27, 25, 23]
    );
    assert_eq!(
        ror(&mut vec![123, 123, 345, 0, 1, 9]),
        &vec![345, 123, 123, 0, 9, 1]
    );
}

fn ror(a: &mut Vec<isize>) -> &Vec<isize> {
    let (mut i, n) = (0, a.len());
    while i < n {
        let mut j = i + 1;
        if (a[i] & 1) != 0 {
            while j < n && (a[j] & 1) != 0 {
                j += 1;
            }
            rev(a, i, j);
        }
        i = j;
    }
    a
}

fn rev(a: &mut Vec<isize>, mut i: usize, mut j: usize) {
    while i < j {
        (a[i], a[j - 1]) = (a[j - 1], a[i]);
        i += 1;
        j -= 1;
    }
}
