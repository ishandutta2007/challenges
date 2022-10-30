/*

This rar file, when decompressed, gives a 65024-byte exe file. Requiring you to output the contents of that file would be absolutely no fun.

But you aren't required to do that. Actually, you're to do something opposite: Output a binary of the same length (65024 bytes), such that no byte equals the byte at same position in the source exe file.

This is code-golf, shortest code wins.

*/

package main

import (
	"io"
	"os"
)

func main() {
	io.Copy(&flipper{os.Stdout, make([]byte, 32768)}, os.Stdin)
}

type flipper struct {
	w io.Writer
	p []byte
}

func (f *flipper) Write(b []byte) (n int, err error) {
	for n < len(b) {
		j := min(len(f.p), len(b)-n)
		for i := 0; i < j; i++ {
			f.p[i] = ^b[n+i]
		}

		m, err := f.w.Write(f.p[:j])
		if n += m; err != nil {
			break
		}
	}
	return
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
