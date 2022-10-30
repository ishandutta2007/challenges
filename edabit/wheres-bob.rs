/*

Write a function that searches an array of names (unsorted) for the name "Bob" and returns the location in the array. If Bob is not in the array, return -1.
Examples

findBob(["Jimmy", "Layla", "Bob"]) ➞ 2

findBob(["Bob", "Layla", "Kaitlyn", "Patricia"]) ➞ 0

findBob(["Jimmy", "Layla", "James"]) ➞ -1

Notes

Assume all names start with a capital letter and are lowercase thereafter (i.e. don't worry about finding "BOB" or "bob").

*/

fn main() {
    assert_eq!(find_bob(&vec!["Jimmy", "Layla", "Bob"]), 2);
    assert_eq!(find_bob(&vec!["Bob", "Layla", "Kaitlyn", "Patricia"]), 0);
    assert_eq!(find_bob(&vec!["Jimmy", "Layla", "James"]), -1);
    assert_eq!(find_bob(&vec!["Jimmy", "Layla", "Mandy"]), -1);
    assert_eq!(find_bob(&vec!["Bob", "Nathan", "Hayden"]), 0);
    assert_eq!(find_bob(&vec!["Paul", "Layla", "Bob"]), 2);
    assert_eq!(find_bob(&vec!["Garry", "Maria", "Bethany", "Bob", "Pauline"]), 3);
}

fn find_bob(p: &Vec<&str>) -> isize {
    for i in 0..p.len() {
        if p[i] == "Bob" {
            return i as isize;
        }
    }
    return -1;
}
