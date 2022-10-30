/*

You are asked to ensure that the first and last names of people begin with a capital letter in their passports.
For example, alison heck should be capitalised correctly as Alison Heck.

Given a full name, your task is to capitalize the name appropriately.

*/

#include <stdio.h>
#include <ctype.h>

char *
capitalize(char *s)
{
	size_t i, j;

	for (j = i = 0; s[i] != '\0'; i++) {
		if (islower(s[i]) && j == 0)
			s[i] = toupper(s[i]);
		if (isspace(s[i]))
			j = 0;
		else
			j++;
	}
	return s;
}

int
main(void)
{
	char a[] = "alison heck";
	printf("%s\n", capitalize(a));

	char b[] = "chris alan";
	printf("%s\n", capitalize(b));

	char c[] = "hello world";
	printf("%s\n", capitalize(c));

	char d[] = "12abc";
	printf("%s\n", capitalize(d));

	char e[] = "HXA liME";
	printf("%s\n", capitalize(e));
	return 0;
}
