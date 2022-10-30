/*

The Challenge

Your goal is to write the shortest program possible that will take a list of events (such as upvote, downvote, etc) and return the user's reputation and the privileges that he has earned.
What sort of events?

Here is a chart of the events, listed in order of reputation earned:

-15 answer unaccepted
-10 answer unupvoted
-5  question unupvoted
-2  answer downvoted
-2  question downvoted
-2  unaccept answer
-1  downvote answer
+1  join website
+1  undownvote answer
+2  accept answer
+2  question undownvoted
+2  answer undownvoted
+5  question upvoted
+10 answer upvoted
+15 answer accepted
+100 association bonus

What sort of privileges?

Here is a list of privileges, in order of reputation required.

1 create posts
5 participate in meta
10 remove new user restrictions
10 create wiki posts
15 vote up
15 flag posts
20 talk in chat
50 comment everywhere
75 set bounties
100 edit community wiki
100 create chat rooms
125 vote down
150 create tags
200 retag questions
250 view close votes
500 cast close and reopen votes
750 established user
1000 edit questions and answers
1000 create gallery chat rooms
1250 create tag synonyms
1500 approve tag wiki edits
2000 access to moderator tools
3500 protect questions
4000 trusted user

Input

Input (on STDIN) will be a list of events, one per line, exactly how they appear in the first chart (except for the amount of reputation). A blank line represents the end of input. Here is an example (there should be a blank line at the end):

join website
association bonus
answer upvoted
answer upvoted
question upvoted
answer accepted
answer upvoted
accept answer
unaccept answer
question unupvoted
accept answer
question upvoted

Output

The first line of output (to STDOUT) should name the amount of rep accumulated. Each line after that should list one privilege earned, exactly as they appear and in the same order as the second chart. The expected output for the above input:

153 reputation
1 create posts
5 participate in meta
10 remove new user restrictions
10 create wiki posts
15 vote up
15 flag posts
20 talk in chat
50 comment everywhere
75 set bounties
100 edit community wiki
100 create chat rooms
125 vote down
150 create tags

Rules, Restrictions, and Notes

This is code golf. Standard code golf rules apply.

(EDIT: Since I have had two entries that access files, I would like to point out that the length of the file needs to be added to code length as part of the standard rules for code golf)

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef struct {
	int value;
	char description[32];
} Sitrep;

void
rank(const char **s, size_t n)
{
	static const Sitrep events[] = {
	    {-15, "answer unaccepted"},
	    {-10, "answer unupvoted"},
	    {-5, "question unupvoted"},
	    {-2, "answer downvoted"},
	    {-2, "question downvoted"},
	    {-2, "unaccept answer"},
	    {-1, "downvote answer"},
	    {+1, "join website"},
	    {+1, "undownvote answer"},
	    {+2, "accept answer"},
	    {+2, "question undownvoted"},
	    {+2, "answer undownvoted"},
	    {+5, "question upvoted"},
	    {+10, "answer upvoted"},
	    {+15, "answer accepted"},
	    {+100, "association bonus"},
	};

	static const Sitrep privileges[] = {
	    {1, "create posts"},
	    {5, "participate in meta"},
	    {10, "remove new user restrictions"},
	    {10, "create wiki posts"},
	    {15, "vote up"},
	    {15, "flag posts"},
	    {20, "talk in chat"},
	    {50, "comment everywhere"},
	    {75, "set bounties"},
	    {100, "edit community wiki"},
	    {100, "create chat rooms"},
	    {125, "vote down"},
	    {150, "create tags"},
	    {200, "retag questions"},
	    {250, "view close votes"},
	    {500, "cast close and reopen votes"},
	    {750, "established user"},
	    {1000, "edit questions and answers"},
	    {1000, "create gallery chat rooms}"},
	    {1250, "create tag synonyms}"},
	    {1500, "approve tag wiki edits"},
	    {2000, "access to moderator tools"},
	    {3500, "protect questions"},
	    {4000, "trusted user"},
	};

	const Sitrep *e, *p;
	size_t i, j;
	int r;

	r = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < nelem(events); j++) {
			e = events + j;
			if (!strcmp(e->description, s[i])) {
				r += e->value;
				break;
			}
		}
	}

	printf("%d reputation\n", r);
	for (i = 0; i < nelem(privileges); i++) {
		p = privileges + i;
		if (r < p->value)
			break;
		printf("%d %s\n", p->value, p->description);
	}
}

int
main(void)
{
	const char *s1[] = {
	    "join website",
	    "association bonus",
	    "answer upvoted",
	    "answer upvoted",
	    "question upvoted",
	    "answer accepted",
	    "answer upvoted",
	    "accept answer",
	    "unaccept answer",
	    "question unupvoted",
	    "accept answer",
	    "question upvoted",
	};

	rank(s1, nelem(s1));
	return 0;
}
