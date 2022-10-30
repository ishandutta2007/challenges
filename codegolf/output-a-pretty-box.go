/*

Your challenge is to exactly output the following box:

..................................................
..................................................
..                                              ..
..                                              ..
..  ++++++++++++++++++++++++++++++++++++++++++  ..
..  ++++++++++++++++++++++++++++++++++++++++++  ..
..  ++                                      ++  ..
..  ++                                      ++  ..
..  ++  ..................................  ++  ..
..  ++  ..................................  ++  ..
..  ++  ..                              ..  ++  ..
..  ++  ..                              ..  ++  ..
..  ++  ..  ++++++++++++++++++++++++++  ..  ++  ..
..  ++  ..  ++++++++++++++++++++++++++  ..  ++  ..
..  ++  ..  ++                      ++  ..  ++  ..
..  ++  ..  ++                      ++  ..  ++  ..
..  ++  ..  ++  ..................  ++  ..  ++  ..
..  ++  ..  ++  ..................  ++  ..  ++  ..
..  ++  ..  ++  ..              ..  ++  ..  ++  ..
..  ++  ..  ++  ..              ..  ++  ..  ++  ..
..  ++  ..  ++  ..  ++++++++++  ..  ++  ..  ++  ..
..  ++  ..  ++  ..  ++++++++++  ..  ++  ..  ++  ..
..  ++  ..  ++  ..  ++      ++  ..  ++  ..  ++  ..
..  ++  ..  ++  ..  ++      ++  ..  ++  ..  ++  ..
..  ++  ..  ++  ..  ++  ..  ++  ..  ++  ..  ++  ..
..  ++  ..  ++  ..  ++  ..  ++  ..  ++  ..  ++  ..
..  ++  ..  ++  ..  ++      ++  ..  ++  ..  ++  ..
..  ++  ..  ++  ..  ++      ++  ..  ++  ..  ++  ..
..  ++  ..  ++  ..  ++++++++++  ..  ++  ..  ++  ..
..  ++  ..  ++  ..  ++++++++++  ..  ++  ..  ++  ..
..  ++  ..  ++  ..              ..  ++  ..  ++  ..
..  ++  ..  ++  ..              ..  ++  ..  ++  ..
..  ++  ..  ++  ..................  ++  ..  ++  ..
..  ++  ..  ++  ..................  ++  ..  ++  ..
..  ++  ..  ++                      ++  ..  ++  ..
..  ++  ..  ++                      ++  ..  ++  ..
..  ++  ..  ++++++++++++++++++++++++++  ..  ++  ..
..  ++  ..  ++++++++++++++++++++++++++  ..  ++  ..
..  ++  ..                              ..  ++  ..
..  ++  ..                              ..  ++  ..
..  ++  ..................................  ++  ..
..  ++  ..................................  ++  ..
..  ++                                      ++  ..
..  ++                                      ++  ..
..  ++++++++++++++++++++++++++++++++++++++++++  ..
..  ++++++++++++++++++++++++++++++++++++++++++  ..
..                                              ..
..                                              ..
..................................................
..................................................

The box is height and width 50, spaces are two wide.

You must write a function or program which outputs or returns a string and takes no input.

Fewest bytes wins!

*/

package main

import "fmt"

func main() {
	fmt.Println(box)
}

const box = `
..................................................
..................................................
..                                              ..
..                                              ..
..  ++++++++++++++++++++++++++++++++++++++++++  ..
..  ++++++++++++++++++++++++++++++++++++++++++  ..
..  ++                                      ++  ..
..  ++                                      ++  ..
..  ++  ..................................  ++  ..
..  ++  ..................................  ++  ..
..  ++  ..                              ..  ++  ..
..  ++  ..                              ..  ++  ..
..  ++  ..  ++++++++++++++++++++++++++  ..  ++  ..
..  ++  ..  ++++++++++++++++++++++++++  ..  ++  ..
..  ++  ..  ++                      ++  ..  ++  ..
..  ++  ..  ++                      ++  ..  ++  ..
..  ++  ..  ++  ..................  ++  ..  ++  ..
..  ++  ..  ++  ..................  ++  ..  ++  ..
..  ++  ..  ++  ..              ..  ++  ..  ++  ..
..  ++  ..  ++  ..              ..  ++  ..  ++  ..
..  ++  ..  ++  ..  ++++++++++  ..  ++  ..  ++  ..
..  ++  ..  ++  ..  ++++++++++  ..  ++  ..  ++  ..
..  ++  ..  ++  ..  ++      ++  ..  ++  ..  ++  ..
..  ++  ..  ++  ..  ++      ++  ..  ++  ..  ++  ..
..  ++  ..  ++  ..  ++  ..  ++  ..  ++  ..  ++  ..
..  ++  ..  ++  ..  ++  ..  ++  ..  ++  ..  ++  ..
..  ++  ..  ++  ..  ++      ++  ..  ++  ..  ++  ..
..  ++  ..  ++  ..  ++      ++  ..  ++  ..  ++  ..
..  ++  ..  ++  ..  ++++++++++  ..  ++  ..  ++  ..
..  ++  ..  ++  ..  ++++++++++  ..  ++  ..  ++  ..
..  ++  ..  ++  ..              ..  ++  ..  ++  ..
..  ++  ..  ++  ..              ..  ++  ..  ++  ..
..  ++  ..  ++  ..................  ++  ..  ++  ..
..  ++  ..  ++  ..................  ++  ..  ++  ..
..  ++  ..  ++                      ++  ..  ++  ..
..  ++  ..  ++                      ++  ..  ++  ..
..  ++  ..  ++++++++++++++++++++++++++  ..  ++  ..
..  ++  ..  ++++++++++++++++++++++++++  ..  ++  ..
..  ++  ..                              ..  ++  ..
..  ++  ..                              ..  ++  ..
..  ++  ..................................  ++  ..
..  ++  ..................................  ++  ..
..  ++                                      ++  ..
..  ++                                      ++  ..
..  ++++++++++++++++++++++++++++++++++++++++++  ..
..  ++++++++++++++++++++++++++++++++++++++++++  ..
..                                              ..
..                                              ..
..................................................
..................................................

`
