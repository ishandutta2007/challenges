/*

Warning: This challenge is only valid for languages with a compiler.

Make a program (which is perfectly valid code) that outputs Hello, World, even before runtime.

How? Let me explain.

Many languages have a compiler. Some operations are made in the compile-time, and others, in runtime. You trick the compiler to output the text Hello, World in compile-time.
The text can be anywhere, like the build log.(Not errors. sorry for invalidating all those answers. at least theres pragma tho)

You can use C, C++ or C#, but I wouldn't encourage you to. It's simply a game breaker.

p.s. I wrote this challenge because the tag compile-time is both unused, and used wrong.

*/

#pragma message("Hello, World!")

int
main(void)
{
	return 0;
}
