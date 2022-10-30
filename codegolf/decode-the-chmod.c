/*

Challenge

Given a three digit octal permissions number, output the permissions that it grants.

chmod

On UNIX OSes file permissions are changed using the chmod command. There are few different ways of using chmod, but the one we will focus on today is using octal permissions.

The three digits in the permissions number represent a different person:

The first digit represents the permissions for the user
The second digit represents the permissions for the group
The last digit represents the permissions for others
Next, each digit represents a permission as shown below in:

Key: number | permission

7 | Read Write and Execute
6 | Read and Write
5 | Read and Execute
4 | Read only
3 | Write and Execute
2 | Write only
1 | Execute only
0 | None

Input

The input will be the three digit number as a string, e.g.:

133
or

007
This will be passed either via STDIN or via function arguments.

Output
Your output should be the different permissions for each of the user, the group and the others. You must display this information like so:

User:   ddd
Group:  ddd
Others: ddd
Where there are three spaces after User, two spaces after Group and one space after Others. You replace ddd with the permissions information.

Your output may be to STDOUT or as a returned string.

Examples
Input: 666

Output:

User:   Read and Write
Group:  Read and Write
Others: Read and Write
Input: 042

Output:

User:   None
Group:  Read only
Others: Write only
Input: 644

Output:

User:   Read and Write
Group:  Read only
Others: Read only
Winning
The shortest code in bytes wins.

*/

#include <stdio.h>

const char *
permission(int m)
{
	static const char *tab[] = {
	    "None",
	    "Execute only",
	    "Write only",
	    "Write and Execute",
	    "Read only",
	    "Read and Execute",
	    "Read and Write",
	    "Read Write and Execute",
	};

	return tab[m & 7];
}

void
decode(int m)
{
	printf("User:   %s\n", permission(m >> 6));
	printf("Group:  %s\n", permission(m >> 3));
	printf("Others: %s\n", permission(m));
	printf("\n");
}

int
main(void)
{
	decode(0666);
	decode(0042);
	decode(0644);

	return 0;
}
