#!/bin/sh

cat << EOF > /dev/null 
Your task is to create the shortest infinite loop!

The point of this challenge is to create an infinite loop producing no output, unlike its possible duplicate. The reason to this is because the code might be shorter if no output is given.
Rules

    Each submission must be a full program.
    You must create the shortest infinite loop.
    Even if your program runs out of memory eventually, it is still accepted as long as it is running the whole time from the start to when it runs out of memory. Also when it runs out of memory, it should still not print anything to STDERR.
    The program must take no input (however, reading from a file is allowed), and should not print anything to STDOUT. Output to a file is also forbidden.
    The program must not write anything to STDERR.
    Feel free to use a language (or language version) even if it's newer than this challenge. -Note that there must be an interpreter so the submission can be tested. It is allowed (and even encouraged) to write this interpreter yourself for a previously unimplemented language. :D
    Submissions are scored in bytes, in an appropriate (pre-existing) encoding, usually (but not necessarily) UTF-8. Some languages, like Folders, are a bit tricky to score - if in doubt, please ask on Meta.
    This is not about finding the language with the shortest infinite loop program. This is about finding the shortest infinite loop program in every language. Therefore, I will not accept an answer.
    If your language of choice is a trivial variant of another (potentially more popular) language which already has an answer (think BASIC or SQL dialects, Unix shells or trivial Brainf**k-derivatives like Alphuck), consider adding a note to the existing answer that the same or a very similar solution is also the shortest in the other language.
    There should be a website such as Wikipedia, Esolangs, or GitHub for the language. For example, if the language is CJam, then one could link to the site in the header like #[CJam](http://sourceforge.net/p/cjam/wiki/Home/), X bytes.
    Standard loopholes are not allowed.

(I have taken some of these rules from Martin Büttner's "Hello World" challenge)

Please feel free to post in the comments to tell me how this challenge could be improved.
EOF

while true
do
	true
done

