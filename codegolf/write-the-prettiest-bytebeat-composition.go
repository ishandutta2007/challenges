/*

Bytebeat is a style of music one can compose by writing a simple C program that's output is piped to aplay or /dev/dsp.

main(t){for(;;t++)putchar(((t<<1)^((t<<1)+(t>>7)&t>>12))|t>>(4-(1^7&(t>>19)))|t>>7);}
There is a good deal of information on the bytebeat site, a javascript implementation, and more demos and example compositions in this thread.

Very simple rules : Try to write a pretty sounding composition. Most up votes wins since that's obviously subjective, although not that subjective considering the usual results.

*/

package main

import (
	"bufio"
	"os"
)

func main() {
	w := bufio.NewWriter(os.Stdout)
	for t := uint(0); ; t++ {
		v := ((t << 1) ^ (((t << 1) + (t >> 7)) & (t >> 12))) | ((t >> (4 - (1 ^ (7 & (t >> 19))))) | (t >> 7))
		w.WriteByte(byte(v))
	}
}
