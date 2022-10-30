/*

In 2014, demoscener Jakub 'Ilmenit' Debski released a 250-byte(1) procedural graphics demo for the Atari XL called Mona. It's drawing the following picture(2):

mona

Your task is to generate the exact same picture, using the language of your choice.

(1) Breakdown: 136 bytes of data + 114 bytes of code.
(2) The original picture is 128x96. The above version was magnified to 256x192. A few pixels differ from the original, but this is the expected output with the pseudo-code described in this challenge.
How?

This is code-golf. Although you're authorized to use any method, best results will most probably be achieved by using the original algorithm which is described below.

NB: This paragraph is not a specification but rather a general description. Please refer to the pseudo-code and the reference implementation for the details of the algorithm.

The image is made of 64 pseudo-random brush strokes (see this video), cycling through the following colors (in RRGGBB hexadecimal format):

COLOR = [ 0xFFE289, 0xE99E45, 0xA55A00, 0x000000 ]

The background is initially filled with the 4th color (black). Each stroke is shorter than the previous one.

The pseudo-random generator is using a Linear-Feedback Shift Register (LFSR) on a 32-bit integer initially set to 0x7EC80000 and XOR'ed with 0x04C11DB7.

Each stroke is initialized with a 16-bit value which overwrites the least significant bytes of the seed:

BRUSH = [
  0x030A, 0x37BE, 0x2F9B, 0x072B, 0x0E3C, 0xF59B, 0x8A91, 0x1B0B,
  0x0EBD, 0x9378, 0xB83E, 0xB05A, 0x70B5, 0x0280, 0xD0B1, 0x9CD2,
  0x2093, 0x209C, 0x3D11, 0x26D6, 0xDF19, 0x97F5, 0x90A3, 0xA347,
  0x8AF7, 0x0859, 0x29AD, 0xA32C, 0x7DFC, 0x0D7D, 0xD57A, 0x3051,
  0xD431, 0x542B, 0xB242, 0xB114, 0x8A96, 0x2914, 0xB0F1, 0x532C,
  0x0413, 0x0A09, 0x3EBB, 0xE916, 0x1877, 0xB8E2, 0xAC72, 0x80C7,
  0x5240, 0x8D3C, 0x3EAF, 0xAD63, 0x1E14, 0xB23D, 0x238F, 0xC07B,
  0xAF9D, 0x312E, 0x96CE, 0x25A7, 0x9E37, 0x2C44, 0x2BB9, 0x2139
];

These values are also used to set the new position (bx, by) of the brush at the beginning of the stroke: bx is given by the least significant byte and by is given by the most significant byte.

The direction of the stroke is given by bits #1 and #7 of the seed. (See the SWITCH statement in the pseudo-code.)
Pseudo-code

Below is the algorithm in pseudo-code, assuming 0-indexed arrays, where AND, OR and XOR mean bitwise operations.

seed = 0x7EC80000
dir = 0x00

FOR part = 0 TO 63
  word = BRUSH[part]
  seed = (seed AND 0xFFFF0000) OR word
  bx = word AND 0xFF
  by = (word >> 8) AND 0xFF

  FOR len = 0 TO (64 - part) * 32 - 1
    carry = seed AND 0x80000000
    seed = (seed << 1) AND 0xFFFFFFFF

    IF carry
      seed = seed XOR 0x04C11DB7
      dir = seed AND 0xFF
    ENDIF

    SWITCH dir AND 0x82
      CASE 0x00:
        by = (by + 1) AND 0x7F
      ENDCASE
      CASE 0x02:
        bx = (bx + 1) AND 0x7F
      ENDCASE
      CASE 0x80:
        by = (by - 1) AND 0x7F
      ENDCASE
      CASE 0x82:
        bx = (bx - 1) AND 0x7F
      ENDCASE
    ENDSWITCH

    drawPixel(bx, by, COLOR[part AND 3])
  ENDFOR
ENDFOR

Reference implementation

Below is an ungolfed reference implementation in JavaScript.

Hide code snippet

const SEED    = 0x7EC80000,
      XOR_MSK = 0x04C11DB7,
      COLOR   = [
        '#FFE289', '#E99E45', '#A55A00', '#000000'
      ],
      BRUSH   = [
        0x030A, 0x37BE, 0x2F9B, 0x072B, 0x0E3C, 0xF59B, 0x8A91, 0x1B0B,
        0x0EBD, 0x9378, 0xB83E, 0xB05A, 0x70B5, 0x0280, 0xD0B1, 0x9CD2,
        0x2093, 0x209C, 0x3D11, 0x26D6, 0xDF19, 0x97F5, 0x90A3, 0xA347,
        0x8AF7, 0x0859, 0x29AD, 0xA32C, 0x7DFC, 0x0D7D, 0xD57A, 0x3051,
        0xD431, 0x542B, 0xB242, 0xB114, 0x8A96, 0x2914, 0xB0F1, 0x532C,
        0x0413, 0x0A09, 0x3EBB, 0xE916, 0x1877, 0xB8E2, 0xAC72, 0x80C7,
        0x5240, 0x8D3C, 0x3EAF, 0xAD63, 0x1E14, 0xB23D, 0x238F, 0xC07B,
        0xAF9D, 0x312E, 0x96CE, 0x25A7, 0x9E37, 0x2C44, 0x2BB9, 0x2139
      ];

var ctx = document.getElementById('output').getContext('2d'),
    seed = SEED,
    bx, by, word, len, carry,
    dir = 0,
    part;

ctx.fillStyle = COLOR[3];
ctx.fillRect(0, 0, 128 * 2, 128 * 2);

for(part = 0; part < 64; part++) {
  word = BRUSH[part];
  seed = (seed & 0xffff0000) | word;
  bx = word & 0xff;
  by = (word >> 8) & 0xff;

  ctx.fillStyle = COLOR[part & 3];

  for(len = 0; len < (64 - part) * 32; len++) {
    carry = seed & 0x80000000;
    seed <<= 1;

    if(carry) {
      seed ^= XOR_MSK;
      dir = seed & 0xff;
    }

    switch(dir & 0x82) {
      case 0x00:
        by = (by + 1) & 0x7f;
        break;

      case 0x02:
        bx = (bx + 1) & 0x7f;
        break;

      case 0x80:
        by = (by - 1) & 0x7f;
        break;

      case 0x82:
        bx = (bx - 1) & 0x7f;
        break;
    }
    ctx.fillRect(bx * 2, by * 2, 2, 2);
  }
}

<canvas id="output" width=256 height=192></canvas>

Expand snippet

You can also see an animated version here.
Clarification and rules

    The output must be cropped to 128x96, even though the algorithm draws outside this area.
    If your language/platform is not able to output the exact colors described above, you must use colors that are as close as possible.
    Should you decide to use an alternate method, you still must generate the exact same output.
    Just in case: submitting the original 6502 assembly code or any slightly edited version is not allowed.
    Can you beat 250 bytes? Happy drawing!

*/

