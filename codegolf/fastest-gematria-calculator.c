/*

Gematria is an ancient Jewish method to determine a numeric value of a letter sequence, using a fixed value for each letter. Gematria is originally applied to Hebrew letters, but for the context of this challenge, we'll use Latin script instead.
There are many ways to implement Gematria in Latin script, but let's define it as a close as it can be to the original standard encoding. The numbering goes as such:

A = 1, B = 2, C = 3, D = 4, E = 5, F = 6, G = 7, H = 8, I = 9, J = 10, K = 20, L = 30, M = 40, N = 50, O = 60, P = 70, Q = 80, R = 90, S = 100, T = 200, U = 300, V = 400, W = 500, X = 600, Y = 700, Z = 800.

Your job is to calculate the Gematria value for each character of a string, sum the result and print it or return it.

Rules

Lowercase and uppercase letters yield the same value. Anything else equals 0. You can assume the input encoding will always be ASCII.
You can input the file in whatever method you see fit, be it loading it from a file, piping it in the terminal or baking it into the source code.
You can use any method you see fit in order to make this go fast, except const evaluation of the input's value and baking that into the binary or a similar method. That would be way too easy. The calculation must happen locally on runtime.
And here's a naïve implementation in Rust to provide an example implementation:

#![feature(exclusive_range_pattern)]
fn char_to_number(mut letter: char) -> u32 {
    // map to lowercase as casing doesn't matter in Gematria
    letter = letter.to_ascii_lowercase();
    // get numerical value relative to 'a', mod 9 and plus 1 because a = 1, not 0.
    // overflow doesn't matter here because all valid ranges ahead have valid values
    let num_value = ((letter as u32).overflowing_sub('a' as u32).0) % 9 + 1;
    // map according to the Gematria skip rule
    match letter.to_ascii_lowercase() {
        'a'..'j' => num_value, // simply its value: 1, 2, 3...
        'j'..'s' => num_value * 10, // in jumps of 10: 10, 20, 30...
        's'..='z' => num_value * 100, // in jumps of 100: 100, 200, 300...
        _ => 0 // anything else has no value
    }
}

fn gematria(word: &str) -> u64 {
    word
        .chars()
        .map(char_to_number)
        .map(|it| it as u64) // convert to a bigger type before summing
        .sum()
}
In order to measure speed, each implementation will be fed the exact same file: a random 100MB text file from Github: https://github.com/awhipp/100mb-daily-random-text/releases/tag/v20221005

The speed of my implementation, measured with Measure-Command, completes in ~573ms and yields the number 9140634224. I compiled using -O 3 and baked the input text into the source code, and then ran the code on an Intel i5-10400 CPU.

*/

#include <assert.h>
#include <ctype.h>

typedef unsigned long long uvlong;

uvlong
gematria(const char *s)
{
	static const uvlong tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 200, 300, 400, 500, 600, 700, 800};
	uvlong r;
	int c;

	r = 0;
	while (*s) {
		c = tolower(*s++);
		if ('a' <= c && c <= 'z')
			r += tab[c - 'a'];
	}
	return r;
}

int
main(void)
{
	assert(gematria("S") == 100);
	assert(gematria("SZ") == 900);
	assert(gematria("JK") == 30);
	assert(gematria("XY") == 1300);
	assert(gematria("PQR") == 240);

	return 0;
}
