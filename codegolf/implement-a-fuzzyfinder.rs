/*

Inspired by this link I found on Reddit.

A FuzzyFinder is a feature of many text editors. As you start to type a file path S, the FuzzyFinder kicks in and shows you all files in the current directory containing the string you entered, sorted by the position of S in the file.

Your task is to implement a fuzzy finder. It should be program or function that takes (via stdin, function argument, or command line) a string S and a list of strings L, formatted however you wish, and returns or prints the result of running the fuzzy finder.
The search should be case-sensitive. Results where S is in the same position in multiple strings may be sorted however you wish.

Example:

Input: mig, [imig, mig, migd, do, Mig]
Output:
    [mig, migd, imig]
OR
    [migd, mig, imig]
This is code golf, so the shortest solution wins.

*/

fn main() {
    println!("{:?}", fuzzies("mig", vec!["imig", "mig", "migd", "do", "Mig"]));
}

fn fuzzies(s: &str, a: Vec<&str>) -> Vec<String> {
    let mut r = vec![];
    for t in a {
        if t.find(s) != None {
            r.push(t.to_owned());
        }
    }
    r.sort();

    r
}
