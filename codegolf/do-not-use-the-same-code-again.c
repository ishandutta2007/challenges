/*

I want to give a task. The main rule is not to use the same code again, it means no loops, no jumps, no goto, no recursion, if you declare procedure it can be called only once and etc. Also if you call some standard function it should meet the requirements inside.

The main point of this task is to write the shorter code which prints the longest output.

NOTE: printing functions, for example printf probably do not meat requirements but it is allowed to use this kind of functions.

EDIT: after reading some comments I have to tell that output needs to be longer then input. Also you cannot use the same function twice because it means you are using the same code, sorry for not very clear requirements.


*/

#include <stdio.h>

#define F1 printf("%d\n", __COUNTER__);
#define F2 F1 F1 F1 F1 F1 F1 F1 F1 F1 F1 F1
#define F3 F2 F2 F2 F2 F2 F2 F2 F2 F2 F2 F2
#define F4 F3 F3 F3 F3 F3 F3 F3 F3 F3 F3 F3
#define F5 F4 F4 F4 F4 F4 F4 F4 F4 F4 F4 F4
#define F6 F5 F5 F5 F5 F5 F5 F5 F5 F5 F5 F5
#define F7 F6 F6 F6 F6 F6 F6 F6 F6 F6 F6 F6
#define F8 F7 F7 F7 F7 F7 F7 F7 F7 F7 F7 F7

int
main(void)
{
	F8;
	return 0;
}
