/*

RSA is a widely used public-key cryptosystem that allows two parties (such as people or computers) to exchange
secret messages without revealing information to anyone else listening on the conversation.
Many websites use RSA when visited over a secure https connection.
In RSA, each party has two different keys: a public key that is published and a private key that is kept secret.
To encrypt a message intended for a specific recipient, the sender will use the recipient’s public key to encrypt the message.
The recipient will use their private key to decrypt the message.

An RSA public key (n,e) consists of two numbers n and e.
The number n is a product of two distinct prime numbers, p and q.
In real applications, n would be hundreds of decimal digits long for security.

Let φ(n) be Euler’s totient function, which in this case is equal to (p−1)(q−1).
The private key consists of (n,d), where n is the same as in the public key and d is the solution to the congruence

de≡1modφ(n)

Formally, a congruence
a≡bmodc holds for three integers a, b, and c, if there exists an integer k such that a−b=kc.

The sender will encrypt a message M (which, for simplicity, is assumed to be an integer smaller than both p and q) by computing Memodn and sending it to the receiver.
The recipient will calculate (Me)d≡Med≡Mkφ(n)+1≡Mφ(n)kM≡Mmodn since by Euler’s theorem Mφ(n)≡1modn.
This will reconstruct the original message.
Without the private key, no practical way has been found for a potential attacker to recover M from the knowledge of Memodn and (n,e).

Your task is to crack RSA by finding the private key related to a specific public key.

Input

The first line of input has the number of test cases T, (1≤T≤50).
Each test case has one line that contains the two numbers n and e.
You may assume that n is the product of two primes p,q such that 2≤p,q<1000.
Also, e will be chosen so that d exists and is unique, and 1<d,e<φ(n).
Note that the product de may not fit into a 32-bit integer (e.g. Java’s int type).

Output

For each test case, output the single number d.

*/

fn main() {
    assert_eq!(crack(33, 3), 7);
    assert_eq!(crack(65, 11), 35);
}

fn crack(n: i128, e: i128) -> i128 {
    let (p, q) = factor(n);
    return recover(p, q, e);
}

fn factor(n: i128) -> (i128, i128) {
    let mut i = 2;
    while i <= n {
        if n%i == 0 {
            return (n/i, i);
        }
        i += 1;
    }
    return (-1, -1);
}

fn recover(p: i128, q: i128, e: i128) -> i128 {
    if p <= 0 || q <= 0 {
        return -1;
    }

    let mut i = 1;
    loop {
        let m = (p-1) * (q-1);
        let v = (e*i - 1) % m;
        if v == 0 {
            break;
        }
        i += 1;
    }
    return i;
}
