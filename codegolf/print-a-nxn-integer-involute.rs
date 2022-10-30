/*

Given an integer N, you must print a N×N integer involute with the numbers increasing in a clockwise rotation. You can start with either 0 or 1 at the top left, increasing as you move towards the centre.

Examples
Input => 1
Output => 
0

Input => 2
Output => 
0 1
3 2

Input => 5
Output => 
 0  1  2  3 4
15 16 17 18 5
14 23 24 19 6
13 22 21 20 7
12 11 10  9 8 

Input => 10
Output => 
 0  1  2  3  4  5  6  7  8  9
35 36 37 38 39 40 41 42 43 10
34 63 64 65 66 67 68 69 44 11
33 62 83 84 85 86 87 70 45 12
32 61 82 95 96 97 88 71 46 13
31 60 81 94 99 98 89 72 47 14
30 59 80 93 92 91 90 73 48 15
29 58 79 78 77 76 75 74 49 16
28 57 56 55 54 53 52 51 50 17
27 26 25 24 23 22 21 20 19 18

You may output a 2 dimensional array, or a grid of numbers.

Challenge inspired by Article by Eugene McDonnell

*/

fn main() {
    involute(1);
    involute(2);
    involute(5);
    involute(10);
}

fn involute(n: usize) {
    if n == 0 {
        return;
    }

    let mut m = vec![0; n * n];
    let mut v = 0;

    let l = n as isize;
    let w = (l as f64).log10().ceil() + 1.0;

    let mut set = |x: isize, y: isize| {
        (m[(y * l + x) as usize], v) = (v, v + 1);
    };

    let (mut x0, mut y0) = (0, 0);
    let (mut x1, mut y1) = (l - 1, l - 1);
    loop {
        if x0 == x1 && y0 == y1 {
            set(x0, y0);
        }

        if x0 >= x1 || y0 >= y1 {
            break;
        }

        let (mut x, mut y) = (x0, y0);
        while x <= x1 {
            set(x, y);
            x += 1;
        }

        (x, y) = (x1, y0 + 1);
        while y <= y1 {
            set(x, y);
            y += 1;
        }

        (x, y) = (x1 - 1, y1);
        while x >= x0 {
            set(x, y);
            x -= 1;
        }

        (x, y) = (x0, y1 - 1);
        while y > y0 {
            set(x, y);
            y -= 1;
        }

        (x0, y0) = (x0 + 1, y0 + 1);
        (x1, y1) = (x1 - 1, y1 - 1);
    }

    let mut i = 0;
    println!("N={}", n);
    for _ in 0..l {
        for _ in 0..l {
            print!("{:w$} ", m[i], w = w as usize);
            i += 1;
        }
        println!();
    }
    println!();
}
