/*

Write the shortest code that raises a Segmentation Fault (SIGSEGV) in any programming language.

*/

#include <signal.h>

int
main(void)
{
	raise(SIGSEGV);
	return 0;
}
