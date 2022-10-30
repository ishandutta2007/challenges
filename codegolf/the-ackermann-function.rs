/*

The Ackermann function is notable for being the one of the simplest examples of a total, computable function that isn't primitive recursive.

We will use the definition of A(m,n)

taking in two nonnegative integers where

A(0, n) = n+1
A(m, 0) = A(m-1, n)
A(m, n) = A(m-1, A(m, n-1))

You may implement

    a named or anonymous function taking two integers as input, returning an integer, or
    a program taking two space- or newline-separated integers on STDIN, printing a result to STDOUT.

You may not use an Ackermann function or hyperexponentiation function from a library, if one exists, but you may use any other function from any other library. Regular exponentiation is allowed.

Your function must be able to find the value of A(m,n)
for m≤3 and n≤10

in less than a minute. It must at least theoretically terminate on any other inputs: given infinite stack space, a native Bigint type, and an arbitrarily long period of time, it would return the answer.
Edit: If your language has a default recursion depth that is too restrictive, you may reconfigure that at no character cost.

The submission with the shortest number of characters wins.

Here are some values, to check your answer:

*/

fn main() {
    table(3, 10);
}

fn table(m: u128, n: u128) {
    let pad = 6;
    print!("  m, n | ");
    for i in 0..n+1 {
        print!("{v:>w$} ", v=i, w=pad);
    }
    println!();
    for _ in 1..(pad as u128)*n*2 {
        print!("-");
    }
    println!();

    for i in 0..m+1 {
        print!("{v:w$} | ", v=i, w=pad);
        for j in 0..n+1 {
            print!("{v:>w$} ", v=ackermann(i, j), w=pad);
        }
        println!();
    }
}

fn ackermann(m: u128, n: u128) -> u128 {
    if m == 0 {
        return n+1;
    }
    if n == 0 {
        return ackermann(m-1, 1);
    }
    return ackermann(m-1, ackermann(m, n-1));
}
