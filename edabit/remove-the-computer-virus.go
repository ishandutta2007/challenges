/*

Your computer might have been infected by a virus! Create a function that finds the viruses in files and removes them from your computer.

Examples

remove_virus("PC Files: spotifysetup.exe, virus.exe, dog.jpg") ➞ "PC Files: spotifysetup.exe, dog.jpg"

remove_virus("PC Files: antivirus.exe, cat.pdf, lethalmalware.exe, dangerousvirus.exe ") ➞ "PC Files: antivirus.exe, cat.pdf"

remove_virus("PC Files: notvirus.exe, funnycat.gif") ➞ "PC Files: notvirus.exe, funnycat.gif")

Notes

    Bad files will contain "virus" or "malware", but "antivirus" and "notvirus" will not be viruses.
    Return "PC Files: Empty" if there are no files left on the computer.

*/

package main

import (
	"bytes"
	"fmt"
	"strings"
)

func main() {
	test("PC Files: spotifysetup.exe, virus.exe, dog.jpg", "PC Files: spotifysetup.exe, dog.jpg")
	test("PC Files: antivirus.exe, cat.pdf, lethalmalware.exe, dangerousvirus.exe ", "PC Files: antivirus.exe, cat.pdf")
	test("PC Files: notvirus.exe, funnycat.gif", "PC Files: notvirus.exe, funnycat.gif")
	test("PC Files: virus.exe, bestmalware.exe, memzvirus.exe", "PC Files: Empty")
}

func test(s, r string) {
	assert(remove(s) == r)
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func remove(s string) string {
	s = strings.TrimPrefix(s, "PC Files:")
	t := strings.Split(s, ",")

	var p []string
	for _, t := range t {
		t = strings.TrimSpace(t)
		switch {
		case strings.Index(t, "antivirus") >= 0 || strings.Index(t, "notvirus") >= 0:
			p = append(p, t)
		case !(strings.Index(t, "virus") >= 0 || strings.Index(t, "malware") >= 0):
			p = append(p, t)
		}
	}
	if len(p) == 0 {
		return "PC Files: Empty"
	}

	w := new(bytes.Buffer)
	fmt.Fprintf(w, "PC Files: ")
	for i := range p {
		fmt.Fprintf(w, "%s, ", p[i])
	}
	r := w.String()
	r = r[:len(r)-2]
	return r
}
