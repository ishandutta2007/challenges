/*

Recently Chef has decided to make some changes in our beloved Codechef.
As you know, each problem at Codechef has its memory and time limits.
To make problems even more challenging, he decided to measure allocated memory in a different way.
Now judge program will be calculating not the maximum memory usage during the execution of all test files, but all the memory ever allocated by the solution program.
But as Chef is not that good in algorithms, so he asks you to write a program that will calculate total memory usage of a solution.

So, you are given N numbers M1...MN representing the measurements of consumed memory (in MBs) for N test files.
In other terms, it means that on i-th test file, program took Mi MBs of memory.
Initially, there is no memory allocated for your program.
Before running your program on each test file, if the currently allocated memory is more than memory needed for the current test file, then there will be a deallocation of the memory to fit the current program.
Also, if there is less than needed memory available, then allocation of memory will happen so as to fit the current program. e.g. Let us say that our program took 10 MBs on current test file.
So, assuming if there was 12 MBs memory allocated before running the program on current test file, then there will happen a deallocation of 2 MBs.
Assuming if there was 8 MBs memory allocated before running the program on current test file, then there will happen a allocation of 2 MBs.

Calculate the total memory allocated for running the solution program on all the N test files. Please see third sample for more clarity.

Input

First line of input contains a single integer T denoting the number of test cases.
First line of each test case contains a single integer N denoting the number of measurements.
Second line of each test case contains N space separated integers, where ith integer denotes the consumption of memory for ith i-th test file.

Output

For each test case, print total memory allocated for running the solution program.

Constraints
1 ≤ T ≤ 10^5
1 ≤ N ≤ 10^5
1 ≤ Mi ≤ 10^9
sum of N over all test cases does not exceed 10^5

*/

fn main() {
    assert_eq!(allocated(vec![1, 1]), 1);
    assert_eq!(allocated(vec![1, 2, 3, 4, 5]), 5);
    assert_eq!(allocated(vec![1, 3, 2]), 3);
}

fn allocated(a: Vec<usize>) -> usize {
    let mut r = 0;
    let mut l = 0;
    for v in a {
        if v > l {
            r += v - l;
        }
        l = v;
    }
    r
}
