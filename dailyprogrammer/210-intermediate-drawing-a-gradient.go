/*

Description
One of the most basic tools in graphic design toolbox is the "gradient": a smooth transtion from one color to another.
They are remarkably useful and are available in virtually every graphic design program and graphic programming library, and even natively in design languages like CSS and SVG.

Your task today is to make a program that can generate these wonderful gradients, and then either draw it to the screen or save it as an image file.
You will get as inputs pixel dimensions for the size of the gradient, and the two colors that the gradient should transition between.

NOTE: As I said, there are many imaging libraries that provide this functionality for you, usually in some function called drawGradient() or something similar.
You are strongly encouraged not to use functions like this, the spirit of this challenge is that you should figure out how to calculate the gradient (and thus the individual pixel colors) yourself.

This isn't an ironclad rule, and if you really can't think of any way to do this yourself, then it's fine to submit your solution using one of these functions. I encourage you to try, though.

It is, however, perfectly acceptable to use a library to save your pixels in whatever format you like.

Formal Inputs & Outputs

Input description
Your input will consist of three lines. The first line contains two numbers which is the width and the height of the resulting gradient.
The other two lines consist of three numbers between 0 and 255 representing the colors that the gradient should transition between.
The first color should be on the left edge of the image, the second color should be on the right edge of the image.

So, for instance, the input

500 100
255 255 0
0 0 255
means that you should draw a 500x100 gradient that transitions from yellow on the left side to blue on the right side.

Output description
You can either choose to draw your gradient to the screen or save it as an image file. You can choose whatever image format you want, though it should preferably a lossless format like PNG.

If you don't wish to tangle with libraries that output PNG images, I recommend checking out the Netpbm format, which is a very easy format to output images in. There's even a dailyprogrammer challenge that can help you out.

Regardless of your chosen method of output, I highly encourage you to upload your resulting images to imgur so that the rest of us can see the product of your hard work!
If you chose to output your image to the screen, you can take a screenshot and crop the gradient out.

Example inputs & outputs
Input
500 100
255 255 0
0 0 255
Output
This image

Challenge inputs
1000 100
204 119 34
1 66 37
Those two colors are Ochre and British Racing Green, my two favorite colors. Use those as a challenge input, or pick your own two favorite colors!

Bonus
We often see people solving these problems in weird languages here at r/dailyprogrammer, and this bonus is for all you crazy people:

Solve this problem in brainfuck. You don't have to read the values from input, you can "hard-code" the colors and dimensions in your program.
You can pick whatever colors and dimensions you like, as long as both the width and the height is larger than 100 pixels.
You can also output the image in whatever format you want (I imagine that one of the binary Netpbm formats will be the easiest). Good luck!

Finally
Have a good challenge idea?

Consider submitting it to r/dailyprogrammer_ideas

*/

package main

import (
	"image"
	"image/color"
	"image/png"
	"math"
	"os"
)

func main() {
	output("gradient-1.png", gradient(500, 100, color.RGBA{255, 255, 0, 255}, color.RGBA{0, 0, 255, 255}))
	output("gradient-2.png", gradient(1000, 100, color.RGBA{204, 119, 34, 255}, color.RGBA{1, 66, 37, 255}))
}

func output(name string, img *image.RGBA) error {
	f, err := os.Create(name)
	if err != nil {
		return err
	}
	err = png.Encode(f, img)
	xerr := f.Close()
	if err == nil {
		err = xerr
	}
	return err
}

func gradient(width, height int, c0, c1 color.RGBA) *image.RGBA {
	img := image.NewRGBA(image.Rect(0, 0, width, height))
	for x := 0; x < width; x++ {
		r := linear_remap(float64(x), 0, float64(width), float64(c0.R), float64(c1.R))
		g := linear_remap(float64(x), 0, float64(width), float64(c0.G), float64(c1.G))
		b := linear_remap(float64(x), 0, float64(width), float64(c0.B), float64(c1.B))

		r = math.Round(r)
		g = math.Round(g)
		b = math.Round(b)

		for y := 0; y < height; y++ {
			img.Set(x, y, color.RGBA{uint8(r), uint8(g), uint8(b), 255})
		}
	}
	return img
}

func lerp(t, a, b float64) float64 {
	return a + t*(b-a)
}

func unlerp(t, a, b float64) float64 {
	return (t - a) / (b - a)
}

func linear_remap(x, a, b, c, d float64) float64 {
	return lerp(unlerp(x, a, b), c, d)
}
