#!/usr/bin/env lua

TEXT= 
[[
The basic idea of a [tag:kolmogorov-complexity] challenge is to print a set output in the shortest code (though that meaning has changed now). We have had many of them, from [Borromean Rings](http://codegolf.stackexchange.com/questions/53417/ascii-borromean-rings) to [The Gettysburg Address](http://codegolf.stackexchange.com/questions/15395/how-random-is-the-gettysburg-address).

##Your Task

This question is similar, except that it requires printing of a special text - the text of this question. Specifically, the very Markdown code that I am typing right now.

To prevent an infinite recursion in the question, the exact text you have to print can be found [here](http://codegolf.stackexchange.com/revisions/1f731ea3-0950-4b03-ae95-24fa812a9a28/view-source).

##Clarifications

- You are not allowed to use any external sources like the internet.
- This means that the purpose of this question is not to download this question text and parse it, but instead to store it in you program.
- This is [tag:code-golf], so shortest code in **bytes** wins!
]]

print(TEXT)
