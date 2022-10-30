/*

I was doing the bandit wargame from overthewire.org and because I am a script kiddie, I googled the answer for level 24.

password="UoMYTrfrBFHyQXmg6gzctqAwOmw1IohZ"
for i in {0000..9999}
//looping to try any possible pin code
do
echo $password' '$i >> wordlist.txt
//save password and possible pin code into wordlist
done
I saw the bash script, and thought, "Well I couldn't have done that because I'm not good at bash." but then I realized that this problem could be done in other languages.

The challenge is simple.

Pipe the password in from stdin.
Append a space in-between the password and the pin or output it separately
Output all PIN combinations. Make sure that there are 4 digits outputted.
BONUS flush the output after each line. This is done automatically with std::endl.
I went ahead and did it in C++

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
        string key; //1
        getline(cin, key); //I heard that std::getline is
        //only standard for linux, so for practical
        //purposes use cin.getline(char*,size)
        for(int i = 0; i < 10000; i++){   //3
                cout << key << setfill('0') << ' ' //2
                << setw(4) << i << endl;  //4
        }
        return 0;
}
Obviously it can do better than 301 bytes, but you get the gist.

Also any language is acceptable as long as it can produce the same formatted strings separated by new lines or line breaks.

*/

#include <stdio.h>
#include <string.h>

int
main(void)
{
	char b[128], *p;
	int i;

	if (!fgets(b, sizeof(b), stdin))
		b[0] = '\0';

	p = strchr(b, '\n');
	if (p)
		*p = '\0';

	for (i = 0; i < 10000; i++) {
		printf("%s %04d\n", b, i);
		fflush(stdout);
	}

	return 0;
}
