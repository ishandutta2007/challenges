/*

You are given the height H (in metres) and mass M (in kilograms) of Chef. The Body Mass Index (BMI) of a person is computed as M/H^2.

Report the category into which Chef falls, based on his BMI:

Category 1: Underweight if BMI ≤18
Category 2: Normal weight if BMI ∈{19, 20,…, 24}
Category 3: Overweight if BMI ∈{25, 26,…, 29}
Category 4: Obesity if BMI ≥30

Input:

The first line of input will contain an integer, T, which denotes the number of testcases. Then the testcases follow.
Each testcase contains a single line of input, with two space separated integers, M,H, which denote the mass and height of Chef respectively.

Output:

For each testcase, output in a single line, 1,2,3 or 4, based on the category in which Chef falls.

Constraints
1≤T≤2∗10^4
1≤M≤10^4
1≤H≤10^2
Its guaranteed that H^2 divides M.

*/

fn main() {
    assert_eq!(classify(72, 2), 1);
    assert_eq!(classify(80, 2), 2);
    assert_eq!(classify(120, 2), 4);
}

fn classify(m: isize, h: isize) -> isize {
    let r = m as f64 / (h * h) as f64;
    if r <= 18.0 {
        1
    } else if r <= 24.0 {
        2
    } else if r <= 29.0 {
        3
    } else {
        4
    }
}
