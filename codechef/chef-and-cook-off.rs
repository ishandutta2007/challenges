/*

Chef has obtained the results of a past Cook-Off. He wants to estimate the skill level of each contestant. The contestants can be classified with high probability (w.h.p.) based on the number of solved problems:

    A contestant that solved exactly 0 problems is a beginner.
    A contestant that solved exactly 1 problem is a junior developer.
    A contestant that solved exactly 2 problems is a middle developer.
    A contestant that solved exactly 3 problems is a senior developer.
    A contestant that solved exactly 4 problems is a hacker.
    A contestant that solved all five problems is Jeff Dean.

Please help Chef to identify the programming level of each participant.

*/

fn main() {
    let a = [0, 0, 0, 0, 0];
    println!("{}", level(&a));

    let a = [0, 1, 0, 1, 0];
    println!("{}", level(&a));

    let a = [0, 0, 1, 0, 0];
    println!("{}", level(&a));

    let a = [1, 1, 1, 1, 1];
    println!("{}", level(&a));

    let a = [0, 1, 1, 1, 0];
    println!("{}", level(&a));

    let a = [0, 1, 1, 1, 1];
    println!("{}", level(&a));

    let a = [1, 1, 1, 1, 0];
    println!("{}", level(&a));
}

fn level(a: &[isize]) -> &str {
    let l = a.iter().filter(|&n| *n == 1).count();
    match l {
        0 => "Beginner",
        1 => "Junior Developer",
        2 => "Middle Developer",
        3 => "Senior Developer",
        4 => "Hacker",
        _ => "Jeff Dean",
    }
}
