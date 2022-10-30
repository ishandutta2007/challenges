/*

Intro

Given radius r, draw a circle in the center of the screen.

Sandbox.
The Challenge

Here is a simple challenge.

Plot a circle using the formula x2+y2=r2, or any other formula that will plot a circle according to the given parameters.

You may use any units that your language provides, so long as they are well defined and give consistent output.

The circle must have it's center at the center of the canvas, and must have a padding of 5 units or more on all sides.

The circle can have any fill that does not match the outline.

You may have axes in the background of your plot.

The outline of the circle must be solid (no gaps), and it must be visible. Here is an example:

enter image description here

Input can be taken in any acceptable form. (function params, variables, stdin...)

Output can be in the form of a separate window, or an image format.

Standard loopholes and rules apply.
Example Code (Java + Processing)

// Modified from the C language example from
// https:// en.wikipedia.org/wiki/Midpoint_circle_algorithm
int r = 70; //radius
void settings() {
  size(2*r+10, 2*r+10);
}

void draw() {
  background(255);
  drawCircle(width/2, height/2, r, 60);
  save("Circle.png");
}


void drawCircle(int x0, int y0, int radius, int angle) {
  int circCol = color(0, 0, 0);
  float limit = radians(angle);
  int x = radius;
  int y = 0;
  int err = 0;

  while (x >= y && atan2(y, x) < limit) {
    set(x0 + x, y0 + y, circCol);
    set(x0 + y, y0 + x, circCol);
    set(x0 - y, y0 + x, circCol);
    set(x0 - x, y0 + y, circCol);
    set(x0 - x, y0 - y, circCol);
    set(x0 - y, y0 - x, circCol);
    set(x0 + y, y0 - x, circCol);
    set(x0 + x, y0 - y, circCol);

    y += 1;
    if (err <= 0) {
      err += 2*y + 1;
    }
    if (err > 0) {
      x -= 1;
      err -= 2*x + 1;
    }
  }
}

Scoring

This is a graphical-output question. No ascii art.

This is code-golf. shortest answer in each language wins.

*/

package main

import (
	"image"
	"image/color"
	"image/draw"
	"image/png"
	"math"
	"os"
)

func main() {
	png.Encode(os.Stdout, gen(256))
}

func gen(r int) *image.RGBA {
	s := 2*r + 10
	m := image.NewRGBA(image.Rect(0, 0, s, s))
	draw.Draw(m, m.Bounds(), image.NewUniform(color.White), image.ZP, draw.Src)
	circle(m, s/2, s/2, r, 60, color.Black)
	return m
}

func circle(m *image.RGBA, x0, y0, r, a int, col color.Color) {
	l := radians(float64(a))
	x := r
	y := 0
	err := 0

	for x >= y && math.Atan2(float64(y), float64(x)) < l {
		m.Set(x0+x, y0+y, col)
		m.Set(x0+y, y0+x, col)
		m.Set(x0-y, y0+x, col)
		m.Set(x0-x, y0+y, col)
		m.Set(x0-x, y0-y, col)
		m.Set(x0-y, y0-x, col)
		m.Set(x0+y, y0-x, col)
		m.Set(x0+x, y0-y, col)

		y += 1
		if err <= 0 {
			err += 2*y + 1
		}
		if err > 0 {
			x -= 1
			err -= 2*x + 1
		}
	}
}

func radians(x float64) float64 {
	return x * math.Pi / 180
}
