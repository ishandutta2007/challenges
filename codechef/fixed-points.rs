/*

An index of an array is called a fixed point if the value on the index of the array is equal to the index itself.
Formally, an index i of an array A of length N is a fixed point if Ai=i, where 1≤i≤N.

For example, in the array A=[1,3,3,4,1], the indices 1,3,4 are fixed points.

Chef has an array A consisting of N integers. Chef tries to find the number of fixed points over all subarrays of the array A.
More formally, for every pair (L,R) such that 1≤L≤R≤N, Chef considers the subarray AL,AL+1,…,AR and calculates the total number of fixed points in all such subarrays.
However, Chef finds this task very hard. Can you help him find the number of fixed points over all subarrays?

Input Format

The first line contains T denoting the number of test cases. Then the test cases follow.
The first line of each test case contains an integer N, denoting the length of the array.
The second line contains N space-separated integers A1,A2,…,AN, denoting the given array.

Output Format

For each test case, print a single line containing one integer - the number of fixed points over all subarrays.

Constraints
1≤T≤10^3
1≤N≤10^5
1≤Ai≤N
Sum of N over all test caes does not exceed 5⋅10^5.

*/

fn main() {
    assert_eq!(fixed_points(vec![1, 2]), 3);
    assert_eq!(fixed_points(vec![2, 3, 2]), 1);
    assert_eq!(fixed_points(vec![1, 3, 4, 2]), 5);
}

fn fixed_points(a: Vec<usize>) -> usize {
    let (mut r, n) = (0, a.len());
    for (i, v) in a.iter().enumerate() {
        if i + 1 >= *v {
            r += n - i;
        }
    }
    r
}