package main

import (
	"flag"
	"image"
	"image/color"
	"image/draw"
	"image/png"
	"os"
)

func main() {
	mag := flag.Int("magnify", 4, "magnify by amount")
	flag.Parse()

	png.Encode(os.Stdout, monalisa(*mag))
}

func monalisa(mag int) *image.RGBA {
	COLOR := []color.RGBA{
		{0xFF, 0xE2, 0x89, 0xFF},
		{0xE9, 0x9E, 0x45, 0xFF},
		{0xA5, 0x5A, 0x00, 0xFF},
		{0x00, 0x00, 0x00, 0xFF},
	}
	BRUSH := []uint32{
		0x030A, 0x37BE, 0x2F9B, 0x072B, 0x0E3C, 0xF59B, 0x8A91, 0x1B0B,
		0x0EBD, 0x9378, 0xB83E, 0xB05A, 0x70B5, 0x0280, 0xD0B1, 0x9CD2,
		0x2093, 0x209C, 0x3D11, 0x26D6, 0xDF19, 0x97F5, 0x90A3, 0xA347,
		0x8AF7, 0x0859, 0x29AD, 0xA32C, 0x7DFC, 0x0D7D, 0xD57A, 0x3051,
		0xD431, 0x542B, 0xB242, 0xB114, 0x8A96, 0x2914, 0xB0F1, 0x532C,
		0x0413, 0x0A09, 0x3EBB, 0xE916, 0x1877, 0xB8E2, 0xAC72, 0x80C7,
		0x5240, 0x8D3C, 0x3EAF, 0xAD63, 0x1E14, 0xB23D, 0x238F, 0xC07B,
		0xAF9D, 0x312E, 0x96CE, 0x25A7, 0x9E37, 0x2C44, 0x2BB9, 0x2139,
	}
	SEED := uint32(0x7EC80000)
	XORMASK := uint32(0x04C11DB7)

	img := image.NewRGBA(image.Rect(0, 0, mag*128, mag*128))
	draw.Draw(img, img.Bounds(), image.NewUniform(COLOR[3]), image.ZP, draw.Src)

	seed := SEED
	dir := uint32(0)
	for part := 0; part < 64; part++ {
		word := BRUSH[part]
		seed = (seed & 0xFFFF0000) | word
		bx := word & 0xFF
		by := (word >> 8) & 0xFF

		col := COLOR[part&3]
		for len := 0; len < (64-part)*32; len++ {
			carry := seed & 0x80000000
			seed = (seed << 1) & 0xFFFFFFFF

			if carry != 0 {
				seed ^= XORMASK
				dir = seed & 0xFF
			}

			switch dir & 0x82 {
			case 0x00:
				by = (by + 1) & 0x7F
			case 0x02:
				bx = (bx + 1) & 0x7F
			case 0x80:
				by = (by - 1) & 0x7F
			case 0x82:
				bx = (bx - 1) & 0x7F
			}

			ix := int(bx * uint32(mag))
			iy := int(by * uint32(mag))
			draw.Draw(img, image.Rect(ix, iy, ix+mag, iy+mag), image.NewUniform(col), image.ZP, draw.Src)
		}
	}

	return img
}
