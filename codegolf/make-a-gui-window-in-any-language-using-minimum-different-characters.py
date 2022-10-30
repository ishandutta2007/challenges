#!/usr/bin/env python

"""

I want you to make a gui window like this:

Small window containing the text "Hello, World" and a "quit" button

* if you're thinking, the [quit] button closes the window

in any language using minimum "different" characters.. AND remember that the gui window must use native widgets instead of custom icons and buttons

like I have Windows 8, so my GUI window looks like this:

Small window containing the text "Hello, World" and a "quit" button
If you didn't understand what i mean by 'minimum "different characters"'..

I meant, like this hello world code:

print("Hello, World!")

has these characters:

()",! HWdeilnoprt

total 17 different characters..

likewise, make a gui window with native widgets of your OS in any language using least "different" characters..

The same gui window in python (tkinter used here) will be:

import tkinter as tk
from tkinter import ttk
root = tk.Tk()
label = tk.Label(root,text='Hello, World')
label.pack()
button = ttk.Button(root,text='quit', command= root.quit)
button.pack()
root.mainloop()

with a total of 32 different characters

NOTE: case-sensative (A != a), all characters like "\n", "\t", "\b", " ", etc. are counted..

use any language... python, java, js, css, html, ts, brainfk, ada, lua, blah.. blah.. blah..

"""

import tkinter as tk
from tkinter import ttk

def main():
    root = tk.Tk()
    root.title("Enterprise World")
    root.geometry("256x64")
    label = tk.Label(root,text='Hello, World!')
    label.pack()
    button = ttk.Button(root, text='Quit', command=root.quit)
    button.pack()
    root.mainloop()

main()
