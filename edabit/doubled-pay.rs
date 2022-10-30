/*

An employee working at a very bizzare company, earns one penny on their first day.
However, for every day that passes, their base amount doubles, so they earn two pennies on the second day
and four pennies on the third day (totalling 7 pennies).
Given a number of days, return how many pennies the employee accumulates.
Examples

doubledPay(1) ➞ 1

doubledPay(2) ➞ 3

doubledPay(3) ➞ 7

Notes

You will only get tests for valid positive integers.

*/

fn main() {
    assert_eq!(doubled_pay(1), 1);
    assert_eq!(doubled_pay(2), 3);
    assert_eq!(doubled_pay(3), 7);
    assert_eq!(doubled_pay(4), 15);
    assert_eq!(doubled_pay(5), 31);
    assert_eq!(doubled_pay(6), 63);
    assert_eq!(doubled_pay(7), 127);
    assert_eq!(doubled_pay(8), 255);
    assert_eq!(doubled_pay(9), 511);
    assert_eq!(doubled_pay(10), 1023);
    assert_eq!(doubled_pay(11), 2047);
    assert_eq!(doubled_pay(12), 4095);
    assert_eq!(doubled_pay(13), 8191);
    assert_eq!(doubled_pay(14), 16383);
    assert_eq!(doubled_pay(15), 32767);
    assert_eq!(doubled_pay(16), 65535);
    assert_eq!(doubled_pay(17), 131071);
    assert_eq!(doubled_pay(18), 262143);
    assert_eq!(doubled_pay(19), 524287);
    assert_eq!(doubled_pay(20), 1048575);
    assert_eq!(doubled_pay(21), 2097151);
    assert_eq!(doubled_pay(22), 4194303);
    assert_eq!(doubled_pay(59), 576460752303423487);
    assert_eq!(doubled_pay(66), 73786976294838206463);
    assert_eq!(doubled_pay(35), 34359738367);
    assert_eq!(doubled_pay(73), 9444732965739290427391);
    assert_eq!(doubled_pay(105), 40564819207303340847894502572031);
}

fn doubled_pay(x: u128) -> u128 {
    (1 << x) - 1
}
