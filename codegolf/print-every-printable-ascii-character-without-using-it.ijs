NB. In a programming language of your choice, write 95 programs, each of which outputs a different one of the 95 printable ASCII characters without that character occurring anywhere in the program.
NB. 
NB. For example, if your language was Python, your program that outputs the character P might be
NB. 
NB. print(chr(80))
NB. because P has ASCII code 80. This program is valid because P never appears in the source code. However, for the program that outputs lowercase p, something like
NB. 
NB. print(chr(112))
NB. would be invalid because, while it does print p, p is present in the code. A valid program could be
NB. 
NB. exec(chr(112)+'rint(chr(112))')
NB. which prints p but does not contain p.
NB. 
NB. Your goal is to make each of your 95 programs as short as possible. Your score is the sum of the character lengths of all your programs.
NB. 
NB. If for any reason you are unable to write valid programs for some characters, you may mark those characters as "Did Not Program" or DNP, and omit programs for them entirely. This way syntactically strict languages will be able to compete.
NB. 
NB. The winning answer is the answer that has the lowest score of the set of answers that have the fewest DNP's.
NB. 
NB. Rules
NB. The source code of all of your programs may only contain printable ASCII plus tabs and newlines, all of which are counted as one character. (Because in a different encoding it would be easy to omit characters that don't exist!)
NB. 
NB. Note: This rule seems necessary but there are many languages with different encodings and I'm sure it'd be cool to see the answers for them. Therefore you can break this rule, you can use whatever characters you want, but then your answer becomes non-competitive, it cannot win.
NB. The programs must be actual, full programs, according to your language's standard conventions. Functions and REPL snippets are not allowed.
NB. 
NB. Each program's output should go to stdout or your language's accepted alternative.
NB. 
NB. Programs should not prompt for or require input. (If prompting for input is inherent to your language, that's ok.)
NB. 
NB. Programs should be deterministic, finite in run time, and independent. e.g. it shouldn't matter if one is run in a folder separate from the other programs.
NB. 
NB. A program's output should be the precise printable ASCII character it corresponds to, optionally followed by a single trailing newline, nothing more, nothing less.
NB. 
NB. Be sure to include information on all 95 (ideally) programs in your answer, as well as your score and any DNP's. You don't have to list all programs that follow a simple pattern like "print(chr(80)), print(chr(81)), print(chr(82))..." but make sure you're sure they all would work and that your score is added correctly.
NB. 
NB. For reference, here are the 95 printable ASCII your programs must output:
NB. 
NB.  !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~

a. {~ 32+i.95
