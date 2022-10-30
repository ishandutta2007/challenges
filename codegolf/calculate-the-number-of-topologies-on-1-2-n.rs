/*

Task
Write a function/program which takes n as a parameter/input and prints/returns the number of topologies (which is demonstrated below) on the set {1,2,...,n}.

Definition of Topology
Let X be any finite set, and assume that T, which is subset of the power set of X (i.e. a set containing subsets of X), satisfy these conditions:

X and the empty set are in T.

If two set U and V are in T, then the union of those two sets are in T.

If two set U and V are in T, then the intersection of those two sets are in T.

...then T is called the topology on X.

Specifications
Your program is either:

a function which takes n as a parameter
or a program which inputs n
and prints or returns the number of (distinct) topologies on the set {1,2,...,n}.

n is any non-negative integer which is less than 11 (of course there's no problem if your program handles n bigger than 11), and the output is a positive integer.

Your program should not use any kinds of library functions or native functions which calculates the number of topology directly.

Example input (value of n) : 7

Example output/return : 9535241

You may check your return value at here or here.

Of course, shortest code wins.

The winner is decided, however, I may change the winner if shorter code appears..

*/

fn main() {
    let tab: Vec<u128> = vec![1, 1, 4, 29, 355, 6942, 209527, 9535241];

    for (i, v) in tab.iter().enumerate() {
        assert_eq!(topologies(i as u128), *v);
        println!("{} {}", i, v);
    }
}

/*

https://oeis.org/A000798

@user76284

Expanded version:

def f(n):
    count = 0
    for x in range(2**2**n): # for every set x of subsets of [n] = {1,...,n}
        try:
            assert x & 1 # {} is in x
            assert (x >> 2 ** n - 1) & 1 # [n] is in x
            for i in range(2**n): # for every subset i of [n]...
                if x >> i & 1: # ...in x
                    for j in range(2**n): # for every subset j of [n]...
                        if x >> j & 1: # ...in x
                            assert (x >> (i | j)) & 1 # their union is in x
                            assert (x >> (i & j)) & 1 # their intersection is in x
            count += 1
        except AssertionError:
            pass
    return count
For example, suppose n = 3. The possible subsets of [n] are

0b000
0b001
0b010
0b011
0b100
0b101
0b110
0b111
where the ith bit indicates whether i is in the subset. To encode sets of subsets, we notice that each of these subsets either belongs or does not belong to the set in question. Thus, for example,

x = 0b10100001
0b000 # 1
0b001 # 0
0b010 # 1
0b011 # 0
0b100 # 0
0b101 # 0
0b110 # 0
0b111 # 1
indicates that x contains {}, {2}, and {1,2,3}.

*/

fn topologies(n: u128) -> u128 {
    let mut c = 0;

    let s = 1u128 << n;
    let t = 1u128 << s;
    'outer: for x in 0..t {
        if (x & 1) == 0 {
            continue;
        }

        if ((x >> (s - 1)) & 1) == 0 {
            continue;
        }

        for i in 0..s {
            if ((x >> i) & 1) == 0 {
                continue;
            }

            for j in 0..s {
                if ((x >> j) & 1) == 0 {
                    continue;
                }

                if ((x >> (i | j)) & 1) == 0 {
                    continue 'outer;
                }

                if ((x >> (i & j)) & 1) == 0 {
                    continue 'outer;
                }
            }
        }

        c += 1;
    }

    c
}
