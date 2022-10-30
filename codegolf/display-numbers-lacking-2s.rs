/*

Display numbers from one to one-hundred (in increasing order), but number 2 shouldn’t appear anywhere in the sequence. So, for example, the numbers two (2) or twenty-three (23) shouldn't be in the sequence.

Here is an example output, with newlines separating the numbers:

1
3
4
5
6
7
8
9
10
11
13
14
15
16
17
18
19
30
31
33
34
35
36
37
38
39
40
41
43
44
45
46
47
48
49
50
51
53
54
55
56
57
58
59
60
61
63
64
65
66
67
68
69
70
71
73
74
75
76
77
78
79
80
81
83
84
85
86
87
88
89
90
91
93
94
95
96
97
98
99
100

*/

fn main() {
    for i in 1..101 {
        let x = i % 10;
        let y = (i / 10) % 10;
        if x != 2 && y != 2 {
            println!("{}", i);
        }
    }
}
