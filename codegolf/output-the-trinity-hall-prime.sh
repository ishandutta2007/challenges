#!/bin/sh

cat << EOF >/dev/null

Based on this Math.SE question; number copied from this answer. Number originally from a Numberphile video, of course.

Your task is to output the following 1350-digit prime number:

888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888111111111111111111111111888888111111111111111111111111888888111111811111111118111111888888111118811111111118811111888888111188811111111118881111888888111188811111111118881111888888111888811111111118888111888888111888881111111188888111888888111888888111111888888111888888111888888888888888888111888888111888888888888888888111888888111888888888888888888111888888811188888888888888881118888188811188888888888888881118881188881118888888888888811188881118888111888888888888111888811111888811118888888811118888111111188881111111111111188881111111118888111111111111888811111111111888811111111118888111111111111188881111111188881111111111111118888811118888811111111111111111888881188888111111111111111111118888888811111111111111111111111888888111111111111111111111111118811111111111111111111111111111111111111111111062100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001
You may optionally include newlines in the output.

Rules
This is kolmogorov-complexity, so no input.
Your program must terminate within one hour on a standard computer - if it is close, I will use mine for testing. If your program runs for more than minute, or does not terminate on TIO, please include the time on your computer.
This is code-golf, so shortest code, in bytes, wins.

EOF

# https://math.stackexchange.com/questions/2420488/what-is-trinity-hall-prime-number/
cat << EOF
888888888888888888888888888888
888888888888888888888888888888
888888888888888888888888888888
888111111111111111111111111888
888111111111111111111111111888
888111111811111111118111111888
888111118811111111118811111888
888111188811111111118881111888
888111188811111111118881111888
888111888811111111118888111888
888111888881111111188888111888
888111888888111111888888111888
888111888888888888888888111888
888111888888888888888888111888
888111888888888888888888111888
888811188888888888888881118888
188811188888888888888881118881
188881118888888888888811188881
118888111888888888888111888811
111888811118888888811118888111
111188881111111111111188881111
111118888111111111111888811111
111111888811111111118888111111
111111188881111111188881111111
111111118888811118888811111111
111111111888881188888111111111
111111111118888888811111111111
111111111111888888111111111111
111111111111118811111111111111
111111111111111111111111111111
062100000000000000000000000000
000000000000000000000000000000
000000000000000000000000000000
000000000000000000000000000000
000000000000000000000000000000
000000000000000000000000000000
000000000000000000000000000000
000000000000000000000000000000
000000000000000000000000000000
000000000000000000000000000000
000000000000000000000000000000
000000000000000000000000000000
000000000000000000000000000000
000000000000000000000000000000
000000000000000000000000000001
EOF