/*

Similar to the images on allrgb.com, make images where each pixel is a unique color (no color is used twice and no color is missing).

Give a program that generates such an image, along with a screenshot or file of the output (upload as PNG).

    Create the image purely algorithmically.
    Image must be 256×128 (or grid that can be screenshot and saved at 256×128)
    Use all 15-bit colors*
    No external input allowed (also no web queries, URLs or databases)
    No embedded images allowed (source code which is an image is fine, e.g. Piet)
    Dithering is allowed
    This is not a short code contest, although it might win you votes.
    If you're really up for a challenge, do 512×512, 2048×1024 or 4096×4096 (in increments of 3 bits).

Scoring is by vote. Vote for the most beautiful images made by the most elegant code and/or interesting algorithm.

Two-step algorithms, where you first generate a nice image and then fit all pixels to one of the available colors, are of course allowed, but won't win you elegance points.

* 15-bit colors are the 32768 colors that can be made by mixing 32 reds, 32 greens, and 32 blues, all in equidistant steps and equal ranges. Example: in 24 bits images (8 bit per channel), the range per channel is 0..255 (or 0..224), so divide it up into 32 equally spaced shades.

To be very clear, the array of image pixels should be a permutation, because all possible images have the same colors, just at different pixels locations. I'll give a trivial permutation here, which isn't beautiful at all:
Java 7

import java.awt.image.BufferedImage;
import java.io.BufferedOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import javax.imageio.ImageIO;

public class FifteenBitColors {
    public static void main(String[] args) {
        BufferedImage img = new BufferedImage(256, 128, BufferedImage.TYPE_INT_RGB);

        // Generate algorithmically.
        for (int i = 0; i < 32768; i++) {
            int x = i & 255;
            int y = i / 256;
            int r = i << 3 & 0xF8;
            int g = i >> 2 & 0xF8;
            int b = i >> 7 & 0xF8;
            img.setRGB(x, y, (r << 8 | g) << 8 | b);
        }

        // Save.
        try (OutputStream out = new BufferedOutputStream(new FileOutputStream("RGB15.png"))) {
            ImageIO.write(img, "png", out);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

enter image description here
Winner

Because the 7 days are over, I'm declaring a winner

However, by no means, think this is over. I, and all readers, always welcome more awesome designs. Don't stop creating.

Winner: fejesjoco with 231 votes

*/

package main

import (
	"image"
	"image/color"
	"image/png"
	"os"
)

func main() {
	png.Encode(os.Stdout, gen())
}

func gen() *image.RGBA {
	r := image.Rect(0, 0, 256, 128)
	m := image.NewRGBA(r)
	for i := 0; i < 32768; i++ {
		x := i & 0xff
		y := i >> 8
		r := (i << 3) & 0xf8
		g := (i >> 2) & 0xf8
		b := (i >> 7) & 0xf8
		m.SetRGBA(x, y, color.RGBA{uint8(r), uint8(g), uint8(b), 255})
	}
	return m
}
