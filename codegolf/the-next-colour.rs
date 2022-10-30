/*

Challenge
Consider the rainbow as seven colours, represented by strings as Red Orange Yellow Green Blue Indigo Violet.
Your task is to create a program that receives one of these colours as input and outputs next in order rainbow colour. This includes overlapping Violet -> Red

Input
A string containing one of rainbow colours.

Output
The next in order colour of the rainbow.

Rules
Colour names are case sensitive. They must match the case included in this post.
The input will always be valid. Any behavior is allowed for invalid input.
This is code golf, so the shortest amount of bytes wins!
Example Input and Output
Input -> Output
Red -> Orange
Orange -> Yellow
Yellow -> Green
Green -> Blue
Blue -> Indigo
Indigo -> Violet
Violet -> Red

*/

fn main() {
    assert_eq!(next("Red"), "Orange");
    assert_eq!(next("Orange"), "Yellow");
    assert_eq!(next("Yellow"), "Green");
    assert_eq!(next("Green"), "Blue");
    assert_eq!(next("Blue"), "Indigo");
    assert_eq!(next("Indigo"), "Violet");
    assert_eq!(next("Violet"), "Red");
}

fn next(name: &str) -> &str {
    let colors = vec![
        "Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet",
    ];

    let location = colors.iter().position(|&value| value == name);
    match location {
        Some(index) => colors[(index + 1) % colors.len()],
        None => "Unknown",
    }
}
