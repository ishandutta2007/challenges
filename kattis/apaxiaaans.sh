#!/bin/sh

cat << EOF > /dev/null

The ancient and mysterious Apaxian civilization, which we most certainly did not make up, continues to confound the researchers at the Oriental Institute.
It turns out that the Apaxians had a peculiar naming system: the more letters in your name, the higher your status in society.
So, in Apaxian society, robert was probably a lowly servant, and robertapalaxiamethostenes was likely a High Priest or Minister.
Even more than that, Apaxians valued the number of adjacent letters that were the same in a name. So, while robert continues to be an unimpressive name, roooooooooobert probably elicited cheers and applause wherever he went.

Unfortunately, this makes the task of reading Apaxian scrolls very cumbersome, especially when you consider that a particularly famous Apaxian queen had ten thousand consecutive a’s in her name.
Legend has it that she was already two years old by the time the Royal Herald finished announcing her birth.

To make the Oriental Institute’s life easier, the Department of Computer Science has offered to convert the Apaxian scrolls into a more readable format.
Specifically, we will be taking Apaxian names and replacing all consecutive runs of the same letter by a single instance of such letter.

So, for example, the compact version of roooobert would be robert, where the four consecutive o’s have been replaced with a single o.
Similarly, the compact version of rrrooobbbert would also be robert. On the other hand, the compact version of robert is still robert.

Input

The input contains a single name. Each name contains only lowercase letters (a–z), no whitespace, a minimum length of 1 character, and a maximum length of 250 characters.

Output

The output contains the compact version of the name: any time the same letter appears two or more times in sequence, it must be replaced by a single instance of that letter.

robert -> robert
rooobert -> robert
roooooobertapalaxxxxios -> robertapalaxios

EOF

echo $@ | tr -s 'a-z'
