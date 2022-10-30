/*

Peter is expecting a large shipment of fuel oil, but he has a small problem (doesn’t everyone in these programming problems!).
The only containers he has are a set of large bottles (each with the same volume) and a set of smaller bottles (also each with the same, but smaller volume).
Given the volume of the shipment of oil, he would like to store the oil in the bottles so that

    all of the oil is stored,

    each bottle is filled to the top, and

    the minimum number of bottles is used.

While Peter thinks he has solved this problem for his given bottle sizes, he often spends hours wondering what would happen if his bottles had different volumes (apparently Peter doesn’t lead the most exciting life).
Input

The input consists of a single line containing three positive integers s, v1, v2, where s≤106 is the volume of the shipment, and v1,v2≤106 are the volumes of the two types of bottles, with v1>v2.

Output

Output the number of bottles of size v1 and the number of bottles of size v2 which satisfy Peter’s two conditions. If the conditions cannot be met, output Impossible.

*/

fn main() {
    assert_eq!(bottles(1000, 9, 7), (108, 4)); 
    assert_eq!(bottles(1000, 900, 7), (-1, -1)); 
    assert_eq!(bottles(1000, 10, 7), (100, 0)); 
}

fn bottles(s: isize, v1: isize, v2: isize) -> (isize, isize) {
    let mut i = s / v1;
    while i >= 0 {
        let r = s - i*v1;
        if r%v2 == 0 {
            return (i, r / v2);
        }
        i -= 1;
    }
    return (-1, -1);
}
