/*

GF(9) or GF(3^2) is the smallest finite field whose order isn't a prime or a power of two. Finite fields of prime order aren't particurlarly interesting and there are already challenges for GF(2^8) (link) and GF(2^64) (link).

Challenge
First define nine elements of the field. These must be distinct integers from 0 to 255, or the one-byte characters their code points represent. State in your answer which representation you choose.

Then implement two binary operations, addition and multiplication, satisfying the field axioms:

Both operations must be commutative and associative.
Addition has the identity element 0 and an additive inverse for each element.
Multiplication has the identity element 1 and a multiplicative inverse for each element except 0.
Multiplication distributes over addition: a⋅(b+c)=(a⋅b)+(a⋅c)
Addition and multiplication can be implemented as functions or programs taking two field elements and producing one field element.

Since the field is really small, you can test the axioms exhaustively to check your implementation or verify the addition and multiplication tables.

Mathematical construction

Elements of GF(32) can be interpreted as polynomials of the form P(x)=ax+b over GF(3). (Addition and multiplication in GF(3)={0,1,2} are the standard integer operations modulo 3.)

Then addition in GF(32) is simply the addition of two polynomials. Multiplication is defined by the product of two polynomials, reduced modulo a polynomial of degree 2 which is irreducible over GF(3).

Example

Mapping polynomials to integers with n=3a+b and using the irreducible polynomial x2+1 yields the following addition and multiplication tables. Note that there are other possible isomorphisms of these tables.

+   0 1 2 3 4 5 6 7 8   *   0 1 2 3 4 5 6 7 8
   ------------------      ------------------
0 | 0 1 2 3 4 5 6 7 8   0 | 0 0 0 0 0 0 0 0 0
1 | 1 2 0 4 5 3 7 8 6   1 | 0 1 2 3 4 5 6 7 8
2 | 2 0 1 5 3 4 8 6 7   2 | 0 2 1 6 8 7 3 5 4
3 | 3 4 5 6 7 8 0 1 2   3 | 0 3 6 2 5 8 1 4 7
4 | 4 5 3 7 8 6 1 2 0   4 | 0 4 8 5 6 1 7 2 3
5 | 5 3 4 8 6 7 2 0 1   5 | 0 5 7 8 1 3 4 6 2
6 | 6 7 8 0 1 2 3 4 5   6 | 0 6 3 1 7 4 2 8 5
7 | 7 8 6 1 2 0 4 5 3   7 | 0 7 5 4 2 6 8 3 1
8 | 8 6 7 2 0 1 5 3 4   8 | 0 8 4 7 3 2 5 1 6
Test of distributivity using the tables above:

5⋅(2+7)=5⋅6=4
(5⋅2)+(5⋅7)=7+6=4

Note that simply using addition and multiplication modulo 9 won't work.

Scoring

This is code golf. Your score is the sum of bytes of the functions (or programs) for addition and multiplication. Lowest number of bytes wins.

*/

fn main() {
    verify();
}

fn verify() {
    commutative();
    associative();
    identity();
    distributive();
}

fn commutative() {
    for a in 0..9 {
        for b in 0..9 {
            assert_eq!(add(a, b), add(b, a));
            assert_eq!(mul(a, b), mul(b, a));
        }
    }
}

fn associative() {
    for a in 0..9 {
        for b in 0..9 {
            for c in 0..9 {
                assert_eq!(add(add(a, b), c), add(a, add(b, c)));
                assert_eq!(mul(mul(a, b), c), mul(a, mul(b, c)));
            }
        }
    }
}

fn identity() {
    for a in 0..9 {
        assert_eq!(add(a, 0), a);
        assert_eq!(mul(a, 1), a);

        assert_eq!(add(a, neg(a)), 0);
        if a != 0 {
            assert_eq!(mul(a, inv(a)), 1);
        }
    }
}

fn distributive() {
    for a in 0..9 {
        for b in 0..9 {
            for c in 0..9 {
                assert_eq!(mul(a, add(b, c)), add(mul(a, b), mul(a, c)));
            }
        }
    }
}

fn add(a: usize, b: usize) -> usize {
    let tab = vec![
        [0, 1, 2, 3, 4, 5, 6, 7, 8],
        [1, 2, 0, 4, 5, 3, 7, 8, 6],
        [2, 0, 1, 5, 3, 4, 8, 6, 7],
        [3, 4, 5, 6, 7, 8, 0, 1, 2],
        [4, 5, 3, 7, 8, 6, 1, 2, 0],
        [5, 3, 4, 8, 6, 7, 2, 0, 1],
        [6, 7, 8, 0, 1, 2, 3, 4, 5],
        [7, 8, 6, 1, 2, 0, 4, 5, 3],
        [8, 6, 7, 2, 0, 1, 5, 3, 4],
    ];

    tab[a][b]
}

fn mul(a: usize, b: usize) -> usize {
    let tab = vec![
        [0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 1, 2, 3, 4, 5, 6, 7, 8],
        [0, 2, 1, 6, 8, 7, 3, 5, 4],
        [0, 3, 6, 2, 5, 8, 1, 4, 7],
        [0, 4, 8, 5, 6, 1, 7, 2, 3],
        [0, 5, 7, 8, 1, 3, 4, 6, 2],
        [0, 6, 3, 1, 7, 4, 2, 8, 5],
        [0, 7, 5, 4, 2, 6, 8, 3, 1],
        [0, 8, 4, 7, 3, 2, 5, 1, 6],
    ];

    tab[a][b]
}

fn neg(a: usize) -> usize {
    for b in 0..9 {
        if add(a, b) == 0 {
            return b;
        }
    }

    0
}

fn inv(a: usize) -> usize {
    for b in 0..9 {
        if mul(a, b) == 1 {
            return b;
        }
    }

    0
}
