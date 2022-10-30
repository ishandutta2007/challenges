/*

Consider this file path:

C:/Users/Martin/Desktop/BackupFiles/PC1/images/cars/new.png
Your goal is to write a program that will return the file path starting from the folder after the last folder that contains a number till the filename. So, for the above file path, the program should return images/cars/new.png.

One or more of the folder names may also contain spaces:

C:/Users/User1/Documents/Books/eBooks/PM2.4/ref/Project Management.pdf
should return ref/Project Management.pdf.

Also this filepath:

C:/Users/John/Videos/YouTube/3D/Animations/52.Tricky.Maneuvers/video234.png
should return video234.png.

Your answer should work with the above given three examples and all other examples that match the criteria described here.

This is code-golf, so the answer with the lowest number of bytes yields victory.

I am new to the site, so feel free to modify my post and/or add relevant tags.

*/

package main

import (
	"path"
)

func main() {
	assert(restpath("C:/Users/Martin/Desktop/BackupFiles/PC1/images/cars/new.png") == "images/cars/new.png")
	assert(restpath("C:/Users/User1/Documents/Books/eBooks/PM2.4/ref/Project Management.pdf") == "ref/Project Management.pdf")
	assert(restpath("C:/Users/John/Videos/YouTube/3D/Animations/52.Tricky.Maneuvers/video234.png") == "video234.png")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func restpath(s string) string {
	r := ""
	for n := 0; ; n++ {
		d := path.Dir(s)
		b := path.Base(s)
		if n > 0 && hasdigit(b) {
			break
		}
		r = path.Join(b, r)
		s = d
	}
	return r
}

func hasdigit(s string) bool {
	for _, r := range s {
		if '0' <= r && r <= '9' {
			return true
		}
	}
	return false
}
