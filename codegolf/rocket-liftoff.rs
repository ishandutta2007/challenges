/*

This code golf challenge is about making a rocket liftoff sequence.

Your output (STDOUT) should be equal to this:

Liftoff in T-10
Liftoff in T-9
Liftoff in T-8
Liftoff in T-7
Liftoff in T-6
Liftoff in T-5
Liftoff in T-4
Liftoff in T-3
Liftoff in T-2
Liftoff in T-1
LIFTOFF!

Rules:

    Your output must print to STDOUT.
    Your program must not raise any errors.
    This is code golf, shortest code in bytes wins.

*/

fn main() {
    liftoff(10);
}

fn liftoff(mut n: isize) {
    while n > 0 {
        println!("Liftoff in T-{}", n);
        n -= 1;
    }
    println!("LIFTOFF!");
}
