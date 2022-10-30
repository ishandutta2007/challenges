/*

On a standard 88 key piano, each key has a scientific name.

The first three keys are A0, B♭0, and B0. The keys then proceed through C1, D♭1, D1, E♭1, E1, F1, G♭1, G1, A♭1, A1, B♭1, B1, and start over again at C2. This continues up through B7, and the final key is C8.

Any flat can instead be written as a sharp of the preceding note, e.g. D♭4 can also be written C♯4. If necessary, you can write "D♭4" as "Db4".

Your program should build an ordered sequence (array, list, vector, etc.) containing the key names (as strings, symbols, or some similar data structure) in order.

Program length should be measured in characters, to avoid penalizing people who properly generate ♯ or ♭ rather than # or b. However, Unicode recoding is forbidden.

*/

package main

import "reflect"

func main() {
	notes := []string{
		"A0", "Bb0", "B0", "C1", "Db1", "D1", "Eb1", "E1", "F1", "Gb1", "G1", "Ab1",
		"A1", "Bb1", "B1", "C2", "Db2", "D2", "Eb2", "E2", "F2", "Gb2", "G2", "Ab2",
		"A2", "Bb2", "B2", "C3", "Db3", "D3", "Eb3", "E3", "F3", "Gb3", "G3", "Ab3",
		"A3", "Bb3", "B3", "C4", "Db4", "D4", "Eb4", "E4", "F4", "Gb4", "G4", "Ab4",
		"A4", "Bb4", "B4", "C5", "Db5", "D5", "Eb5", "E5", "F5", "Gb5", "G5", "Ab5",
		"A5", "Bb5", "B5", "C6", "Db6", "D6", "Eb6", "E6", "F6", "Gb6", "G6", "Ab6",
		"A6", "Bb6", "B6", "C7", "Db7", "D7", "Eb7", "E7", "F7", "Gb7", "G7", "Ab7",
		"A7", "Bb7", "B7", "C8",
	}

	assert(reflect.DeepEqual(gen(), notes))
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func gen() []string {
	n1 := []string{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}
	n2 := []string{"C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B"}

	var r []string
	for _, y := range n1 {
		for _, x := range n2 {
			r = append(r, x+y)
		}
	}
	return r[9:97]
}
