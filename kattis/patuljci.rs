/*

Every day, while the dwarves are busy in the mines, Snow White prepares dinner for them; seven chairs, seven plates, seven forks and seven knives for seven hungry dwarves.

One day nine dwarves came from the mines instead of seven (nobody knows how or why), each of them claiming to be one of Snow White’s seven dwarves.

Luckily, each dwarf wears a hat with a positive integer less than 100 written on it.
Snow White, a famous mathematician, realised long ago that the sum of numbers on the hats of her seven dwarves was exactly 100.

Write a program which determines which dwarves are legit, i.e., pick seven of nine numbers that add to 100.

Input

There are 9 lines of input. Each contains an integer between 1 and 99 (inclusive). All of the numbers will be distinct. The test data will be such that there exists a unique solution.

Output

Your program must produce exactly seven lines of output – the numbers on the hats of Snow White’s seven dwarves. Output the numbers in the same order they are given in the input.

*/

fn main() {
    assert_eq!(legit(&vec![7, 8, 10, 13, 15, 19, 20, 23, 25]), vec![7, 8, 10, 13, 19, 20, 23]);
    assert_eq!(legit(&vec![8, 6, 5, 1, 37, 30, 28, 22, 36]), vec![8, 6, 5, 1, 30, 28, 22]);
}

fn legit(a: &Vec<isize>) -> Vec<isize> {
    let mut r = Vec::new();
    if a.len() != 9 {
        return r;
    }

    let mut s = 0;
    for v in a {
        s += v;
    }

    'xloop: for i in 1..9 {
        for j in 0..i {
            if s-a[i]-a[j] == 100 {
                for k in 0..9 {
                    if k != i && k != j {
                        r.push(a[k]);
                    }
                }
                break 'xloop;
            }
        }
    }
    return r;
}
