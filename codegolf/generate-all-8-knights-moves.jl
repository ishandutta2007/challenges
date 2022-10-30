#!/usr/bin/env julia

#=

Introduction

In chess, Knights can move two squares in one direction, and then one square in an orthogonal direction. On an x/y plane, these can be thought of as being a relative change of coordinates, such as (+1, -2).

Challenge

Your task is to output all 8 possible moves as pairs of relative x/y coordinates, in any order.

You may output in any reasonable format. To decrease reliance on printing random separators, using the same separators for everything is fine, and no separators are also fine. Standard loopholes apply.

Example Outputs:

1,2 1,-2 -1,-2 -1,2 2,1 2,-1 -2,-1 -2,1

2-112-2-1-211-2-1-2-1221

1;2
-1;2
2;1
2;-1
-2;-1
1;-2
-1;-2
-2;1
This is code golf, so fewest bytes wins.

=#

function knight_moves()
	return [[1, 2], [1, -2], [-1, -2], [-1, 2], [2, 1], [2, -1], [-2, -1], [-2, 1]]
end

println(knight_moves())
