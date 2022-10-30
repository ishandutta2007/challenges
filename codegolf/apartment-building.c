/*

Draw an "apartment" building according to the specifications below.

Basic Rules
Take, as input, the number of floors of the building. Return a building with that many floors meeting the following specifications:

The building will be eight characters wide, with eight underscore characters (_) on top and eight dashes (-) on the bottom.

The first floor of the building will always look like this: |  ||  |.

As long as the building has more than one floor, the top floor will always look like this: | ---- |

All floors in between must be randomly selected between the following:

| -  - |

|  []  |

|__  __|

Example Outputs:
5 floors:

________
| ---- |
|  []  |
| -  - |
|__  __|
|  ||  |
--------
2 floors:

________
| ---- |
|  ||  |
--------
1 floor:

________
|  ||  |
--------
Specific rules

Your inputted number of floors will, at minimum, be 1.

You may output as a string, a list of strings, a nested list of characters, or any other output format in which the position of each element is clear.

All floor types must have a nonzero chance of appearing at any given level (other than the bottom and the top), but they do not have to be uniformly randomly chosen.

Code-golf, so shortest code wins.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void
building(int n)
{
	static const char *floor[] = {
	    "________",
	    "| ---- |",
	    "| -  - |",
	    "|  []  |",
	    "|__  __|",
	    "|  ||  |",
	    "--------",
	};
	int i;

	printf("n=%d\n", n);
	printf("%s\n", floor[0]);
	for (i = n; i >= 1; --i) {
		if (i == 1)
			printf("%s\n", floor[5]);
		else if (i == n)
			printf("%s\n", floor[1]);
		else
			printf("%s\n", floor[2 + (rand() % 3)]);
	}
	printf("%s\n", floor[6]);
	printf("\n");
}

int
main(void)
{
	srand(time(NULL));
	building(1);
	building(2);
	building(5);
	building(100);

	return 0;
}
