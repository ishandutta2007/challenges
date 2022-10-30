#!/bin/sh

cat << EOF > /dev/null

Write a function that, given a string, removes from the string any * character, or any character that's one to the left or one to the right of a * character. Examples:

"adf*lp" --> "adp"
"a*o" --> ""
"*dech*" --> "ec"
"de**po" --> "do"
"sa*n*ti" --> "si"
"abc" --> "abc"

Thanks to user larg3-p3nis for suggesting this problem in r/dailyprogrammer_ideas!

EOF

while read line
do
	echo $line | sed 's/*//g'
done
