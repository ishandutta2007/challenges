/*

My colleague recently sent me the following piece of JavaScript as a joke:

let butScript = (nrOfButs) => {
    for(var i = 0; i < nrOfButs; i++){
        if(i % 3 == 0){
            console.log("Yeah")
        }
        if(i % 2 == 0){
            console.log("But")
        }
        if(i % 3 == 1){
            console.log("No")
        }
    }
}

Since the code was written during work hours, it was obviously a huge waste of company resources.
To prevent similar occurrences in the future, we must minimize the waste of worked hours.
And since it is common knowledge that a shorter program is faster to write, we must golf this code to be as short as possible!

Input
A single non-negative integer. You must not handle faulty input.

Output
Your program must produce output identical to that of the script above. You should output one word per line, and the number of words should be consistent with the original script.

It is permissible to include non-newline whitespace characters at the end of each line (but not at the beginning) since they are invisible. One additional newline character is permissible at the very end of the output.

Examples
Input: 0
Output:


Input: 1
Output:
Yeah
But

Input: 2
Output:
Yeah
But
No

Input: 10
Output:
Yeah
But
No
But
Yeah
But
No
Yeah
But
No
But
Yeah

*/

#include <stdio.h>

void
butscript(int n)
{
	int i;

	for (i = 0; i < n; i++) {
		if (i % 3 == 0)
			printf("Yeah\n");
		if (i % 2 == 0)
			printf("But\n");
		if (i % 3 == 1)
			printf("No\n");
	}
	printf("\n");
}

int
main(void)
{
	butscript(0);
	butscript(1);
	butscript(2);
	butscript(10);

	return 0;
}
