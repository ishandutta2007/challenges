/*

Your task today is to write a program or function that takes an array of integers, and counts the number of times, reading it left to right, that the value changes.
This is easier to show with an example: [1 1 1 2 2 5 5 5 5 17 3] => [1 1 1 **2** 2 **5** 5 5 5 **17** **3**] => 4

Test case:

Input           |   Output
[]              |   0
[0]             |   0
[0 1]           |   1
[0 0]           |   0
[1 2 3 17]      |   3
[1 1 1 2 2 3]   |   2
[-3 3 3 -3 0]   |   3

*/

fn main() {
    assert_eq!(changes(vec![]), 0);
    assert_eq!(changes(vec![0]), 0);
    assert_eq!(changes(vec![0, 1]), 1);
    assert_eq!(changes(vec![0, 0]), 0);
    assert_eq!(changes(vec![1, 2, 3, 17]), 3);
    assert_eq!(changes(vec![1, 1, 1, 2, 2, 3]), 2);
    assert_eq!(changes(vec![-3, 3, 3, -3, 0]), 3);
}

fn changes(a: Vec<isize>) -> isize {
    if a.len() == 0 {
        return 0;
    }

    let mut c = 0;
    let mut p = a[0];
    for v in a {
        if p != v {
            p = v;
            c += 1;
        }
    }
    c
}
