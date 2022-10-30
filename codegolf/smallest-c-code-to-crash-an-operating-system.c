/*

A shortest C program, that can crash the Operating system, either on a Windows or a Linux PC...

Rules:

    The code is to be developed in C language, but it may use other api, specific to linux or windows systems.
    The Operating System is said to have been put out of commission, if either it has come to a state[Standstill or otherwise] , where no matter how much time passes, the system is rendered inoperable or (even better), self restarts itself, or something similar to a blue screen of death.
    To be most effective, the program will be run as a normal user and not as superuser or an administrator.
    For every valid program that is able to crash the PC, countermeasures can be suggested by others in the comments, successful measures that can nullify the effect of the program gets the answer invalidated. For Example - If an answer suggests use of fork Bombs, i would suggest measures like this in the comments.
    Since Linux OS is considered more stable, a program that crashes linux is always a better one, even if it takes extra code than it takes to crash windows, but still the smallest program to crash the OS wins, independent of the platform.
    The community is free to edit the question to add more sensible rules, provided the new rules maintain compatibility with existing answers.

Note: This above question is asked with the purpose of demonstrating the raw power of C[or the lack of it] as a low level/mid level language. Also hopefully, to become more aware of OS security, and possible measures that can be taken.

EDIT:

A similar question lies here Code Golf of Death...

But here are the reasons my question differs from the above mentioned one...

    I am looking for the answers to only be in C language.
    Though the above question has one answer in C, the code works only for a rare version of pentium 5. So in short there is no C language based answer in the above question to achieve the end purpose.
    In the other question Kernel-mode drivers are allowed, but my question concentrates mainly on user space processes.
    Some of the answers in the above question allow the programs to run in supervisor/administrator mode, but such privileged execution of the program is not allowed in the rules stated by my question.
    In the similar question the answer with highest upvotes win, in my question answer which crashes the OS , using the shortest code, and does so without any suggestion of countermeasure to be taken against the method employed by the answer.
    In short, apart from the same intention of crashing the OS , the two questions differ in every other aspect.

*/

#include <unistd.h>

void
forkbomb(void)
{
	for (;;)
		fork();
}

int
main(void)
{
	forkbomb();
	return 0;
}
