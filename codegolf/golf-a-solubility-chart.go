/*

Given the name of a cation and anion, output "S" (soluble) or "I" (insoluble).
The table we will be using is from wikipedia: https://en.wikipedia.org/wiki/Solubility_chart.
It is copied at the end of the question for future reference.

Input: The cation, followed by the anion, separated by a space. The cation will be one of the following:

Lithium Sodium Potassium Ammonium Beryllium Magnesium Calcium
Strontium Barium Zinc Iron(II) Copper(II) Aluminium Iron(III) Lead(II) Silver
and the anion will be one of the following:

Fluoride Chloride Bromide Iodide Carbonate Chlorate Hydroxide Cyanide Cyanate
Thiocyanate Nitrate Oxide Phosphate Sulfate Dichromate
Each will have its first letter capitalized.

Example Input: Sodium Chloride

Output:
A truthy value, or S, if it is soluble, falsey or I otherwise.
If the wikipedia page lists anything else (e.g. slightly soluble, or reacts with water) or if the input is not in the form "cation anion,"
your program may do anything (undefined behavior), so it may output 'S', 'I', or anything else.

Table:

?,S,S,S,?,S,S,S,?,S,S,?,I,S,S
S,S,S,S,S,S,S,S,S,S,S,?,S,S,S
S,S,S,S,S,S,S,S,S,S,S,?,S,S,S
S,S,S,S,S,S,S,S,?,S,S,?,S,S,S
S,S,S,?,?,?,?,?,?,?,S,?,?,S,?
?,S,S,S,I,S,I,?,?,?,S,I,I,S,I
I,S,S,S,I,S,?,S,?,?,S,?,I,?,I
?,S,S,S,I,S,S,?,?,?,S,?,?,I,?
?,S,S,S,I,S,S,S,?,?,S,?,?,I,?
?,S,S,S,I,S,I,I,?,?,S,I,I,S,I
S,S,S,S,I,S,I,?,?,?,S,I,I,S,I
?,S,S,?,I,S,I,?,?,I,S,I,I,S,I
S,S,S,?,?,S,I,?,?,?,S,I,I,S,I
?,S,S,?,?,S,I,?,?,?,S,I,I,?,I
?,?,?,I,I,S,I,?,?,?,S,I,I,I,?
S,I,I,I,I,S,?,I,I,?,S,?,I,?,I

The rows are cations in the order listed above and the columns are anions.
For example, since Magnesium Iodide is soluble, and Magnesium was the 6th cation and Iodide was the 4th anion, the 6th row and 4th column has the character 'S'.
The ? indicates undefined behavior.

*/

package main

func main() {
	assert(solubility("Magnesium", "Iodide") == 'S')
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func solubility(cation, anion string) rune {
	cations := []string{
		"Lithium", "Sodium", "Potassium", "Ammonium", "Beryllium", "Magnesium", "Calcium",
		"Strontium", "Barium", "Zinc", "Iron(II)", "Copper(II)", "Aluminium", "Iron(III)", "Lead(II)", "Silver",
	}

	anions := []string{
		"Fluoride", "Chloride", "Bromide", "Iodide", "Carbonate", "Chlorate", "Hydroxide", "Cyanide", "Cyanate",
		"Thiocyanate", "Nitrate", "Oxide", "Phosphate", "Sulfate", "Dichromate",
	}

	mixings := [][]rune{
		{'?', 'S', 'S', 'S', '?', 'S', 'S', 'S', '?', 'S', 'S', '?', 'I', 'S', 'S'},
		{'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', '?', 'S', 'S', 'S'},
		{'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', '?', 'S', 'S', 'S'},
		{'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', '?', 'S', 'S', '?', 'S', 'S', 'S'},
		{'S', 'S', 'S', '?', '?', '?', '?', '?', '?', '?', 'S', '?', '?', 'S', '?'},
		{'?', 'S', 'S', 'S', 'I', 'S', 'I', '?', '?', '?', 'S', 'I', 'I', 'S', 'I'},
		{'I', 'S', 'S', 'S', 'I', 'S', '?', 'S', '?', '?', 'S', '?', 'I', '?', 'I'},
		{'?', 'S', 'S', 'S', 'I', 'S', 'S', '?', '?', '?', 'S', '?', '?', 'I', '?'},
		{'?', 'S', 'S', 'S', 'I', 'S', 'S', 'S', '?', '?', 'S', '?', '?', 'I', '?'},
		{'?', 'S', 'S', 'S', 'I', 'S', 'I', 'I', '?', '?', 'S', 'I', 'I', 'S', 'I'},
		{'S', 'S', 'S', 'S', 'I', 'S', 'I', '?', '?', '?', 'S', 'I', 'I', 'S', 'I'},
		{'?', 'S', 'S', '?', 'I', 'S', 'I', '?', '?', 'I', 'S', 'I', 'I', 'S', 'I'},
		{'S', 'S', 'S', '?', '?', 'S', 'I', '?', '?', '?', 'S', 'I', 'I', 'S', 'I'},
		{'?', 'S', 'S', '?', '?', 'S', 'I', '?', '?', '?', 'S', 'I', 'I', '?', 'I'},
		{'?', '?', '?', 'I', 'I', 'S', 'I', '?', '?', '?', 'S', 'I', 'I', 'I', '?'},
		{'S', 'I', 'I', 'I', 'I', 'S', '?', 'I', 'I', '?', 'S', '?', 'I', '?', 'I'},
	}

	i := index(cation, cations)
	j := index(anion, anions)
	if i < 0 || j < 0 || i >= len(mixings) || j >= len(mixings[i]) {
		return '?'
	}
	return mixings[i][j]
}

func index(str string, tab []string) int {
	for i := range tab {
		if str == tab[i] {
			return i
		}
	}
	return -1
}
