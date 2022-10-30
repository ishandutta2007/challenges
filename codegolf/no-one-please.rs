/*

I absolutely hate the digit 1. So, I need your help to convert numbers to their "proper forms".

Numbers in proper form never have two 1s in a row. 101 is okay, but 110 is hideous.

To convert, simply skip all the improper numbers and count normally. For instance...

1 -> 1
2 -> 2
...
10 -> 10
11 -> 12
12 -> 13
...
108 -> 109
109 -> 120
110 -> 121
111 -> 122

and so on.

Your program should take an integer and output it in proper form. This is code-golf, so shortest code in bytes wins.

*/

fn main() {
    assert_eq!(seq(1), 1);
    assert_eq!(seq(2), 2);
    assert_eq!(seq(10), 10);
    assert_eq!(seq(11), 12);
    assert_eq!(seq(12), 13);
    assert_eq!(seq(108), 109);
    assert_eq!(seq(109), 120);
    assert_eq!(seq(110), 121);
    assert_eq!(seq(111), 122);
}

fn seq(n: usize) -> usize {
    let mut r = 0;
    for _ in 0..n {
        loop {
            r += 1;
            if !ones(r) {
                break;
            }
        }
    }
    r
}

fn ones(mut n: usize) -> bool {
    while n > 10 {
        let x = n % 10;
        let y = (n / 10) % 10;
        if x == 1 && y == 1 {
            return true;
        }
        n /= 10;
    }
    return false;
}
