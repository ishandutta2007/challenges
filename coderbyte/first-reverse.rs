/*

Have the function FirstReverse(str) take the str parameter being passed and return the string in reversed order. For example: if the input string is "Hello World and Coders" then your program should return the string sredoC dna dlroW olleH.

*/

fn main() {
    let a = String::from("coderbyte");
    println!("{}", first_reverse(a));

    let b = String::from("I Love Code");
    println!("{}", first_reverse(b));

    let c = "Hello World and Coders";
    println!("{}", first_reverse(c.to_string()));
}

fn first_reverse(s: String) -> String {
    s.chars().rev().collect::<String>()
}

