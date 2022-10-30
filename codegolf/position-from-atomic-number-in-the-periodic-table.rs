/*

Let us consider the following representation of the periodic table.

     __________________________________________________________________________
    | | 1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18 |
    |--------------------------------------------------------------------------|
    |1|  1                                                                   2 |
    | |                                                                        |
    |2|  3   4                                           5   6   7   8   9  10 |
    | |                                                                        |
    |3| 11  12                                          13  14  15  16  17  18 |
    | |                                                                        |
    |4| 19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35  36 |
    | |                                                                        |
    |5| 37  38  39  40  41  42  43  44  45  46  47  48  49  50  51  52  53  54 |
    | |                                                                        |
    |6| 55  56      72  73  74  75  76  77  78  79  80  81  82  83  84  85  86 |
    | |                                                                        |
    |7| 87  88     104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 |
    | |                                                                        |
    |8|             57  58  59  60  61  62  63  64  65  66  67  68  69  70  71 |
    | |                                                                        |
    |9|             89  90  91  92  93  94  95  96  97  98  99 100 101 102 103 |
    |__________________________________________________________________________|

Task
Produce a program that takes an atomic number as input, and outputs the row and column of the element of given atomic number.

For instance, giving the atomic number 1 should produce 1 1 (or 1, 1, or anything that looks like a vector of two 1s).

Details
The representation of the periodic table may be represented in various way. The one presented in this challenge does have the following property : Lantanides and Aktinoides are all in a dedicated row, hence there is no element that is placed at 6, 3 nor 7, 3.

You may take a look at the atomic number repartitions here.

The atomic number is at least 1, at most 118.

test cases
1 -> 1, 1
2 -> 1, 18
29 -> 4, 11
42 -> 5, 6
58 -> 8, 5
59 -> 8, 6
57 -> 8, 4
71 -> 8, 18
72 -> 6, 4
89 -> 9, 4
90 -> 9, 5
103 -> 9, 18

Scoring
This is code golf, standard rules applies, hence fewer bytes win.

*/

static PERIODIC: [[usize; 18]; 9] = [
    [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2],
    [3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 6, 7, 8, 9, 10],
    [11, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 14, 15, 16, 17, 18],
    [
        19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36,
    ],
    [
        37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54,
    ],
    [
        55, 56, 0, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86,
    ],
    [
        87, 88, 0, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118,
    ],
    [
        0, 0, 0, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71,
    ],
    [
        0, 0, 0, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103,
    ],
];

static mut LUT: [[usize; 2]; 128] = [[0; 2]; 128];

fn main() {
    init();

    assert_eq!(location(1), (1, 1));
    assert_eq!(location(2), (1, 18));
    assert_eq!(location(29), (4, 11));
    assert_eq!(location(42), (5, 6));
    assert_eq!(location(58), (8, 5));
    assert_eq!(location(59), (8, 6));
    assert_eq!(location(57), (8, 4));
    assert_eq!(location(71), (8, 18));
    assert_eq!(location(72), (6, 4));
    assert_eq!(location(89), (9, 4));
    assert_eq!(location(90), (9, 5));
    assert_eq!(location(103), (9, 18));
}

fn init() {
    for r in 0..9 {
        for c in 0..18 {
            let i = PERIODIC[r][c] as usize;
            unsafe {
                if i != 0 {
                    LUT[i][0] = r + 1;
                    LUT[i][1] = c + 1;
                }
            }
        }
    }
}

fn location(n: usize) -> (usize, usize) {
    if n >= 128 {
        (0, 0)
    } else {
        unsafe { (LUT[n][0], LUT[n][1]) }
    }
}
