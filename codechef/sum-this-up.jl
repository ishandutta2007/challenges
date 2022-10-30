#!/usr/bin/env julia

#=

You are given an array A with N positive elements A1,A2,…,AN. You are also given a function S on any array C with length N defined as follow:

S(C) = ∑[i, 1, N] ((Ci−1+Ci+1)/2−Ci)
Note that conventionally, we define all elements outside the range of the array to have value 0. In this context, C0=CN+1=0.

Consider the following process:

Choose a permutation P of values from 1 to N uniformly randomly.
Let B be the array of N elements B1,B2,…,BN, where Bi=APi.
Define V as the expected value of |S(B)|. Find ⌊V⌋.

Note :

|X| denotes absolute value of X
⌊X⌋ is the greatest integer that does not exceed X.

Input Format

The first line of the input contains an integer T - the number of test cases. The test cases then follow.
The first line of each test case contains an integer N - the size of array.
The second line of each test case contains N integers A1,A2,…,AN - the elements of the array.

Output Format

For each testcase, output ⌊V⌋ in a new line.

Constraints
1≤T≤10
1≤N≤2⋅10^5
1≤Ai≤2⋅10^5

=#

using Statistics

@assert(mean([1, 1]) == 1)
@assert(mean([8, 2, 2]) == 4)
