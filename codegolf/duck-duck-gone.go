/*

Here is the (quite scary) Five little ducks song(it is not long):

Five little ducks went out one day,
over the hills and up away.
Mother Duck said, "Quack Quack Quack Quack",
but only four little ducks came back.

Four little ducks went out one day,
over the hills and up away.
Mother Duck said, "Quack Quack Quack Quack",
but only three little ducks came back.

Three little ducks went out one day,
over the hills and up away.
Mother Duck said, "Quack Quack Quack Quack",
but only two little ducks came back.

Two little ducks went out one day,
over the hills and up away.
Mother Duck said, "Quack Quack Quack Quack",
but only one little duck came back.

One little duck went out one day,
over the hills and up away.
Mother Duck said, "Quack Quack Quack Quack",
but none of the little ducks came back.

Mother duck herself went out one day,
over the hills and up away.
Mother Duck said, "Quack Quack Quack Quack",
and all of the little ducks came back.

Your task is not to output this song. You should take a verse and output the next verse, cyclically (the next verse of the last verse is the first verse).
Rules

    No standard loopholes, please.
    Input/output will be taken via our standard input/output methods.
    The exact verse must be outputted, and there should be no differences when compared to the song lyrics. The input will not be different when it is compared to the song lyrics too.

Examples

Mother duck herself went out one day,
over the hills and up away.
Mother Duck said, "Quack Quack Quack Quack",
and all of the little ducks came back.

Expected:

Five little ducks went out one day,
over the hills and up away.
Mother Duck said, "Quack Quack Quack Quack",
but only four little ducks came back.

Three little ducks went out one day,
over the hills and up away.
Mother Duck said, "Quack Quack Quack Quack",
but only two little ducks came back.

Expected:

Two little ducks went out one day,
over the hills and up away.
Mother Duck said, "Quack Quack Quack Quack",
but only one little duck came back.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	fmt.Println(verse(`Mother duck herself went out one day,
over the hills and up away.
Mother Duck said, "Quack Quack Quack Quack",
and all of the little ducks came back.`))

	fmt.Println(verse(`Three little ducks went out one day,
over the hills and up away.
Mother Duck said, "Quack Quack Quack Quack",
but only two little ducks came back.`))
}

func verse(s string) string {
	t := strings.Split(poem, "\n\n")
	for i := range t {
		if s == t[i] {
			return t[(i+1)%len(t)]
		}
	}
	return ""
}

const poem = `Five little ducks went out one day,
over the hills and up away.
Mother Duck said, "Quack Quack Quack Quack",
but only four little ducks came back.

Four little ducks went out one day,
over the hills and up away.
Mother Duck said, "Quack Quack Quack Quack",
but only three little ducks came back.

Three little ducks went out one day,
over the hills and up away.
Mother Duck said, "Quack Quack Quack Quack",
but only two little ducks came back.

Two little ducks went out one day,
over the hills and up away.
Mother Duck said, "Quack Quack Quack Quack",
but only one little duck came back.

One little duck went out one day,
over the hills and up away.
Mother Duck said, "Quack Quack Quack Quack",
but none of the little ducks came back.

Mother duck herself went out one day,
over the hills and up away.
Mother Duck said, "Quack Quack Quack Quack",
and all of the little ducks came back.`
