/*

Two gangsters Harry and Larry had a rest at countryside. They decided to spend some time shooting, so they put several beer cans (no more than 10) on a log.
Harry started to shoot cans one after another from the leftmost to the right and Larry – from the rightmost to the left.
At some moment it happened so that they shot one and the same can.
Harry got indignant and claimed that Larry owed him a considerable sum of money because Larry deprived him of shooting some more cans.
Larry became furious and told Harry that he owed even greater sum of money to Larry because of the same reason.
They started to argufy but nobody remembered how many cans there were at the very beginning.
And no one of them was going to search cans which was shot.
Anyway, each of them remembered exactly how many cans he shot.
Determine how many cans were not shot by Harry and how many cans were not shot by Larry.

Input

The only input line contains two integers — the number of cans shot by Harry and by Larry respectively.

Output

two integers — the number of cans that were not shot by Harry and the number of cans that were not shot by Larry, respectively.

*/

fn main() {
    assert_eq!(cans(4, 7), (6, 3));
}

fn cans(h: isize, l: isize) -> (isize, isize) {
    (l - 1, h - 1)
}
