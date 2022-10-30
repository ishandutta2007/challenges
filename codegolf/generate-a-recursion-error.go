/*

Write the shortest possible code cause an error due to recursion too deep

Example error in python

RecursionError: maximum recursion depth exceeded

Example error in c

Segmentation fault

My Python version (15 bytes):

def f():f()
f()

*/

package main

func main() {
	main()
}
