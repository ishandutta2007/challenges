/*

Given a two digit number, return true if that number contains one even and one odd digit.
Examples

oneOddOneEven(12) ➞ true

oneOddOneEven(55) ➞ false

oneOddOneEven(22) ➞ false

*/

fn main() {
    assert_eq!(one_odd_one_even(10), true);
    assert_eq!(one_odd_one_even(11), false);
    assert_eq!(one_odd_one_even(12), true);
    assert_eq!(one_odd_one_even(13), false);
    assert_eq!(one_odd_one_even(14), true);
    assert_eq!(one_odd_one_even(15), false);
    assert_eq!(one_odd_one_even(16), true);
    assert_eq!(one_odd_one_even(17), false);
    assert_eq!(one_odd_one_even(18), true);
    assert_eq!(one_odd_one_even(19), false);
    assert_eq!(one_odd_one_even(20), false);
    assert_eq!(one_odd_one_even(21), true);
    assert_eq!(one_odd_one_even(22), false);
    assert_eq!(one_odd_one_even(23), true);
    assert_eq!(one_odd_one_even(24), false);
    assert_eq!(one_odd_one_even(25), true);
    assert_eq!(one_odd_one_even(26), false);
    assert_eq!(one_odd_one_even(27), true);
    assert_eq!(one_odd_one_even(28), false);
    assert_eq!(one_odd_one_even(29), true);
    assert_eq!(one_odd_one_even(30), true);
    assert_eq!(one_odd_one_even(31), false);
    assert_eq!(one_odd_one_even(32), true);
    assert_eq!(one_odd_one_even(33), false);
    assert_eq!(one_odd_one_even(34), true);
    assert_eq!(one_odd_one_even(35), false);
    assert_eq!(one_odd_one_even(36), true);
    assert_eq!(one_odd_one_even(37), false);
    assert_eq!(one_odd_one_even(38), true);
    assert_eq!(one_odd_one_even(39), false);
    assert_eq!(one_odd_one_even(40), false);
    assert_eq!(one_odd_one_even(41), true);
    assert_eq!(one_odd_one_even(42), false);
    assert_eq!(one_odd_one_even(43), true);
    assert_eq!(one_odd_one_even(44), false);
    assert_eq!(one_odd_one_even(45), true);
    assert_eq!(one_odd_one_even(46), false);
    assert_eq!(one_odd_one_even(47), true);
    assert_eq!(one_odd_one_even(48), false);
    assert_eq!(one_odd_one_even(49), true);
    assert_eq!(one_odd_one_even(50), true);
    assert_eq!(one_odd_one_even(51), false);
    assert_eq!(one_odd_one_even(52), true);
    assert_eq!(one_odd_one_even(53), false);
    assert_eq!(one_odd_one_even(54), true);
    assert_eq!(one_odd_one_even(55), false);
    assert_eq!(one_odd_one_even(56), true);
    assert_eq!(one_odd_one_even(57), false);
    assert_eq!(one_odd_one_even(58), true);
    assert_eq!(one_odd_one_even(59), false);
    assert_eq!(one_odd_one_even(60), false);
    assert_eq!(one_odd_one_even(61), true);
    assert_eq!(one_odd_one_even(62), false);
    assert_eq!(one_odd_one_even(63), true);
    assert_eq!(one_odd_one_even(64), false);
    assert_eq!(one_odd_one_even(65), true);
    assert_eq!(one_odd_one_even(66), false);
    assert_eq!(one_odd_one_even(67), true);
    assert_eq!(one_odd_one_even(68), false);
    assert_eq!(one_odd_one_even(69), true);
    assert_eq!(one_odd_one_even(70), true);
    assert_eq!(one_odd_one_even(71), false);
    assert_eq!(one_odd_one_even(72), true);
    assert_eq!(one_odd_one_even(73), false);
    assert_eq!(one_odd_one_even(74), true);
    assert_eq!(one_odd_one_even(75), false);
    assert_eq!(one_odd_one_even(76), true);
    assert_eq!(one_odd_one_even(77), false);
    assert_eq!(one_odd_one_even(78), true);
    assert_eq!(one_odd_one_even(79), false);
    assert_eq!(one_odd_one_even(80), false);
    assert_eq!(one_odd_one_even(81), true);
    assert_eq!(one_odd_one_even(82), false);
    assert_eq!(one_odd_one_even(83), true);
    assert_eq!(one_odd_one_even(84), false);
    assert_eq!(one_odd_one_even(85), true);
    assert_eq!(one_odd_one_even(86), false);
    assert_eq!(one_odd_one_even(87), true);
    assert_eq!(one_odd_one_even(88), false);
    assert_eq!(one_odd_one_even(89), true);
    assert_eq!(one_odd_one_even(90), true);
    assert_eq!(one_odd_one_even(91), false);
    assert_eq!(one_odd_one_even(92), true);
    assert_eq!(one_odd_one_even(93), false);
    assert_eq!(one_odd_one_even(94), true);
    assert_eq!(one_odd_one_even(95), false);
    assert_eq!(one_odd_one_even(96), true);
    assert_eq!(one_odd_one_even(97), false);
    assert_eq!(one_odd_one_even(98), true);
    assert_eq!(one_odd_one_even(99), false);
}

fn one_odd_one_even(n: isize) -> bool {
    if !(10 <= n && n <= 99) {
        return false;
    }
    return ((n%10) ^ (n/10))&1 != 0;
}
