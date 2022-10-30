// Match couples based on likeability

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* constraints based on the homework specs */
#define MATCHING_FILE "matching.txt"
#define MAX_NAME 20
#define MAX_PAIRS 10

/* the struct containing the info of the couple pairs,
 * male first, then female. One struct only holds
 * one run out of n specified in the input file */
struct person_info {
	char name[MAX_PAIRS * 2][MAX_NAME];
	int attraction[MAX_PAIRS * 2][MAX_PAIRS];
	int number_of_pairs;
};

/* matching info stuff, like how many runs to do */
struct matching_info {
	int runs;
};
/* prototypes */
static void swap(int *, int, int);
static int min(int, int);
static int max(int, int);
static struct person_info *open_file(const char *, struct matching_info *);
static void permute(struct person_info *, int *, int *, int);
static void match(struct matching_info *, struct person_info *);

int
main(void)
{

	struct matching_info minfo;
	/* open the file and get all the couples to pair off */
	struct person_info *pinfo = open_file(MATCHING_FILE, &minfo);
	if (!pinfo)
		return 1;
	/* permute them to find the best match */
	match(&minfo, pinfo);
	/* cleanup and exit */
	free(pinfo);
	return 0;
}

/* swap the values in an index, use this
 * to do recursive permutations */
static void
swap(int *index, int i, int k)
{
	int temp = index[i];
	index[i] = index[k];
	index[k] = temp;
}

/* get minimum out of the two */
static int
min(int a, int b)
{
	return (a < b) ? a : b;
}

/* get maximum out of the two */
static int
max(int a, int b)
{
	return (a > b) ? a : b;
}

/* open the file */
static struct person_info *
open_file(const char *file,
          struct matching_info *minfo)
{
	FILE *fp;
	int i, k, l, j;
	struct person_info *p = NULL;
	/* since the assignment didn't say anything
	 * about valid input assumption, we have to check
	 * for errors, due to alot of redundant code,
	 * gotos in this case are very helpful. */

	/* open the file */
	if (!(fp = fopen(file, "r"))) {
		/* failed, so exit */
		printf("Error: %s\n", strerror(errno));
		goto done;
	}

	/* get the number of runs we are supposed to do */
	if (fscanf(fp, "%d", &minfo->runs) < 1) {
		printf("Error parsing the number of runs in the file.\n");
		goto done;
	}

	/* allocate memory */
	if (!(p = malloc(sizeof(struct person_info) * minfo->runs)))
		goto done;

	/* double for loops that loops through the runs
	 * and get the info about the couple names and their
	 * attraction rating */
	for (i = 0; i != minfo->runs; ++i) {
		fscanf(fp, "%d", &p[i].number_of_pairs);
		/* check if greater than max pairs */
		if (p[i].number_of_pairs > MAX_PAIRS || p[i].number_of_pairs < 2) {
			printf("%d people is too few/many for this program!\n",
			       p[i].number_of_pairs);
			goto free_mem;
		}
		/* since the number represent a pair, have to
		 * multiply by 2 to get each individual */
		l = p[i].number_of_pairs * 2;
		/* get the names of the people */
		for (k = 0; k != l; ++k) {
			if (fscanf(fp, "%20s", p[i].name[k]) < 1) {
				printf("Failed to read in the names!\n");
				goto free_mem;
			}
		}
		/* get their attraction ratings */
		for (k = 0; k != l; ++k) {
			for (j = 0; j != p[i].number_of_pairs; ++j) {
				if (fscanf(fp, "%d", &p[i].attraction[k][j]) < 1) {
					printf("Failed to read all the attraction numbers!\n");
					goto free_mem;
				}
				if (p[i].attraction[k][j] > 10 || p[i].attraction[k][j] < 1) {
					printf("Invalid score in input file!\n");
					printf("The score has to be 1 to 10 inclusive! Exiting!\n");
					goto free_mem;
				}
			}
		}
	}
	/* if failed, return NULL */
done:
	if (fp)
		fclose(fp);
	return p;

free_mem:
	free(p);
	p = NULL;
	goto done;
}

/* this is the main algorithm, the recursive permutation */
static void
permute(struct person_info *pinfo, int *index, int *best, int k)
{
	int i, t, sum, diff, x, y;

	/* we are at the end of the permutation, add up the sums
	 * of the couple pairs, and see if its the best one */
	if (k == pinfo->number_of_pairs) {
		for (sum = t = 0; t != pinfo->number_of_pairs; ++t) {
			x = min(pinfo->attraction[index[t]][t],
			        pinfo->attraction[t][index[t] - pinfo->number_of_pairs]);
			y = max(pinfo->attraction[index[t]][t],
			        pinfo->attraction[t][index[t] - pinfo->number_of_pairs]);

			sum += x;
			diff += y - x;
		}

		/* copy over the best, either sum is greater than best,
		 * or they are equal then we check their difference for the minimum
		 * diff, the teacher guaranteed us that the input case will have
		 * only a unique minimizing pair, so dont worry for collisions */
		if (sum > best[MAX_PAIRS] ||
		    (sum == best[MAX_PAIRS] && diff < best[MAX_PAIRS + 1])) {
			memcpy(best, index, pinfo->number_of_pairs * sizeof(int));
			best[MAX_PAIRS] = sum;
			best[MAX_PAIRS + 1] = diff;
		}
		return;
	}

	for (i = k; i != pinfo->number_of_pairs; ++i) {
		/* doesn't matter if its male or the female that we swap
		   still get all of the combinations, but permute the
		   females to make it easier on us because of the output
		   specs */
		swap(index, k, i);
		permute(pinfo, index, best, k + 1); /* recursively permute */
		swap(index, i, k);
	}
}

/* this function calls the recursive permute */
static void
match(struct matching_info *minfo, struct person_info *pinfo)
{
	int i, k;
	int index[MAX_PAIRS], best[MAX_PAIRS + 2];
	/* do up to the number of runs */
	for (i = 0; i != minfo->runs; ++i) {
		/* preinitialize the best values to something
		 * so big that no couple would score them as */
		best[MAX_PAIRS] = -32000;
		best[MAX_PAIRS + 1] = 32000;

		/* these are the numbers to the female indices,
		 * we are going to permute this. */
		for (k = 0; k != pinfo[i].number_of_pairs; ++k)
			index[k] = k + pinfo[i].number_of_pairs;
		/* permute index and passing it the best array in which
		 * the best matching will be stored in */
		permute(&pinfo[i], index, best, 0);

		/* print out the best matching score, and then
		 * print out the couples */
		printf("Matching #%d: Maximum Score = %d.\n\n", i + 1,
		       best[MAX_PAIRS]);

		for (k = 0; k != pinfo[i].number_of_pairs; ++k)
			printf("%s %s\n", pinfo[i].name[k], pinfo[i].name[best[k]]);

		printf("\n\n");
	}
}
