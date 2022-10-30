#!/bin/bash

# For each line in a given input file, transform the first occurrence of the word 'the' with 'this'.
# The search and transformation should be strictly case sensitive.

# Substitute the first occurrence of 'editor' with 'tool':
# `$:~/hackerrank/bash/grep/grep1$` echo "My favorite programming editor is Emacs. Another editor I like is Vim." | sed -e s/editor/tool/
# My favorite programming tool is Emacs. Another editor I like is Vim.

# Substitute all the occurrences of 'editor' with 'tool':
# `$:~/hackerrank/bash/grep/grep1$` echo "My favorite programming editor is Emacs. Another editor I like is Vim." | sed -e s/editor/tool/g
# My favorite programming tool is Emacs. Another tool I like is Vim.

# Substitute the second occurrence of 'editor' with 'tool':
# `$:~/hackerrank/bash/grep/grep1$` echo "My favorite programming editor is Emacs. Another editor I like is Vim." | sed -e s/editor/tool/2
# My favorite programming editor is Emacs. Another tool I like is Vim.

# Highlight all the occurrences of 'editor' by wrapping them up in brace brackets:
# `$:~/hackerrank/bash/grep/grep1$` echo "My favorite programming editor is Emacs. Another editor I like is Vim." | sed -e s/editor/{\&}/g
# My favorite programming {editor} is Emacs. Another {editor} I like is Vim.

while read line
do
	echo $line | sed -e 's/\<the\>/this/'
done
