/*

You have an object with years 2015-2020 as keys and some albums released for each year as key values. Write a function that takes an album and returns the year in which it was released.

Examples

releaseYear("Ode to Joy") ➞ 2019

releaseYear("Honeymoon") ➞ 2015

releaseYear("Fake_album") ➞ "Unknown"

Note

    Albums object is made for you.
    If the album isn't in the object, return the string "Unknown".

*/

package main

func main() {
	assert(release("Ode to Joy") == 2019)
	assert(release("Honeymoon") == 2015)
	assert(release("Fake_album") == "Unknown")
	assert(release("Rebel Heart") == 2015)
	assert(release("Someone Out There") == 2018)
	assert(release("Where Wildness Grows") == "Unknown")
	assert(release("thank u next") == 2019)
	assert(release("2017") == "Unknown")
	assert(release("Flower Boy") == 2017)
	assert(release("Kamikaze") == 2018)
	assert(release("folklore") == 2020)
	assert(release("Opal") == "Unknown")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func release(s string) interface{} {
	m := map[string]int{
		"Honeymoon":         2015,
		"Ode to Joy":        2019,
		"Rebel Heart":       2015,
		"Someone Out There": 2018,
		"thank u next":      2019,
		"Flower Boy":        2017,
		"Kamikaze":          2018,
		"folklore":          2020,
	}
	if y, f := m[s]; f {
		return y
	}
	return "Unknown"
}
