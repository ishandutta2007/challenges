#!/bin/sh

cat << EOF > /dev/null

Background

Sometimes, people think you didn't work at your git project. But - you can prove yourself with git shortlog -n. Now, the problem is you are a programmer and programmers are lazy. So you want to write a program which shows the person who committed at most.
Rules

You may not do the following things:

    use git shortlog with the argument -s

    use any alias, which calls git on any way

You may assume the following:

    git is installed on the system

    You are in the working directory of the repository where to find out the person

    The output of git shortlog -n will be piped in your program, but you may also call the command in your program, even though I can't see the advantage.

    If there is a language-specific package or library for git, you may use it.

The output

Your program has to output the name of the person with the most commits in the repo.

This is a code-golf challenge, so the program with the least amount of bytes wins!

EOF

git shortlog -n | egrep '^[^[:space:]]'
