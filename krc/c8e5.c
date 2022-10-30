// Modify the fsize program to print the other information contained
// in the inode entry.

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

enum {
	MAX_PATH = 4096,
};

void
dirwalk(const char *dir, void (*fcn)(const char *))
{
	char name[MAX_PATH];
	struct dirent *dp;
	DIR *dfd;

	dfd = opendir(dir);
	if (dfd == NULL) {
		fprintf(stderr, "dirwalk: can't open %s\n", dir);
		return;
	}

	while ((dp = readdir(dfd))) {
		if (!strcmp(dp->d_name, ".") || !strcmp(dp->d_name, ".."))
			continue;

		if (strlen(dir) + strlen(dp->d_name) + 2 > sizeof(name)) {
			fprintf(stderr, "dirwalk: name %s/%s too long\n", dir, dp->d_name);
			continue;
		}
		snprintf(name, sizeof(name), "%s/%s", dir, dp->d_name);
		fcn(name);
	}
	closedir(dfd);
}

void
fsize(const char *name)
{
	struct stat st;

	if (stat(name, &st) < 0) {
		fprintf(stderr, "fsize: can't access %s\n", name);
		return;
	}
	if ((st.st_mode & S_IFMT) == S_IFDIR)
		dirwalk(name, fsize);
	
	printf("%5lu %6o %3lu %8ld %s\n",
	       st.st_ino, st.st_mode, st.st_nlink, st.st_size, name);
}

int
main(int argc, char *argv[])
{
	if (argc < 2)
		fsize(".");
	else {
		while (--argc > 0)
			fsize(*++argv);
	}
	return 0;
}
