/*

Chef wants to order food from a food delivery app. He wishes to order once today, and buy three items costing A1,A2 and A3 rupees, respectively.
He'll also order once tomorrow, when he'll buy three items costing B1,B2 and B3 rupees, respectively.
There is an additional delivery charge of rupees D for each order.

He notices that there is a coupon on sale, which costs rupees C.
If he buys that coupon, the delivery charges on any day, on an order of rupees 150 or more shall be waived (that is, the D rupees will not be added, if the sum of the costs of the items is ≥150).

Note that Chef is ordering the three items together on each day, so the delivery charge is charged only once each day.
Also, note that it's only needed to buy the coupon once to avail the delivery fee waiver on both days.

Should Chef buy the coupon? Note that Chef shall buy the coupon only if it costs him strictly less than what it costs him without the coupon, in total.

Input:

The first line of the input contains a single integer T, denoting the number of test cases.
The first line of each test case contains two space-separated integers D and C, denoting the delivery charge, and the price of the coupon, respectively.
The second line of each test case contains three space-separated integers A1,A2 and A3, denoting the prices of the food items that Chef plans to order on Day 1, respectively.
The third line of each test case contains three space-separated integers B1, B2 and B3, denoting the prices of the food items that Chef plans to order on Day 2, respectively.

Output:

For each test case, output YES if Chef should buy the coupon, and NO otherwise, in a separate line.

Constraints
1≤T≤10^4
1≤D,C≤100
1≤A1,A2,A3≤100
1≤B1,B2,B3≤100

*/

fn main() {
    assert_eq!(coupon(90, 100, vec![100, 50, 10], vec![80, 80, 80]), true);
    assert_eq!(coupon(30, 30, vec![100, 100, 100], vec![10, 20, 30]), false);
}

fn coupon(d: isize, c: isize, a: Vec<isize>, b: Vec<isize>) -> bool {
    let (u, mut v) = (d + d, c);
    if sum(a) < 150 {
        v += d;
    }
    if sum(b) < 150 {
        v += d;
    }
    v < u
}

fn sum(a: Vec<isize>) -> isize {
    let mut r = 0;
    for v in a {
        r += v;
    }
    r
}
