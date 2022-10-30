#!/usr/bin/perl -w

=pod

Your goal is to create an alphabet song as text in the following form (in order):

A is for <word starting with A>
B is for <word starting with B>
C is for <word starting with C>
...
Z is for <word starting with Z>

Example output:

A is for Apple
B is for Banana
C is for Carrot
D is for Door
E is for Elephant
F is for Frog
G is for Goat
H is for Hat
I is for Icicle
J is for Jelly
K is for Kangaroo
L is for Lovely
M is for Mom
N is for Never
O is for Open
P is for Paste
Q is for Queen
R is for Rice
S is for Star
T is for Test
U is for Underneath
V is for Very
W is for Water
X is for X-ray
Y is for Yellow
Z is for Zipper

Rules:

    Each "letter" of the song has its own line, so there are 26 lines, and a possible trailing linefeed.

    The output is case-sensitive:
        The letter at the start of each line must be capitalized.
        is for is lowercase.
        The chosen word does not need to be capitalized, but may be. All lines should be consistent.

    The chosen word for each line is up to you, but must be a valid English word with at least 3 letters, and it cannot be a conjunction (like and or but), interjection/exclamation (like hey or yay), abbreviation (like XLS), or a name (like Jon).

    Though I doubt anyone would find it shorter, I'd find it acceptable to use a phrase instead of a single word. So if for some reason S is for Something smells fishy... is shorter, go for it.

    Put your program's output in your answer, or at least the list of words you used (if there's a link to run your code online, we don't need to see the entire output).

    Shortest code wins

=cut

print('A is for Apple
B is for Banana
C is for Carrot
D is for Door
E is for Elephant
F is for Frog
G is for Goat
H is for Hat
I is for Icicle
J is for Jelly
K is for Kangaroo
L is for Lovely
M is for Mom
N is for Never
O is for Open
P is for Paste
Q is for Queen
R is for Rice
S is for Star
T is for Test
U is for Underneath
V is for Very
W is for Water
X is for X-ray
Y is for Yellow
Z is for Zipper
');

