/*

Inspired by We had a unit test once which only failed on Sundays, write a program or function that does nothing but throw an error when it is Sunday, and exit gracefully on any other day.
Rules:

    No using input or showing output through the usual IO methods, except to print to STDERR or your language's equivalent. You are allowed to print to STDOUT if it's a by-product of your error.
    A function may return a value on non-Sundays as long as it doesn't print anything
    Your program may use a Sunday from any timezone, or the local timezone, as long as it is consistent.
    An error is a something that makes the program terminate abnormally, such as a divide by zero error or using an uninitialised variable. This means that if any code were to be added after the part that errors, it would not be executed on Sunday.
    You can also use statements that manually create an error, equivalent to Python’s raise.
    This includes runtime errors, syntax errors and errors while compiling (good luck with that!)
    On an error there must be some sign that distinguishes it from having no error
    This is code-golf, so the shortest bytecount in each language wins!

I'll have to wait til Sunday to check the answers ;)

*/

package main

import "time"

func main() {
	t := time.Now()
	if t.Weekday() == time.Sunday {
		panic("God rests on Sunday!")
	}
}
