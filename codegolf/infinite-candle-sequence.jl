#!/usr/bin/env julia

#=

I have a cake shop that specialises in birthday cakes. The cakes that I sell must have candles placed in a circle.
You would probably think I can just divide 360° by the number of candles, but the machine for placing candles is quite unique; it uses a list of numbers representing positions of candles, placing them one-by-one until it reaches the desired amount.
Furthermore, it can only store numbers as a binary fraction of turns, ie. n/2^m where {n,m∈Z0+|n<m}.

Since I want the candles placed as evenly as possible, I've devised a method for working out where to place each candle.

The first candle goes at position 0.
In order to balance the cake, the next goes at 1/2.
The next two candles go in the remaining gaps, so 1/4, 3/4.
The next four use the sequence so far to define the order. So 1/8, 5/8, 3/8, 7/8.
Ad infinitum.

To put it more generally:

f(0)f(n)=0=f(n−2^⌊log2(n)⌋)+2^−⌊log2(n)⌋−1

Create for me a program or function to create this sequence.

My machine has a small hard drive (I mean really small), so the code should be as short as possible.

Output

The output should follow standard sequence output. That is, either output the entire sequence (print them one by one or return a list or generator representing the sequence), or given an index n (0 or 1 indexed) return the nth entry or every entry up to the nth.

The entries can be either represented as a simplified fraction (numerator and denominator separated by /) or decimal (rounding errors are acceptable).

The first 64 terms as fractions are

0
1/2
1/4
3/4
1/8
5/8
3/8
7/8
1/16
9/16
5/16
13/16
3/16
11/16
7/16
15/16
1/32
17/32
9/32
25/32
5/32
21/32
13/32
29/32
3/32
19/32
11/32
27/32
7/32
23/32
15/32
31/32
1/64
33/64
17/64
49/64
9/64
41/64
25/64
57/64
5/64
37/64
21/64
53/64
13/64
45/64
29/64
61/64
3/64
35/64
19/64
51/64
11/64
43/64
27/64
59/64
7/64
39/64
23/64
55/64
15/64
47/64
31/64
63/64
and as decimal

0
0.5
0.25
0.75
0.125
0.625
0.375
0.875
0.0625
0.5625
0.3125
0.8125
0.1875
0.6875
0.4375
0.9375
0.03125
0.53125
0.28125
0.78125
0.15625
0.65625
0.40625
0.90625
0.09375
0.59375
0.34375
0.84375
0.21875
0.71875
0.46875
0.96875
0.015625
0.515625
0.265625
0.765625
0.140625
0.640625
0.390625
0.890625
0.078125
0.578125
0.328125
0.828125
0.203125
0.703125
0.453125
0.953125
0.046875
0.546875
0.296875
0.796875
0.171875
0.671875
0.421875
0.921875
0.109375
0.609375
0.359375
0.859375
0.234375
0.734375
0.484375
0.984375

=#

function f(n)
	if n <= 0
		return 0
	end
	m = BigInt(floor(log2(n)))
	return f(n - 2^m) + 1//2^(m+1)
end

for n in 0:63
	println(f(n))
end
