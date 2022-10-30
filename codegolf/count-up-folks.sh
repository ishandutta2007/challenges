#!/bin/sh

cat << EOF > /dev/null

Introduction

It may sound strange, but we haven't got ONE challenge for counting from 1 to n, inclusive.

This is not the same thing. That one is a (closed) not well-explained challenge.
This is not the same thing. That one is about counting up indefinitely.
Challenge

Write a program or function that prints every integer from 1 to n inclusive.
Rules

    You can get n any way.
    You can assume that n will always be a positive integer.
    You can get n in any base, but you should always output in decimal.
    Output must be separated by any character (or pattern) not in 0123456789. Non-decimal leading or trailing characters are allowed (for example when using arrays such as [1, 2, 3, 4, 5, 6]).
    Standard loopholes are denied.
    We want to find the shortest approach in each language, not the shortest language, so I will not accept any answer.
    You must update your answer(s) after this edit, answers posted before the last edit must comply with the change rule about standard loopholes (I didn't want to deny them, but I didn't want to make the community roar, so I denied them).
    You can use any post-dating language version (or language). You cannot use any language or language version made just for this challenge.

Bonuses
20%

    Your program must be able to count at least up to 18446744073709551615 (2^64-1). For example, if a new datatype is the only way to support big integers, you must construct it. If your language does not have any way to support huge integers up to 2^64-1, the upper limit of that particular language must be supported instead.

EDIT: I've changed the limit from 2^64 to 2^64-1 to allow more answers.

EDIT: I made the 2^64-1 rule a bonus, since there has not been much interest in this challenge. If your answer supports 2^64-1, you can now edit it to include the bonus. Also, you can post an answer not supporting it, if it is shorter.

EOF

n=$1
if [[ $n == "" ]]; then
	n=$(echo 2^64 | bc)
fi

seq 1 1 $n
