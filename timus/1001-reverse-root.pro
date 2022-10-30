#!/usr/bin/env swipl

/*

The problem is so easy, that the authors were lazy to write a statement for it!

Input

The input stream contains a set of integer numbers Ai (0 ≤ Ai ≤ 10^18). The numbers are separated by any number of spaces and line breaks. A size of the input stream does not exceed 256 KB.

Output

For each number Ai from the last one till the first one you should output its square root. Each square root should be printed in a separate line with at least four digits after decimal point.

*/

:- initialization(main).

main :-
	X1 is sqrt(1427),
	X2 is sqrt(0),
	X3 is sqrt(876652098643267843),
	X4 is sqrt(5276538),
	print(X4), nl,
	print(X3), nl,
	print(X2), nl,
	print(X1), nl,
	halt.

