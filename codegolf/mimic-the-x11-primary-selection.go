/*

Background

In X11 (a windowing system used by a lot of Unix-like OS), what you would call the clipboard behave a bit differently than on other OSes like MacOS or Windows.
While the "traditional" clipboard using ctrl+v/ctrl+c works, there is also another clipboard, called PRIMARY selection, that behave as following:

when you select a piece of text, this selection is added to the clipboard
when you use the middle mouse button, the content of that selection is pasted where your mouse is.
Some more details for those who are interested : X11: How does “the” clipboard work?

Challenge
The input in this challenge is any representation of a binary input. In the following I will use 'S' for select and 'P' for paste.

Given the input, you must output the input after making the following changes :

put the content of the current output in the primary selection when you receive a select instruction
paste the content of the primary selection in the middle of the current output when you receive a paste instruction. If the current output is odd numbered, the middle is the length divided by 2 and truncated.
Example
Input is SPSP :

selection = ""
output = "SPSP"
 SPSP
↑
selection = "SPSP"
output = "SPSP"
 SPSP
 ↑
selection = "SPSP"
output = "SPSPSPSP"
 SPSP
  ↑
selection = "SPSPSPSP"
output = "SPSPSPSP"
 SPSP
   ↑
selection = "SPSPSPSP"
output = "SPSPSPSPSPSPSPSP"
 SPSP
    ↑
Final Output is SPSPSPSPSPSPSPSP

Test Cases
"" -> ""
"S" -> "S"
"P" -> "P"
"PS" -> "PS"
"SP" -> "SSPP"
"SPP" -> "SSPSPPPPP"
"SPSP" -> "SPSPSPSPSPSPSPSP"
"SPPSP" -> "SPSPPSPSPSPPSPPSPSPPSPPSPSPPSP"
"SPPSPSSS" -> "SPPSSPPSSPPSSPPSSPPSSPPSPSSSPSSSPSSSPSSSPSSSPSSS"
Reference Implementation
In Python 3 :

def clipboard(inp, select="S", paste="P"):
    out = inp
    primary_selection = ""
    for instruction in inp:
        if instruction is select:
            primary_selection = out
        if instruction is paste:
            out = out[:len(out)//2] + primary_selection + out[len(out)//2:]
    return out
Try it online!

Rules
You may assume that the input contains only the "paste" or "select" characters (you don't need to handle error cases)
You may take your input newline separated (e.g S\n P\n S\n)
You may use any kind of data representation (e.g binary data,\n(newline) as a select character and  (space) as a paste character, etc.)
Standard code-golf rules , shortest submission by bytes wins!

*/

package main

func main() {
	assert(clipboard("") == "")
	assert(clipboard("S") == "S")
	assert(clipboard("P") == "P")
	assert(clipboard("PS") == "PS")
	assert(clipboard("SP") == "SSPP")
	assert(clipboard("SPP") == "SSPSPPPPP")
	assert(clipboard("SPSP") == "SPSPSPSPSPSPSPSP")
	assert(clipboard("SPPSP") == "SPSPPSPSPSPPSPPSPSPPSPPSPSPPSP")
	assert(clipboard("SPPSPSSS") == "SPPSSPPSSPPSSPPSSPPSSPPSPSSSPSSSPSSSPSSSPSSSPSSS")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func clipboard(s string) string {
	t := s
	p := ""
	for _, r := range s {
		switch r {
		case 'S':
			p = t
		case 'P':
			t = t[:len(t)/2] + p + t[len(t)/2:]
		}
	}
	return t
}
