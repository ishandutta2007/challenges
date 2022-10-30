/*

Using markdown, it's possible to format links such as https://edabit.com/challenges, into something tidier like this. Notice how the text "Go to the challenges!" appears when hovering over the link.

This was achieved by using this code:

[this](https://edabit.com/challenges "Go to the challenges!")
Given the url, the new name and optionally the hover_text, return the tidied up hyperlink as a string.

Examples
tidy_link("https://edabit.com/challenges", "this", "Go to the challenges!") ➞ "[this](https://edabit.com/challenges "Go to the challenges!")"

tidy_link("https://www.google.com", "Google", "Google Search") ➞ "[Google](https://www.google.com "Google Search")"

tidy_link("https://www.youtube.com/watch?v=dQw4w9WgXcQ", "Click Me!") ➞ "[Click Me!](https://www.youtube.com/watch?v=dQw4w9WgXcQ)"

Notes
Supply double quotes for the hover text.
Keep in mind that some tests will not include an argument for hover_text.

*/

package main

import "fmt"

func main() {
	assert(tidy(`https://edabit.com/challenges`, `Challenges`, `Go to the challenges!`) == `[Challenges](https://edabit.com/challenges "Go to the challenges!")`)
	assert(tidy(`https://www.google.com`, `Google`, `Google Search`) == `[Google](https://www.google.com "Google Search")`)
	assert(tidy(`https://www.youtube.com/watch?v=dQw4w9WgXcQ`, `Click Me!`, ``) == `[Click Me!](https://www.youtube.com/watch?v=dQw4w9WgXcQ)`)
	assert(tidy(`https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet`, `Markdown Cheatsheet`, ``) == `[Markdown Cheatsheet](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet)`)
	assert(tidy(`https://www.python.org/`, `Python`, `Visit the Python Website!`) == `[Python](https://www.python.org/ "Visit the Python Website!")`)
	assert(tidy(`https://www.youtube.com/watch?v=O2yPnnDfqpw`, `i just did a bad thing`, ``) == `[i just did a bad thing](https://www.youtube.com/watch?v=O2yPnnDfqpw)`)
	assert(tidy(`https://www.reddit.com/`, `Reddit`, `the front page of reddit`) == `[Reddit](https://www.reddit.com/ "the front page of reddit")`)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func tidy(url, name, hover string) string {
	text := url
	if hover != "" {
		text += fmt.Sprintf(" \"%v\"", hover)
	}
	return fmt.Sprintf("[%v](%v)", name, text)
}
