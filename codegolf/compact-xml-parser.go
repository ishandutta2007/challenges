/*

Goal:

The goal of this challenge is to take a simple 6 row by 6 column XML file (without the standard XML header) and parse it out so that the program can return the value of a cell given it's coordinates.

The entry with the shortest overall length by language and overall will be declared the winner.

Additional information:

The XML syntax will always be an HTML table with each inner level being indented by four single spaces. You may assume that every file put into the program will be exactly like the one given below.

If your program uses imports you do not need to include them in the golfed version of your code but you must submit a copy of the program in the explanation that shows all imports used. This explanation will not effect your entries byte count.

Rules:

The XML file cannot be hardcoded
XML libraries/functions cannot be used
Extra Credit:

Can pretty print the table if given the --all flag (20 bytes off of total)
Can print all entries of a column given the column number in --col=number (20 bytes off of total)
Can print all entries of a row given the row number in --row=number (20 bytes off of total)
Can parse any size file as long as #rows = #columns (40 bytes off of total)
XML File:

<table>
    <tr>
        <th>Foo</th>
        <th>Bar</th>
        <th>Baz</th>
        <th>Cat</th>
        <th>Dog</th>
        <th>Grinch</th>
    </tr>
    <tr>
        <th>Something</th>
        <th>Something</th>
        <th>Darkside</th>
        <th>Star</th>
        <th>Wars</th>
        <th>Chicken</th>
    </tr>
    <tr>
        <th>Star</th>
        <th>Trek</th>
        <th>Xbox</th>
        <th>Words</th>
        <th>Too</th>
        <th>Many</th>
    </tr>
    <tr>
        <th>Columns</th>
        <th>Not</th>
        <th>Enough</th>
        <th>Words</th>
        <th>To</th>
        <th>Fill</th>
    </tr>
    <tr>
        <th>Them</th>
        <th>So</th>
        <th>I</th>
        <th>Will</th>
        <th>Do</th>
        <th>My</th>
    </tr>
    <tr>
        <th>Best</th>
        <th>To</th>
        <th>Fill</th>
        <th>Them</th>
        <th>All</th>
        <th>Up</th>
    </tr>
</table>

*/

package main

import (
	"encoding/xml"
	"flag"
	"fmt"
	"log"
	"os"
)

var (
	all = flag.Bool("all", true, "dump table")
	row = flag.Int("row", 0, "dump row")
	col = flag.Int("col", 0, "dump col")
)

func main() {
	log.SetFlags(0)
	log.SetPrefix("compact-xml-parser: ")

	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 1 {
		usage()
	}

	values, rows, cols, err := parse(flag.Arg(0))
	check(err)

	switch {
	case 1 <= *row && *row <= rows:
		for _, value := range values[*row-1] {
			fmt.Printf("%-16s", value)
		}
		fmt.Println()

	case 1 <= *col && *col <= cols:
		for i := range values {
			fmt.Printf("%-16s\n", values[i][*col-1])
		}

	case *all:
		for i := range values {
			for j := range values[i] {
				fmt.Printf("%-16s", values[i][j])
			}
			fmt.Println()
		}
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] file")
	flag.PrintDefaults()
	os.Exit(2)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func parse(name string) (values [][]string, rows, cols int, err error) {
	data, err := os.ReadFile(name)
	if err != nil {
		return
	}

	var table struct {
		Tr []struct {
			Th []string `xml:"th"`
		} `xml:"tr"`
	}
	err = xml.Unmarshal(data, &table)
	if err != nil {
		return
	}

	for _, tr := range table.Tr {
		var value []string
		for _, th := range tr.Th {
			value = append(value, th)
		}
		values = append(values, value)
	}

	rows = len(values)
	if rows == 0 {
		err = fmt.Errorf("table has no rows")
		return
	}

	cols = len(values[0])
	if cols == 0 {
		err = fmt.Errorf("table has no columns")
		return
	}

	for i := range values {
		if len(values[i]) != cols {
			err = fmt.Errorf("table has mismatched number of columns")
			return
		}
	}

	return
}
