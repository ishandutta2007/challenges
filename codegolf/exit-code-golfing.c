/*

The Task
Write a program that, given an input integer x between 0 and 255, crashes with exit code x.

Restrictions
You may not call anything which is intended directly for exit code output (System.exit(x), returning from main, etc.). Instead, your program must cause an error or crash which will cause, with a probability of 1, the program to exit with the input integer.
In this case, the words "error" and "crash" means that the program caused some fatal unintended exception, wherein a method, operation or otherwise was used incorrectly that caused an irreversible failure.
You may not directly cause the error by throwing it directly. You must cause it by using a method, function, or otherwise whose purpose serves a different function (i.e. attempting to execute a file write to a read-only directory).
You must have at least two exit codes accounted for in your program.
Termination of the process with the use of signals is banned. (Reasoning may be found in this discussion)

Scoring
Your program's score is determined by the number of supported exit codes, where code concision is tiebreaker. The greatest number of supported exit codes wins!

*/

#include <stdlib.h>

int
main(int argc, char *argv[])
{
	if (argc < 2)
		return 0;
	return atoi(argv[1]);
}
