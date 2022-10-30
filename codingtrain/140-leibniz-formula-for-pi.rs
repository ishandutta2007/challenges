fn main() {
    for i in 1..1000 {
        println!("{}", pi(i));
    }
}

// 1 - 1/3 + 1/5 - 1/7 + 1/9 ... = pi/4
fn pi(n: isize) -> f64 {
    let (mut r, mut s) = (0.0, 1.0);
    for i in 0..n {
        r += s / (2.0*i as f64 + 1.0);
        s = -s;
    }
    return 4.0*r;
}
