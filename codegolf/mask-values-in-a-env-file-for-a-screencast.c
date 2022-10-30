/*

Let's say I have a .env file with the following contents:

CF_WORKERS_ACCOUNT_ID=abcdef34632114
CF_WORKERS_API_TOKEN=abcdef34632114def3463def3463
FAB_DEV_ZONE_ID=434932843272439874329

I'm doing a screencast, and I want to quickly cat .env to show what's in the file, without broadcasting the exact values, since they're secret.

What I want is a one-line unix command (I'm on OSX personally) that gives me:

> cat .env | some_command
CF_WORKERS_ACCOUNT_ID=••••••••••••••
CF_WORKERS_API_TOKEN=••••••••••••••••••••••••••••
FAB_DEV_ZONE_ID=•••••••••••••••••••••

A little thing, but would be neat!

My best attempt is cat .env | ruby -pe 'k,v=$_.split("=");$_="#{k}=#{v.gsub(/./,"•")}"' but I'm sure it can be shorter...

*/

#include <stdio.h>

void
mask(FILE *ifp, FILE *ofp)
{
	int f, ch;

	f = 0;
	for (;;) {
		ch = fgetc(ifp);
		if (ch == EOF)
			return;

		if (ch == '=' && !f) {
			fputc(ch, ofp);
			f = 1;
			continue;
		}

		if (ch == '\n')
			f = 0;

		fputc((!f) ? ch : '*', ofp);
	}
}

int
main(void)
{
	mask(stdin, stdout);
	return 0;
}
