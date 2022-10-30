/*

Have you heard about the mastermind Tai? He found a way to calculate the area under a glucose curve, given discrete measurement points.
He even validated his formula against the approximate technique of counting the number of squares below the graph, when printed on graph paper.

Can you, just like Tai, reinvent the wheel and calculate the area under a glucose curve?
Instead of publishing a paper, you need to implement the algorithm.
You need this algorithm in your new app, that logs your glucose values that comes from a continuous glucose monitor.
You have also figured out the trick of the device. It’s not actually continuous, it just samples the glucose value frequently, automatically.

Input

Input contains several lines of numbers separated by spaces. The first line contains the integer N, 2≤N≤10^4, the number of glucose samples.

The following N lines describe each glucose sample.

Each line contains two numbers ti, vi, where ti is the time of the sample, and vi is the glucose value at time ti.

The glucose values vi are inside the measurement domain: 2.0≤vi≤23.0 mmol/L.

Each glucose value is given with exactly one decimal digit.

Since you are working with a computer program, the time of each sample is given as an integer, the number of milliseconds since the first of January 1970.

The samples are always given in increasing order by time, meaning 0<t1<t2<⋯<tN<10^14 ms.

Note that a second is a thousand milliseconds.

Output

The area under the glucose curve in the unit mmol/L⋅s

Answers within a relative or absolute error of 10^-6 will be accepted.

Sample Explanation

In Sample Input 1 there are three data points, where the area between the t-axis and the curve is formed by two Trapezoids.
The first trapezoid have the area of 2+122⋅(2000−1000)=7000mmol/L⋅ms, making 7mmol/L⋅s. The second has an area of 17mmol/L⋅s, making the total area 24mmol/L⋅s.

*/

fn main() {
    test(vec![[1000.0, 2.0], [2000.0, 12.0], [3000.0, 22.0]], 24.0);
    test(vec![[1000.0, 4.0], [2000.0, 8.0], [3001.0, 7.3]], 13.65765);
}

fn test(a: Vec<[f64; 2]>, r: f64) {
    let p = integrate(a);
    println!("{}", p);

    let t = (p - r).abs();
    assert_eq!(t < 1e-6, true);
}

fn integrate(a: Vec<[f64; 2]>) -> f64 {
    let mut t = 0.0;
    let mut v = 0.0;
    let mut r = 0.0;
    for (i, u) in a.iter().enumerate() {
        if i > 0 {
            r += (v + u[1])*0.5 * (u[0] - t);
        }
        t = u[0];
        v = u[1];
    }
    r/1000.0
}
