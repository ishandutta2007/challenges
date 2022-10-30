/*

Write a function or program that takes string inputs, fully-spelled, English month names in title case: January, February, March, etc. (null/CR/LF terminated OK,
delimited with some non-alpha character if you so choose) and either compares two inputs, returning a Truthy value if the second input is greater (in month order) than the first.
Equal values result in a Falsey value or sorts an arbitrary sequence (list, delimited string, etc.) of them in chronological order
(The crux of the challenge is defining a method/expression that gives the correct lexicographical sort. Some languages might have a shorter answer with one or the other)
You cannot use any internal time parsing methods (e.g. strptime) to translate the month name into a number or a pre-canned mapping of month names. Use properties of the strings themselves, a parsimonious look-up table you define, or something clever.

Example

Functioning examples, though the first is prohibited by the rules...

import datetime
def is_later_month(a, b):
    '''
    Example of prohibited code because it relies on language
    features about how to parse month names
    '''
    return datetime.strptime(a, '%B') < datetime.strptime(b, '%B')
The below versions are OK though, because we code that info

months = {
    'January':  1, 'February':  2, 'March':      3,
    'April':    4, 'May':       5, 'June':       6,
    'July':     7, 'August':    8, 'September':  9,
    'October': 10, 'November': 11, 'December':  12,
}
def is_later_month(a, b):
    """
    Returns True/False when comparing two months.
    """
    return months[a] < months[b]
Or you could do a sorting function

months = {'as above...'}
def sort_months(l):
    """
    Sorts list and returns it. Different input and output than the above,
    but equally valid. Sorting versus comparing might be shorter in your
    favorite language.
    """
    return sorted(l, key=lambda x: months[x])

Example tests

assert is_later_month('January', 'February')
assert is_later_month('January', 'December')
assert is_later_month('November', 'December')
assert not is_later_month('July', 'July')
assert not is_later_month('October', 'September')

*/

package main

func main() {
	assert(monthcmp("January", "February") == -1)
	assert(monthcmp("January", "December") == -1)
	assert(monthcmp("November", "December") == -1)
	assert(monthcmp("July", "July") == 0)
	assert(monthcmp("October", "September") == 1)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func monthcmp(a, b string) int {
	m := map[string]int{
		"January": 1, "February": 2, "March": 3,
		"April": 4, "May": 5, "June": 6,
		"July": 7, "August": 8, "September": 9,
		"October": 10, "November": 11, "December": 12,
	}
	if m[a] < m[b] {
		return -1
	}
	if m[a] > m[b] {
		return 1
	}
	return 0
}
