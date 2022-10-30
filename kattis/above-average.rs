/*

It is said that 90% of frosh expect to be above average in their class. You are to provide a reality check.

Input

The first line of standard input contains an integer 1≤C≤50, the number of test cases.
C data sets follow. Each data set begins with an integer, N, the number of people in the class (1≤N≤1000).
N integers follow, separated by spaces or newlines, each giving the final grade (an integer between 0 and 100) of a student in the class.

Output

For each case you are to output a line giving the percentage of students whose grade is above average, rounded to exactly 3 decimal places.

*/

fn main() {
    test(&vec![50.0, 50.0, 70.0, 80.0, 100.0], 40.000);
    test(&vec![100.0, 95.0, 90.0, 80.0, 70.0, 60.0, 50.0], 57.143);
    test(&vec![70.0, 90.0, 80.0], 33.333);
    test(&vec![70.0, 90.0, 81.0], 66.667);
    test(&vec![100.0, 99.0, 98.0, 97.0, 96.0, 95.0, 94.0, 93.0, 91.0], 55.556);
}

fn test(a: &Vec<f64>, r: f64) {
    let p = percentage(a);
    println!("{}", p);
    assert_eq!((p - r).abs() < 1e-3, true);
}

fn percentage(a: &Vec<f64>) -> f64 {
    let n = a.len() as f64;

    let mut x = 0.0;
    for v in a {
        x += v;
    }
    x /= n;

    let mut y = 0.0;
    for v in a {
        if v > &x {
            y += 1.0;
        }
    }

    (y / n) * 100.0
}
