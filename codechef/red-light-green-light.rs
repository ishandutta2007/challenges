/*

“You won’t get caught if you hide behind someone.”

Sang-Woo advises Gi-Hun to hide behind someone to avoid getting shot.

Gi-Hun follows Sang-Woo's advice and hides behind Ali, who saved his life earlier. Gi-Hun and Ali both have the same height, K. Many players saw this trick and also started hiding behind Ali.

Now, there are N players standing between Gi-Hun and Ali in a straight line, with the ith player having height Hi. Gi-Hun wants to know the minimum number of players who need to get shot so that Ali is visible in his line of sight.

Note:

Line of sight is a straight line drawn between the topmost point of two objects. Ali is visible to Gi-Hun if nobody between them crosses this line.
Even if there are some players who have the same height as that of Gi-Hun and Ali, Ali will be visible in Gi-Hun's line of sight.
Gi-Hun and Ali have the same height.

Input Format

The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and K, denoting the total number of players between Gi-Hun and Ali and the height of both of them respectively.
The second line of each test case contains N space-separated integers, denoting the heights of the players between Gi-Hun and Ali.

Output Format

For each test case, output in a single line the minimum number of players who need to get shot so that Ali is visible in Gi-Hun's line of sight.

Constraints
1≤T≤10^5
1≤N≤10^5
1≤K≤10^6
1≤Hi≤10^6 for every 1≤i≤N.
The sum of N across all test cases does not exceed 5⋅10^5.

*/

fn main() {
    assert_eq!(shots(vec![2, 13, 4, 16], 10), 2);
    assert_eq!(shots(vec![9, 3, 8, 8, 4], 8), 1);
    assert_eq!(shots(vec![1, 2, 3, 4], 6), 0);
}

fn shots(a: Vec<isize>, k: isize) -> isize {
    let mut c = 0;
    for v in a {
        if v > k {
            c += 1;
        }
    }
    c
}
