/*

Write a program that can validate a PNG file. Your program should follow the PNG spec and must validate the PNG signature and the 4 critical chunks: IHDR, IDAT, PLTE and IEND.
Your program must not validate the contents of ancillary chunks, except for their CRC checksums.

Your program must validate the presence of the PLTE chunk (that is, This chunk shall appear for colour type 3, and may appear for colour types 2 and 6; it shall not appear for colour types 0 and 4. There shall not be more than one PLTE chunk. ref)

Your program must validate chunk order.

Your program must validate CRC checksums.

Your program must validate the compressed data.

You may use runtime code generation+execution (e.g. compress the program itself, or algorithmically write the program itself a la kolmogorov complexity).
If any binary blobs are used, their source code will be considered when calculating size.

External library source code size counts towards program size. This is to discourage image-parsing external libraries while allowing e.g. a CRC32 library. Libraries defined in the language specification (aka "standard libraries") don't count as external.

No regex.

You must specify how to input the file. Your program must output to stdout "true" or "false" to answer the question "is the file a valid PNG?".

Failing test files:

This file is false.

(Yes, that's a plaintext file. Newline-terminated.)

Passing test files:

*/

package main

import (
	"bufio"
	"flag"
	"fmt"
	"image/png"
	"os"
)

func main() {
	flag.Parse()
	if flag.NArg() < 1 {
		usage()
	}
	for _, name := range flag.Args() {
		fmt.Printf("%v: %v\n", name, validate(name))
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: file ...")
	flag.PrintDefaults()
	os.Exit(2)
}

func validate(name string) bool {
	f, err := os.Open(name)
	if err != nil {
		return false
	}
	defer f.Close()

	r := bufio.NewReader(f)
	_, err = png.Decode(r)
	return err == nil
}
