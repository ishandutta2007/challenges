#!/usr/bin/env python

"""

Given a positive integer n and another positive integer b (1<b<36), return the number of digits/length of n in base b

1597 16 -> 3
1709 9 -> 4
190 29 -> 2
873 24 -> 3
1061 27 -> 3
289 26 -> 2
1575 34 -> 3
1135 15 -> 3
1161 22 -> 3
585 23 -> 3
1412 23 -> 3
1268 14 -> 3
714 12 -> 3
700 29 -> 2
1007 35 -> 2
292 17 -> 3
1990 16 -> 3
439 3 -> 6
1212 17 -> 3
683 31 -> 2
535 25 -> 2
1978 32 -> 3
153 8 -> 3
1314 33 -> 3
433 2 -> 9
655 35 -> 2
865 19 -> 3
1947 25 -> 3
1873 32 -> 3
1441 12 -> 3
228 30 -> 2
947 2 -> 10
1026 11 -> 3
1172 24 -> 3
1390 32 -> 3
1495 21 -> 3
1339 10 -> 4
1357 9 -> 4
1320 27 -> 3
602 5 -> 4
1462 16 -> 3
1658 9 -> 4
519 11 -> 3
159 3 -> 5
1152 11 -> 3
1169 33 -> 3
1298 7 -> 4
1686 32 -> 3
1227 25 -> 3
770 15 -> 3
1478 20 -> 3
401 22 -> 2
1097 7 -> 4
1017 9 -> 4
784 23 -> 3
1176 15 -> 3
1521 7 -> 4
1623 23 -> 3
1552 13 -> 3
819 15 -> 3
272 32 -> 2
1546 12 -> 3
1718 4 -> 6
1686 8 -> 4
1128 2 -> 11
1617 34 -> 3
1199 34 -> 3
626 23 -> 3
991 9 -> 4
742 22 -> 3
1227 11 -> 3
1897 12 -> 4
348 35 -> 2
1107 11 -> 3
31 26 -> 2
1153 26 -> 3
432 4 -> 5
758 9 -> 4
277 21 -> 2
472 29 -> 2
1935 21 -> 3
457 27 -> 2
1807 26 -> 3
1924 26 -> 3
23 27 -> 1
558 30 -> 2
203 15 -> 2
1633 8 -> 4
769 21 -> 3
1261 32 -> 3
577 7 -> 4
1440 22 -> 3
1215 35 -> 2
1859 23 -> 3
1702 35 -> 3
1580 12 -> 3
782 15 -> 3
701 32 -> 2
177 24 -> 2
1509 28 -> 3

"""

def int2base(n, b):
    if n == 0:
        return [0]
    d = []
    while n != 0:
        d.append(int(n % b))
        n //= b
    return d[::-1]

def dibl(n, b):
    return len(int2base(n, b))

def main():
    assert(dibl(1597, 16) == 3)
    assert(dibl(1709, 9) == 4)
    assert(dibl(190, 29) == 2)
    assert(dibl(873, 24) == 3)
    assert(dibl(1061, 27) == 3)
    assert(dibl(289, 26) == 2)
    assert(dibl(1575, 34) == 3)
    assert(dibl(1135, 15) == 3)
    assert(dibl(1161, 22) == 3)
    assert(dibl(585, 23) == 3)
    assert(dibl(1412, 23) == 3)
    assert(dibl(1268, 14) == 3)
    assert(dibl(714, 12) == 3)
    assert(dibl(700, 29) == 2)
    assert(dibl(1007, 35) == 2)
    assert(dibl(292, 17) == 3)
    assert(dibl(1990, 16) == 3)
    assert(dibl(439, 3) == 6)
    assert(dibl(1212, 17) == 3)
    assert(dibl(683, 31) == 2)
    assert(dibl(535, 25) == 2)
    assert(dibl(1978, 32) == 3)
    assert(dibl(153, 8) == 3)
    assert(dibl(1314, 33) == 3)
    assert(dibl(433, 2) == 9)
    assert(dibl(655, 35) == 2)
    assert(dibl(865, 19) == 3)
    assert(dibl(1947, 25) == 3)
    assert(dibl(1873, 32) == 3)
    assert(dibl(1441, 12) == 3)
    assert(dibl(228, 30) == 2)
    assert(dibl(947, 2) == 10)
    assert(dibl(1026, 11) == 3)
    assert(dibl(1172, 24) == 3)
    assert(dibl(1390, 32) == 3)
    assert(dibl(1495, 21) == 3)
    assert(dibl(1339, 10) == 4)
    assert(dibl(1357, 9) == 4)
    assert(dibl(1320, 27) == 3)
    assert(dibl(602, 5) == 4)
    assert(dibl(1462, 16) == 3)
    assert(dibl(1658, 9) == 4)
    assert(dibl(519, 11) == 3)
    assert(dibl(159, 3) == 5)
    assert(dibl(1152, 11) == 3)
    assert(dibl(1169, 33) == 3)
    assert(dibl(1298, 7) == 4)
    assert(dibl(1686, 32) == 3)
    assert(dibl(1227, 25) == 3)
    assert(dibl(770, 15) == 3)
    assert(dibl(1478, 20) == 3)
    assert(dibl(401, 22) == 2)
    assert(dibl(1097, 7) == 4)
    assert(dibl(1017, 9) == 4)
    assert(dibl(784, 23) == 3)
    assert(dibl(1176, 15) == 3)
    assert(dibl(1521, 7) == 4)
    assert(dibl(1623, 23) == 3)
    assert(dibl(1552, 13) == 3)
    assert(dibl(819, 15) == 3)
    assert(dibl(272, 32) == 2)
    assert(dibl(1546, 12) == 3)
    assert(dibl(1718, 4) == 6)
    assert(dibl(1686, 8) == 4)
    assert(dibl(1128, 2) == 11)
    assert(dibl(1617, 34) == 3)
    assert(dibl(1199, 34) == 3)
    assert(dibl(626, 23) == 3)
    assert(dibl(991, 9) == 4)
    assert(dibl(742, 22) == 3)
    assert(dibl(1227, 11) == 3)
    assert(dibl(1897, 12) == 4)
    assert(dibl(348, 35) == 2)
    assert(dibl(1107, 11) == 3)
    assert(dibl(31, 26) == 2)
    assert(dibl(1153, 26) == 3)
    assert(dibl(432, 4) == 5)
    assert(dibl(758, 9) == 4)
    assert(dibl(277, 21) == 2)
    assert(dibl(472, 29) == 2)
    assert(dibl(1935, 21) == 3)
    assert(dibl(457, 27) == 2)
    assert(dibl(1807, 26) == 3)
    assert(dibl(1924, 26) == 3)
    assert(dibl(23, 27) == 1)
    assert(dibl(558, 30) == 2)
    assert(dibl(203, 15) == 2)
    assert(dibl(1633, 8) == 4)
    assert(dibl(769, 21) == 3)
    assert(dibl(1261, 32) == 3)
    assert(dibl(577, 7) == 4)
    assert(dibl(1440, 22) == 3)
    assert(dibl(1215, 35) == 2)
    assert(dibl(1859, 23) == 3)
    assert(dibl(1702, 35) == 3)
    assert(dibl(1580, 12) == 3)
    assert(dibl(782, 15) == 3)
    assert(dibl(701, 32) == 2)
    assert(dibl(177, 24) == 2)
    assert(dibl(1509, 28) == 3)

main()
