#!/usr/bin/env julia

#=

Chef, the event manager of his college . He has been assigned to count the total number of teams taking part in a particular contest.
A team consists of two students . Chef decides to do a lottery for team formation.
Each student has to choose a ticket from the collection of tickets given and two students with matching ticket numbers can make a pair for a team .

Given N number of tickets and an array A[ ] of size N with ticket numbers.

Chef is busy handling other activities for the events so he needs your help.
You have to count the total number of teams.

Note:- Each and every student can make a pair only once.

Input:

First line will contain T, number of testcases. Then the testcases follow.
First line of each testcase contains of a single line of input, an integer N.
Second line of each testcase contains N integers A[0],A[1],...,A[N−1] separated by a single space.

Output:

For each testcase, print the total number of teams in a single line answer.

Constraints
1≤T≤100
1≤N≤100
0≤A[i]≤100

=#

function teams(a)
	a = sort(a)
	
	r = 0
	i = 1
	while i < length(a)
		if a[i] == a[i+1]
			r += 1
			i += 1
		end
		i += 1
	end
	
	return r
end

@assert(teams([21, 13, 17, 13]) == 1)
@assert(teams([5, 11, 7, 5, 5, 11, 9]) == 2)
@assert(teams([2, 2, 17, 2, 19, 23, 52, 37, 23, 37, 23, 10, 23]) == 4)

