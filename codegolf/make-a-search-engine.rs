/*

You need to make a program, that when giving a list and a string, searches on the list for items that contains the string.

Examples:

Input: th [thing, awesome, potato, example]
Output: thing (Because it starts with "th")

Input: ing [thing, potato]
Output: thing (Because it ends with "ing")

Input: tat [thing, potato]
Output: potato (Because it contains "tat")

Input: tat [tato, potato]
Output: tato, potato (If there are 2 or more results matching, print all of them)
Remember, this is code golf, so the shortest code wins.

*/

fn main() {
    assert_eq!(search("th", vec!["thing", "awesome", "potato", "example"]), vec!["thing"]);
    assert_eq!(search("ing", vec!["thing", "potato"]), vec!["thing"]);
    assert_eq!(search("tat", vec!["thing", "potato"]), vec!["potato"]);
    assert_eq!(search("tat", vec!["tato", "potato"]), vec!["tato", "potato"]);
}

fn search(text: &str, list: Vec<&str>) -> Vec<String> {
    let mut result = vec![];
    for word in list {
        if word.contains(text) {
            result.push(word.to_string());
        }
    }
    result
}
