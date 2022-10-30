/*

Today's Daily WTF quotes the following line of code...

FailSafe==0?'No technical alarms':((FailSafe&1)!=0&&(FailSafe&2)!=0&&(FailSafe&4)!=0&&(FailSafe&8)!=0?'Detection zones staying in a given state; Bad visibility;
Initialization; Bad configuration':((FailSafe&1)!=0&&(FailSafe&2)!=0&&(FailSafe&4)!=0?'Detection zones staying in a given state; Bad visibility; Initialization':
((FailSafe&1)!=0&&(FailSafe&2)!=0&&(FailSafe&8)!=0?'Detection zones staying in a given state; Bad visibility; Bad configuration':((FailSafe&1)!=0&&(FailSafe&4)!=0&&
(FailSafe&8)!=0?'Detection zones staying in a given state; Initialization; Bad configuration':((FailSafe&2)!=0&&(FailSafe&4)!=0&&(FailSafe&8)!=0?'Bad visibility;
Initialization; Bad configuration':((FailSafe&1)!=0&&(FailSafe&2)!=0?'Detection zones staying in a given state; Bad visibility':((FailSafe&1)!=0&&(FailSafe&4)!=0?'Detection
zones staying in a given state; Initialization':((FailSafe&1)!=0&&(FailSafe&8)!=0?'Detection zones staying in a given state; Bad configuration':((FailSafe&2)!=0&&
(FailSafe&4)!=0?'Bad visibility; Initialization':((FailSafe&2)!=0&&(FailSafe&8)!=0?'Bad visibility; Bad configuration':((FailSafe&4)!=0&&(FailSafe&8)!=0?'Initialization; Bad
configuration':((FailSafe&1)!=0?'Detection zones staying in a given state':((FailSafe&2)!=0?'Bad visibility':((FailSafe&4)!=0?'Initialization':((FailSafe&8)!=0?'Bad
configuration':'Unknown')))))))))))))))
Write some code that takes an integer value named FailSafe and returns the same string that the above code would produce from the same integer value.

The challenge is to rewrite that line, so "boilerplate" code is free, including any code that loads an integer value and outputs the string. Only the code that performs the above transformation from an integer to a string counts.
You may use a different name to "FailSafe" if you wish, as long as your chosen identifier has the same golf score.
No calling external resources to perform the lookup.
Normal code-golf rules apply.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

const char *
wtf(int FailSafe)
{
	return FailSafe == 0
	           ? "No technical alarms"
	           : ((FailSafe & 1) != 0 && (FailSafe & 2) != 0 && (FailSafe & 4) != 0 && (FailSafe & 8) != 0
	                  ? "Detection zones staying in a given state; Bad visibility; Initialization; Bad configuration"
	                  : ((FailSafe & 1) != 0 && (FailSafe & 2) != 0 && (FailSafe & 4) != 0
	                         ? "Detection zones staying in a given state; Bad visibility; Initialization"
	                         : ((FailSafe & 1) != 0 && (FailSafe & 2) != 0 && (FailSafe & 8) != 0
	                                ? "Detection zones staying in a given state; Bad visibility; Bad configuration"
	                                : ((FailSafe & 1) != 0 && (FailSafe & 4) != 0 && (FailSafe & 8) != 0
	                                       ? "Detection zones staying in a given state; Initialization; Bad configuration"
	                                       : ((FailSafe & 2) != 0 && (FailSafe & 4) != 0 && (FailSafe & 8) != 0
	                                              ? "Bad visibility; Initialization; Bad configuration"
	                                              : ((FailSafe & 1) != 0 && (FailSafe & 2) != 0
	                                                     ? "Detection zones staying in a given state; Bad visibility"
	                                                     : ((FailSafe & 1) != 0 && (FailSafe & 4) != 0
	                                                            ? "Detection zones staying in a given state; Initialization"
	                                                            : ((FailSafe & 1) != 0 && (FailSafe & 8) != 0
	                                                                   ? "Detection zones staying in a given state; Bad configuration"
	                                                                   : ((FailSafe & 2) != 0 && (FailSafe & 4) != 0
	                                                                          ? "Bad visibility; Initialization"
	                                                                          : ((FailSafe & 2) != 0 && (FailSafe & 8) != 0
	                                                                                 ? "Bad visibility; Bad configuration"
	                                                                                 : ((FailSafe & 4) != 0 && (FailSafe & 8) != 0
	                                                                                        ? "Initialization; Bad configuration"
	                                                                                        : ((FailSafe & 1) != 0
	                                                                                               ? "Detection zones staying in a given state"
	                                                                                               : ((FailSafe & 2) != 0 ? "Bad visibility"
	                                                                                                                      : ((FailSafe & 4) != 0
	                                                                                                                             ? "Initialization"
	                                                                                                                             : ((FailSafe & 8) != 0
	                                                                                                                                    ? "Bad configuration"
	                                                                                                                                    : "Unknown")))))))))))))));
}

const char *
wtfremix(int state)
{
	static const char *strings[] = {
	    "Detection zones staying in a given state",
	    "Bad visibility",
	    "Initialization",
	    "Bad configuration",
	};

	static char buf[256];

	size_t i;
	int len;

	if (state == 0)
		return strcpy(buf, "No technical alarms");

	len = 0;
	for (i = 0; i < nelem(strings); i++) {
		if (state & (1 << i)) {
			if (len)
				len += sprintf(buf + len, "; ");

			len += sprintf(buf + len, "%s", strings[i]);
		}
	}
	if (!len)
		strcpy(buf, "Unknown");

	return buf;
}

int
main(void)
{
	int i;

	for (i = 0; i <= 10000; i++)
		assert(!strcmp(wtf(i), wtfremix(i)));

	return 0;
}
