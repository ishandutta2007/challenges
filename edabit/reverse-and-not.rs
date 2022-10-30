/*

Write a function that takes an integer i and returns an integer with the integer backwards followed by the original integer.

To illustrate:

123

We reverse 123 to get 321 and then add 123 to the end, resulting in 321123.
Examples

reverseAndNot(123) ➞ 321123

reverseAndNot(152) ➞ 251152

reverseAndNot(123456789) ➞ 987654321123456789

Notes

i is a non-negative integer.

*/

fn main() {
    assert_eq!(reverse_and_not(123), 321123);
    assert_eq!(reverse_and_not(123456789), 987654321123456789);
    assert_eq!(reverse_and_not(496), 694496);
    assert_eq!(reverse_and_not(307), 703307);
    assert_eq!(reverse_and_not(500), 5500);
    assert_eq!(reverse_and_not(321), 123321);
    assert_eq!(reverse_and_not(564), 465564);
    assert_eq!(reverse_and_not(66), 6666);
    assert_eq!(reverse_and_not(553), 355553);
    assert_eq!(reverse_and_not(518), 815518);
    assert_eq!(reverse_and_not(152), 251152);
    assert_eq!(reverse_and_not(273), 372273);
    assert_eq!(reverse_and_not(603), 306603);
    assert_eq!(reverse_and_not(864), 468864);
    assert_eq!(reverse_and_not(170), 71170);
    assert_eq!(reverse_and_not(96), 6996);
    assert_eq!(reverse_and_not(869), 968869);
    assert_eq!(reverse_and_not(960), 69960);
    assert_eq!(reverse_and_not(471), 174471);
    assert_eq!(reverse_and_not(925), 529925);
    assert_eq!(reverse_and_not(235), 532235);
    assert_eq!(reverse_and_not(389), 983389);
    assert_eq!(reverse_and_not(293), 392293);
    assert_eq!(reverse_and_not(586), 685586);
    assert_eq!(reverse_and_not(218), 812218);
    assert_eq!(reverse_and_not(262), 262262);
    assert_eq!(reverse_and_not(610), 16610);
    assert_eq!(reverse_and_not(75), 5775);
    assert_eq!(reverse_and_not(699), 996699);
    assert_eq!(reverse_and_not(298), 892298);
    assert_eq!(reverse_and_not(532), 235532);
    assert_eq!(reverse_and_not(211), 112211);
    assert_eq!(reverse_and_not(602), 206602);
    assert_eq!(reverse_and_not(804), 408804);
    assert_eq!(reverse_and_not(195), 591195);
    assert_eq!(reverse_and_not(271), 172271);
    assert_eq!(reverse_and_not(449), 944449);
    assert_eq!(reverse_and_not(938), 839938);
    assert_eq!(reverse_and_not(257), 752257);
    assert_eq!(reverse_and_not(205), 502205);
    assert_eq!(reverse_and_not(345), 543345);
    assert_eq!(reverse_and_not(365), 563365);
    assert_eq!(reverse_and_not(112), 211112);
    assert_eq!(reverse_and_not(792), 297792);
    assert_eq!(reverse_and_not(777), 777777);
    assert_eq!(reverse_and_not(759), 957759);
    assert_eq!(reverse_and_not(239), 932239);
    assert_eq!(reverse_and_not(469), 964469);
    assert_eq!(reverse_and_not(953), 359953);
    assert_eq!(reverse_and_not(574), 475574);
    assert_eq!(reverse_and_not(155), 551155);
    assert_eq!(reverse_and_not(238), 832238);
}

fn reverse_and_not(n: usize) -> usize {
    let x = format!("{}", n);
    let y: String = x.chars().rev().collect();
    let s = format!("{}{}", y, x);
    return s.parse::<usize>().unwrap();
}
