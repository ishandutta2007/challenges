/*

Chef is preparing a sweet dish called Halva. He has already added all the necessary ingredients except milk and sugar.
He just added one of the remaining ingredients and someone started ringing the bell.
He wants to check who is ringing the bell, so he tells you the ingredient he just added and asks you to add the last one. What will be the ingredient you need to add?

Note: If you are using Python then please use input().strip() instead of input().

Input:

First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line containing a single string S denoting the last ingredient added by Chef.

Output:

For each testcase, output a single string (in lower case alphabets) naming the ingredient that you need to add to Halva, on a separate line.

Constraints
1≤T≤100
S=milk or S=sugar

*/

fn main() {
    assert_eq!(ingredient("sugar"), "milk");
    assert_eq!(ingredient("milk"), "sugar");
}

fn ingredient(s: &str) -> &'static str {
    match s {
        "sugar" => "milk",
        "milk" => "sugar",
        _ => "",
    }
}
