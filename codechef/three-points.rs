/*

There are three distinct points - A,B,C in the X−Y plane. Initially, you are located at point A. You want to reach the point C satisfying the following conditions:

You have to go through point B.
You can move in any of the four axis-parallel directions (+X, −X, +Y, −Y direction). However, you can make at most one turn in the path from A to C.
Determine if it is possible to reach the destination C satisfying the above conditions.

NOTE:

One turn means 90∘ clockwise or anticlockwise rotation along the direction of movement.
For example, if you are moving towards the +X direction, after one turn you can move either in the +Y direction or in the −Y direction.
Changing the direction by 180∘ is not allowed.

Input Format

The first line of input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers XA,YA, denoting the coordinates of the starting point A.
The second line of each test case contains two space-separated integers XB,YB, denoting the coordinates of the point B.
The third line of each test case contains two space-separated integers XC,YC, denoting the coordinates of the finishing point C.

Output Format

For each test case, print a single line containing one string - "YES"(without quotes) if it is possible to reach the finishing point satisfying the above conditions, otherwise print "NO"(without quotes).

Constraints

1≤T≤2⋅10^5
−10^9≤XA,YA,XB,YB,XC,YC≤10^9
Three points are pairwise distinct

*/

fn main() {
    assert_eq!(reachable(1, 1, 1, 3, 3, 3), true);
    assert_eq!(reachable(0, 0, 2, 2, 3, 4), false);
    assert_eq!(reachable(5, 2, 3, 2, 1, 2), true);
    assert_eq!(reachable(1, 1, -1, 1, 10000, 10000), false);
}

fn reachable(xa: isize, ya: isize, xb: isize, yb: isize, xc: isize, yc: isize) -> bool {
    let l = isize::min(xa, xc);
    let r = isize::max(xa, xc);
    let b = isize::min(ya, yc);
    let t = isize::max(ya, yc);

    if l <= xb && xb <= r && (yb == t || yb == b) {
        return true;
    }

    if b <= yb && yb <= t && (xb == l && xb == r) {
        return true;
    }

    return false;
}
