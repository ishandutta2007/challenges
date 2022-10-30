/*

Suppose the population is divided into the age groups [1,10],[11,20],[21,30],…,[91,∞). The age groups are numbered from 1 to 10 and there are Xi people in age group i.

The COVID vaccine drive has started and people will be vaccinated in the decreasing order of their age groups.
Suppose P people are vaccinated per day and if less than P people are left in an age group,
then the remaining doses for that day are given to the people of immediate lower age group and the process for that day continues until the vaccines for that day are finished or the entire population has been vaccinated.
The selection of a person from a given age group is done randomly.

Given X, P, and Chef’s age group G, tell the minimum and the maximum number of days will it take for Chef to get vaccinated.

Input

The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, twelve integers G, P, X1,X2,…,X10.

Output

For each test case, output in a single line two space-separated integers, the minimum and maximum time required for Chef to get vaccinated.

Constraints
1≤T≤10^4
1≤G≤10
1≤P,Xi≤10^5

*/

fn main() {
    assert_eq!(days(5, 2, [2, 2, 2, 2, 2, 2, 2, 2, 2, 2]), (6, 6));
    assert_eq!(days(5, 2, [2, 2, 2, 2, 2, 3, 2, 2, 2, 2]), (6, 7));
    assert_eq!(days(9, 4, [2, 2, 2, 2, 3, 2, 2, 2, 2, 2]), (1, 1));
}

fn days(g: usize, p: usize, x: [usize; 10]) -> (usize, usize) {
    let mut c = 0;
    let mut i = g;
    while i < 10 {
        c += x[i];
        i += 1;
    }
    (measure(c + 1, p), measure(c + x[g - 1], p))
}

fn measure(c: usize, p: usize) -> usize {
    let mut r = c / p;
    if c % p != 0 {
        r += 1;
    }
    r
}
