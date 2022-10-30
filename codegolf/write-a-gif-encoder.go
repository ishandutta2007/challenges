/*

Yes, the good old GIF. Loved for its versatility, hated for its patents and partly obsoleted due to its limitations (and patents), GIF consists, at the core, of a color palette and a palette-indexed image compressed using the LZW algorithm.

Your task is to write a program that reads an image in ASCII PPM format ("P3" magic number) from the standard input, and writes the same image (identical pixel-by-pixel) in GIF format to the standard output. The output can either be in binary form, or ASCII text with each byte represented by a number between 0 and 255 (inclusive), separated by whitespace.

The input image is guaranteed not to have more than 256 different colors.

Scoring:

Your program will be tested on 3 sample images, and your score will be calculated as:
program size + sum(output size - reference size for each sample image)
Lowest score wins.

Requirements:

    Your program must work with any similar kinds of images of various sizes, and not be limited to the sample images. You could, for example, restrict the dimensions to be multiples of 2 or assume that the ppm max color is 255, but it should still work with a wide variety of input images.
    The output must be a valid GIF file that can be loaded with any compliant program (after converting back to binary if using the ASCII output option).
    You can not use any image processing functions (built-in or third-party), your program must contain all the relevant code.
    Your program must be runnable in Linux using freely available software.
    The source code must use only ASCII characters.

Sample images:

Here are the 3 sample images that will be used for scoring. You can download a zip archive with the ppm files (use the download button on the top of that page). Or you can convert them from the png images below, using ImageMagick with the following command:

convert file.png -compress none file.ppm

I am also providing the MD5 checksums of the ppm files for confirmation.

1. amber

amber.png

Reference size: 38055
MD5 checksum of ppm: d1ad863cb556869332074717eb278080

2. blueeyes

blueeyes.png

Reference size: 28638
MD5 checksum of ppm: e9ad410057a5f6c25a22a534259dcf3a

3. peppers

peppers.png

Reference size: 53586
MD5 checksum of ppm: 74112dbdbb8b7de5216f9e24c2e1a627

*/

package main

import (
	"flag"
	"fmt"
	"image"
	"image/gif"
	_ "image/jpeg"
	_ "image/png"
	"log"
	"os"
)

func main() {
	flag.Usage = usage
	flag.Parse()
	if flag.NArg() != 2 {
		usage()
	}

	r, err := os.Open(flag.Arg(0))
	ck(err)

	m, _, err := image.Decode(r)
	ck(err)

	w, err := os.Create(flag.Arg(1))
	ck(err)

	ck(gif.Encode(w, m, &gif.Options{NumColors: 256}))
	ck(w.Close())
}

func ck(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func usage() {
	fmt.Fprintln(os.Stderr, "usage: [options] input output")
	flag.PrintDefaults()
	os.Exit(2)
}
