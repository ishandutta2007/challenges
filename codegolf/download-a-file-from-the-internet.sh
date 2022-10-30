#!/bin/sh

cat << EOF > /dev/null

Introduction
Yes, it's as simple as that. Download any file from the internet!

Rules
You must use your language's API.

You must output the file you downloaded to STDOUT, the console, a file, etc.

Input should be empty, or the URL you wish to download, but the url must count to byte count..

Good luck!

EOF

wget $@
