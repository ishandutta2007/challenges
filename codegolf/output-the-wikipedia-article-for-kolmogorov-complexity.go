/*

Your job is to output the html of the current version (at the time of this writing) of the Wikipedia page for Kolmogorov complexity:
https://en.wikipedia.org/w/index.php?title=Kolmogorov_complexity&oldid=781950121&action=raw (backup)

This is code-golf, so the shortest code wins.

*/

package main

import (
	"fmt"
	"io"
	"net/http"
	"os"
)

func main() {
	output("https://en.wikipedia.org/w/index.php?title=Kolmogorov_complexity&oldid=781950121&action=raw")
}

func output(url string) {
	resp, err := http.Get(url)
	if err != nil {
		fmt.Println(err)
		return
	}

	io.Copy(os.Stdout, resp.Body)
	fmt.Println()
}
