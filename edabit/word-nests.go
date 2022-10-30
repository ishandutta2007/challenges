/*

A word nest is created by taking a starting word, and generating a new string by placing the word inside itself. This process is then repeated.

Nesting 3 times with the word "incredible":

start  = incredible
first  = incre|incredible|dible
second = increin|incredible|credibledible
third  = increinincr|incredible|ediblecredibledible

The final nest is "increinincrincredibleediblecredibledible" (depth = 3).

Given a starting word and the final word nest, return the depth of the word nest.

*/

package main

import (
	"fmt"
	"strings"
)

func main() {
	test("incredible", "increinincrincredibleediblecredibledible")
	test("floor", "floor")
	test("code", "cocodccococodededeodeede")
	test("engagement", "engenengagemengagemeengagementntentgagementagement")
	test("passage", "passpassageage")
	test("factory", "ffacfactofactfafactoryctoryoryrytoryactory")
	test("deny", "ddededdddenyenyenyenynynyeny")
	test("jinx", "jijijjijjijijjinxinxnxnxinxnxinxnxnx")
	test("deal", "dedddealealealal")
	test("paradox", "parparaparadoxdoxadox")
	test("meet", "mmememmeeteeteteteet")
	test("last", "lalastst")
	test("silence", "sisilsisilencelenceencelence")
	test("inflate", "inflate")
	test("ruin", "rurrurrrrrrururuinininuinuinuinuinuininuinin")
	test("episode", "episoepisepisepiepiepiepisoepisodedesodesodesodeodeodede")
	test("dictate", "dictadicdidictdiddictadictadictateteteictatectateatectatetatete")
	test("caller", "callcacacalccallcacaccallerallerllerllererallerlerllerllerer")
	test("sweater", "sweatsweswsweatereateraterer")
	test("measure", "measumememeasumemmeasmmeasureeasureureeasureasurereasureasurere")
	test("relieve", "relierelierelrelierrelieveelieveveieveveve")
	test("home", "hohohohhohohhhohhomeomemeomeomememeomemememe")
	test("profession", "profesprofessionsion")
	test("continuous", "contcontcontinuoconcocontinuousntinuoustinuoususinuousinuous")
}

func test(w, n string) {
	fmt.Println(wordnestit(w, n), wordnestclosed(w, n))
}

func wordnestit(w, n string) int {
	d := 0
	for ; n != w; d++ {
		i := strings.Index(n, w)
		if i < 0 {
			return -1
		}
		n = n[:i] + n[i+len(w):]
	}
	return d
}

func wordnestclosed(w, n string) int {
	return len(n)/len(w) - 1
}
