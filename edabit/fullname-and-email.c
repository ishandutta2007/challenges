/*

Create the instance attributes fullname and email in the Employee class. Given a person's first and last names:

    Form the fullname by simply joining the first and last name together, separated by a space.
    Form the email by joining the first and last name together with a . in between, and follow it with @company.com at the end. Make sure everything is in lowercase.

Examples

emp_1 = Employee("John", "Smith")
emp_2 = Employee("Mary",  "Sue")
emp_3 = Employee("Antony", "Walker")

emp_1.fullname ➞ "John Smith"

emp_2.email ➞ "mary.sue@company.com"

emp_3.firstname ➞ "Antony"

Notes

    The attributes firstname and lastname are already made for you.
    See the Resources tab for some helpful tutorials on Python classes!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	char fullname[32];
	char firstname[32];
	char lastname[32];
	char email[32];
} Employee;

void
employee_init(Employee *e, const char *firstname, const char *lastname)
{
	char *p;

	snprintf(e->fullname, sizeof(e->fullname), "%s %s", firstname, lastname);
	snprintf(e->firstname, sizeof(e->firstname), "%s", firstname);
	snprintf(e->lastname, sizeof(e->lastname), "%s", lastname);
	snprintf(e->email, sizeof(e->email), "%s.%s@company.com", firstname, lastname);
	for (p = e->email; *p; p++)
		*p = tolower(*p);
}

int
main(void)
{
	Employee emp1, emp2, emp3, emp4;

	employee_init(&emp1, "John", "Smith");
	employee_init(&emp2, "Mary", "Sue");
	employee_init(&emp3, "Antony", "Walker");
	employee_init(&emp4, "Joshua", "Senoron");

	assert(!strcmp(emp1.firstname, "John"));
	assert(!strcmp(emp1.lastname, "Smith"));
	assert(!strcmp(emp1.fullname, "John Smith"));
	assert(!strcmp(emp1.email, "john.smith@company.com"));

	assert(!strcmp(emp2.firstname, "Mary"));
	assert(!strcmp(emp2.lastname, "Sue"));
	assert(!strcmp(emp2.fullname, "Mary Sue"));
	assert(!strcmp(emp2.email, "mary.sue@company.com"));

	assert(!strcmp(emp3.firstname, "Antony"));
	assert(!strcmp(emp3.lastname, "Walker"));
	assert(!strcmp(emp3.fullname, "Antony Walker"));
	assert(!strcmp(emp3.email, "antony.walker@company.com"));

	assert(!strcmp(emp4.firstname, "Joshua"));
	assert(!strcmp(emp4.lastname, "Senoron"));
	assert(!strcmp(emp4.fullname, "Joshua Senoron"));
	assert(!strcmp(emp4.email, "joshua.senoron@company.com"));

	return 0;
}
