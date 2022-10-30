/*

For this challenge, a linked list looks like this:

[1, 2, 4, 0, 6, 1, 3, 1]
You'll notice there's no data; each item in the list is just a reference to the index of the next one.
Your task is to write a program or function which will follow a linked list like this forever, outputting each item as it is encountered.
For example, for the above input:

[1, 2, 4, 6, 3, 0, 1, ...]
Input and output can be represented in any reasonable manner.
All numbers in the input will be valid indices in the list, and you can choose if it's 0- or 1-indexed.
The output will be infinite, and as long as your program would theoretically give a correct result given infinite time and resources it's valid.

Test cases:

Zero indexed, using lists.

[0]         -> [0, 0, ...]
[1, 0]      -> [1, 0, 1, ...]
[0, 1, 2]   -> [0, 0, ...]
[2, 1, 0]   -> [2, 0, 2, ...]
[4]         -> (does not need to be handled)

*/

fn main() {
    follow(vec![0], 2);
    follow(vec![1, 0], 2);
    follow(vec![2, 1, 0], 2);
    follow(vec![4], 1);
}

fn follow(a: Vec<usize>, n: usize) {
    let (mut i, mut m) = (0, 0);
    loop {
        if i >= a.len() || (n > 0 && m >= n) {
            break;
        }
        println!("{}", a[i]);
        i = a[i];
        m = m + 1;
    }
}
