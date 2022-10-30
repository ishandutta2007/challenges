#!/usr/bin/env python

"""

As programmers, we all know the saying: "You can have it fast and good, but it won't be cheap, you can have it cheap and good, but it won't be fast, or you can have it fast and cheap, but it won't be good."

For this challenge, you are implementing an imaginary configuration tool for your custom programming services. You should render a set of three check boxes, with a heading of "SELECT ANY TWO":

SELECT ANY TWO
☐ FAST
☐ CHEAP
☐ GOOD
Once two items have been selected, the third item must be disabled. Upon deselecting one of the two selected items, all options must again be enabled.
Put another way, if zero or one items are selected, all are still enabled, but if two items are selected, the third must be disabled.

No special controls allowed. The check boxes should be the standard check box in your language of choice. For example, don't use a "CheckBoxList" control, if your language has one.
I'm imagining most entries will be HTML/jQuery, but that is not a rule. This is code golf, looking for the shortest entry.

"""

import tkinter as tk

class Option:
    def __init__(self, window, text, handler):
        self.text = text
        self.value = tk.IntVar()
        self.check = tk.Checkbutton(window, text=self.text, variable=self.value, onvalue=1, offvalue=0, command=handler)
        self.check.pack()

    def toggle(self, state):
        self.check.config(state=state)

def main():
    def selection():
        c = 0
        v = None
        for p in options:
            if p.value.get() == 1:
                c += 1
            else:
                v = p

        if c < 2:
            for p in options:
                p.toggle(tk.NORMAL)
        elif c >= 2:
            v.toggle(tk.DISABLED)

    window = tk.Tk()
    window.title("POISON PICKING")
    window.geometry("256x100")

    label = tk.Label(window, bg="white", width=50, text="MAKE A SELECTION")
    label.pack()
    
    options = [
        Option(window, "FAST", selection),
        Option(window, "CHEAP", selection),
        Option(window, "GOOD", selection)
    ]
    
    window.mainloop()

main()
