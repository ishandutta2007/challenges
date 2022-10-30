{-

Task
This one is simple. We want to compress a URL, but don't trust URL shorteners.

Write a program that prints to stdout (or a 0-argument function that returns) the following, working URL:

http://a.b.c.d.e.f.g.h.i.j.k.l.m.n.oo.pp.qqq.rrrr.ssssss.tttttttt.uuuuuuuuuuu.vvvvvvvvvvvvvvv.wwwwwwwwwwwwwwwwwwwwww.xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx.yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy.zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz.me

Code golf, standard rules.

You may output uppercase or lowercase.

Leading or trailing whitespace is ok.

Context
Explanation taken from the website:

The domain is created to reach the maximum number of allowed characters (255 (really 253)) with an exponential curve in the length of the letters as you proceed through the alphabet.
The formula used is "1 + 62 * (10/7)^(x-26)". To help illustrate this curve, reference the distribution on this spreadsheet. It's colorful because I like colors and wanted to do a progressive "rainbow" animation in CSS3.

-}

main = putStrLn "http://a.b.c.d.e.f.g.h.i.j.k.l.m.n.oo.pp.qqq.rrrr.ssssss.tttttttt.uuuuuuuuuuu.vvvvvvvvvvvvvvv.wwwwwwwwwwwwwwwwwwwwww.xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx.yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy.zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz.me"
