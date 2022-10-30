/*

Given an integer from 1 to 999 inclusive, output a truthy value if it appears horizontally, vertically, or diagonally, either forwards or backwards, anywhere in the 3x3 square of digits 1-9 on a standard number pad:

789
456
123
If the number does not appear, output a falsy value.

The exact 65 numbers you need to output truthy for are:

1
2
3
4
5
6
7
8
9
12
14
15
21
23
24
25
26
32
35
36
41
42
45
47
48
51
52
53
54
56
57
58
59
62
63
65
68
69
74
75
78
84
85
86
87
89
95
96
98
123
147
159
258
321
357
369
456
654
741
753
789
852
951
963
987
Everything else is falsy.

The shortest code in bytes wins.

*/

fn main() {
    assert_eq!(numpad(987), true);
    assert_eq!(numpad(94), false);

    let mut c = 0;
    for i in 0..1000 {
        if numpad(i) {
            c += 1;
        }
    }
    assert_eq!(c, 65);
}

fn numpad(x: isize) -> bool {
    let vals = vec![
        1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 14, 15, 21, 23, 24, 25, 26, 32, 35, 36, 41, 42, 45, 47, 48,
        51, 52, 53, 54, 56, 57, 58, 59, 62, 63, 65, 68, 69, 74, 75, 78, 84, 85, 86, 87, 89, 95, 96,
        98, 123, 147, 159, 258, 321, 357, 369, 456, 654, 741, 753, 789, 852, 951, 963, 987,
    ];

    let r = vals.binary_search(&x);

    !r.is_err()
}
