--[[

Maya is a bee that likes to help her friends.
Willy is a drone bee and Maya’s best friend.
He has just discovered that he has no father, and he is worried about that.
Maya knows that female bees have two parents (one father and one mother), but male or drone bees have a mother but no father.
This is because if an egg is laid by an unmated female, it hatches a drone bee, but if, instead, an egg was fertilized by a male, it hatches a female.
After Maya talks with Willy about this, he begins to think about the number of ancestors that he has. He has one mother.
He also has two grandparents (one grandmother and one grandfather). And he has three great-grandparents.
Since Willy is very lazy, he doesn’t want to perform more calculations and he is asking you to write a program that, given a number of generation,
determines how many of Willy’s ancestors belong to that generation, under the assumption that the ancestors at each level are unrelated.

Input

Your program receives a sequence of positive integers, one per line, each representing the generation.
The maximum value for the generation is 80. The input terminates with a ‘0’.

Output

For each input case, your program must print the corresponding number of ancestors that Willy has in
such generation.

Sample Input
1
2
3
0

Sample Output
1
2
3

--]]

function ancestors(n)
	a, b = 1, 1
	for i=1,n do
		a, b = b, a + b
	end
	return a
end

assert(ancestors(1) == 1)
assert(ancestors(2) == 2)
assert(ancestors(3) == 3)

for i=1,80 do
	print(i, ancestors(i))
end
