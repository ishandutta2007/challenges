#!/bin/sh

cat << EOF > /dev/null

Write a program that takes a filename and a parameter n and prints the n most common words in the file, and the count of their occurrences, in descending order.

Request: Please take your time in browsing r/dailyprogrammer_ideas and helping in the correcting and giving suggestions to the problems given by other users. It will really help us in giving quality challenges!

Thank you!

EOF

if [ $# -ne 2 ]; then
	echo "usage: nth file"
	exit 2
fi

tr -c '[:alnum:]' '[\n*]' < $2 | sort | uniq -c | sort -nr | head -n $1
