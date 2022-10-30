/*

This! is an RGB colour grid...

Basic RGB grid

Basically it's a 2-dimensional matrix in which:

    The first row, and the first column, are red.
    The second row, and the second column, are green.
    The third row, and the third column, are blue.

Here are the colours described graphically, using the letters R, G, and B.

row and column diagram

Here's how we calculate the colour of each space on the grid is calculated.

    Red + Red = Red (#FF0000)
    Green + Green = Green (#00FF00)
    Blue + Blue = Blue (#0000FF)
    Red + Green = Yellow (#FFFF00)
    Red + Blue = Purple (#FF00FF)
    Green + Blue = Teal (#00FFFF)

The Challenge

    Write code to generate an RGB colour grid.
    It's code golf, so attempt to do so in the smallest number of bytes.
    Use any programming language or markup language to generate your grid.
    Things I care about:
        The result should graphically display an RGB grid with the defined colours.
    Things I don't care about:
        If the output is an image, HTML, SVG or other markup.
        The size or shape of the colour blocks.
        Borders, spacing etc between or around the blocks.
        It definitely doesn't have to have labels telling you what the row and column colours should be.

*/

package main

import (
	"image"
	"image/color"
	"image/draw"
	"image/png"
	"os"
)

func main() {
	m := gen(600, 600)
	png.Encode(os.Stdout, m)
}

func gen(w, h int) *image.RGBA {
	tab := [3][3]color.RGBA{
		{red, yellow, purple},
		{yellow, green, teal},
		{purple, teal, blue},
	}

	s := min(w, h) / 3
	m := image.NewRGBA(image.Rect(0, 0, w, h))
	for y := 0; y < 3; y++ {
		for x := 0; x < 3; x++ {
			r := image.Rect(x*s, y*s, (x+1)*s, (y+1)*s)
			draw.Draw(m, r, image.NewUniform(color.Black), image.ZP, draw.Src)

			r = r.Inset(2)
			draw.Draw(m, r, image.NewUniform(tab[y][x]), image.ZP, draw.Src)
		}
	}
	return m
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

var (
	red    = color.RGBA{255, 0, 0, 255}
	green  = color.RGBA{0, 255, 0, 255}
	blue   = color.RGBA{0, 0, 255, 255}
	yellow = color.RGBA{255, 255, 0, 255}
	purple = color.RGBA{255, 0, 255, 255}
	teal   = color.RGBA{0, 255, 255, 255}
)
