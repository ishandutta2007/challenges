/*

Create a function which takes in an encoded string and returns an object according to the following example:

Notes

The string will always be in the same format, first name, last name and id with zeros between them. Id numbers will not contain any zeros

*/

#include <assert.h>
#include <stdio.h>
#include <errno.h>

typedef struct {
	char firstname[32];
	char lastname[32];
	char id[32];
} Person;

const char *
parsestring(const char *s, char *b, size_t n)
{
	size_t i, j;

	for (i = j = 0; s[i] && s[i] != '0'; i++) {
		if (j + 1 >= n)
			return NULL;
		b[j++] = s[i];
	}
	b[j] = '\0';

	while (s[i] == '0')
		i++;

	if (i == 0)
		return NULL;
	return s + i;
}

int
parsecode(const char *s, Person *p)
{
	if (!(s = parsestring(s, p->firstname, sizeof(p->firstname))))
		return -1;
	if (!(s = parsestring(s, p->lastname, sizeof(p->lastname))))
		return -1;
	if (!(s = parsestring(s, p->id, sizeof(p->id))))
		return -1;
	if (*s != '\0')
		return -1;

	return 0;
}

void
print(Person *p)
{
	printf("{\n");
	printf("  firstName: \"%s\"\n", p->firstname);
	printf("  lastName: \"%s\"\n", p->lastname);
	printf("  id: \"%s\"\n", p->id);
	printf("}\n");
}

void
test(const char *s)
{
	Person p;

	assert(parsecode(s, &p) == 0);
	print(&p);
}

int
main(void)
{
	test("John000Doe000123");
	test("Michael0Smith004331");
	test("Thomas0000Lee0000045553");
	test("a0b01");
	return 0;
}
