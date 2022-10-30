#!/usr/bin/env swipl

/*

Steve Ballmer is the ex-CEO of Microsoft, and in a recent article, claimed that he "still does not know what he did wrong with mobile".

As CodeProject's newsletter pointed out, "That article's title could be ended at so many spots and still be accurate".

Given no input, output the following:

Steve Ballmer still does not know.
Steve Ballmer still does not know what he did.
Steve Ballmer still does not know what he did wrong.
Steve Ballmer still does not know what he did wrong with mobile.
This must be outputted exactly as shown, and must be the only output of your program. You may include a single trailing newline.

This is code-golf so fewest bytes in each language wins

*/

:- initialization(main).

main :-
	write('Steve Ballmer still does not know.'), nl,
	write('Steve Ballmer still does not know what he did.'), nl,
	write('Steve Ballmer still does not know what he did wrong.'), nl,
	write('Steve Ballmer still does not know what he did wrong with mobile.'), nl,
	halt.

