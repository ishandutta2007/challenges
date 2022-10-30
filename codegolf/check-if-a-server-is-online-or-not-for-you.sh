#!/bin/sh

cat << EOF >/dev/null

Inspired from Is this site down or is it just me?
Challenge

You have to print if a website server is online or not, for you.
Input

The domain name, like codegolf.stackexchange.com
Output

    1/True if online
    0/False if offline

Rules

    Any kind of web access is allowed

    URL shorteners allowed

    Except 2 no. Rule, all standard loopholes forbidden

    You cannot use a language which cannot access internet

    This is code-golf, so shortest answer wins

Cheers!

EOF

online() {
	ping -c 1 $1 >/dev/null 2>&1
	if [ $? -eq 0 ]; then
		echo "true"
	else
		echo "false"
	fi
}

if [ $# -eq 0 ]; then
	echo "usage: <url>"
	exit 2
fi

online $1

