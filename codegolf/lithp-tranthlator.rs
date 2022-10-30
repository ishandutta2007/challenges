/*

My friend made a lisp translator the other day, that is to say it took a string and converted s=>th and S=>Th. It was quite long and I thought that it could be golfed.

So the task is to make a program/function that takes an input string, translates it in to lisp and outputs the string

Test case

Sam and Sally like Sheep        Tham and Thally like Thheep
Sally likes sausages            Thally liketh thauthageth
Sally sells seashells           Thally thellth theathhellth
Note that it doesn't matter that h gets repeated all the time

This is code golf so shortest answer wins

*/

fn main() {
    assert_eq!(lithp("Sam and Sally like Sheep"), "Tham and Thally like Thheep");
    assert_eq!(lithp("Sally likes sausages"), "Thally liketh thauthageth");
    assert_eq!(lithp("Sally sells seashells"), "Thally thellth theathhellth");
}

fn lithp(s: &str) -> String {
    let mut r = str::replace(&s, "s", "th");
    r = str::replace(&r, "S", "Th");
    r
}
