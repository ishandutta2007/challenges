/*

(Just open 50 tabs in Google Chrome :D (just kidding, no you can't))

Shortest code for infinite disk I/O any language, C# example:

using System.IO;

namespace FileApp {
    static class Program {
        public static void Main() {
            do {
                File.WriteAllText("a", "a");
                File.Delete("a");
            } while (true);
        }
    }
}

You can't just fill the entire disk though, as then it would halt in the end and would be finite.

And you can't do reading only, infinite writing has to happen. (It has to kill my SSD after enough runtime.)

Get cracking! :)

*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

char *
now(void)
{
	struct tm *tm;
	time_t t;

	time(&t);
	tm = gmtime(&t);
	return asctime(tm);
}

int
main(void)
{
	FILE *fp;
	char *buf;
	size_t len;

	len = 1ull << 31;
	buf = calloc(1, len);
	if (!buf)
		return 1;

	printf("%sstarted\n", now());
	do {
		fp = fopen("iostress.dat", "wb");
		if (!fp)
			continue;

		setvbuf(fp, NULL, _IONBF, 0);

		fwrite(buf, len, 1, fp);
		fclose(fp);

		printf("%swrote %zu bytes\n", now(), len);
	} while (1);

	return 0;
}
