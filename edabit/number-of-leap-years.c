/*

Given a range of years as a string, return the number of leap years there are within the range (inclusive).
Examples

numLeapYears("1980-1984") ➞ 2
// 1980 and 1984 are leapyears.

numLeapYears("2000-2020") ➞ 6

numLeapYears("1600-2000") ➞ 98

Notes

    Remember that a hyphen separates the years.
    Check the Resources tab for help on checking whether a year is a leap year.

*/

#include <assert.h>
#include <stdio.h>

void
swapl(long *x, long *y)
{
	long t;

	t = *y;
	*y = *x;
	*x = t;
}

long
leapb(long y)
{
	y--;
	return (y / 4) - (y / 100) + (y / 400);
}

// https://stackoverflow.com/questions/4587513/how-to-calculate-number-of-leap-years-between-two-years-in-c-sharp
long
leapyears(const char *s)
{
	long y0, y1;

	if (sscanf(s, "%ld-%ld", &y0, &y1) != 2)
		return -1;
	if (y0 > y1)
		swapl(&y0, &y1);

	return leapb(y1 + 1) - leapb(y0);
}

int
main(void)
{
	assert(leapyears("2000-2020") == 6);
	assert(leapyears("1600-2000") == 98);
	assert(leapyears("1980-1984") == 2);
	assert(leapyears("1224-8090") == 1666);
	assert(leapyears("2486-7607") == 1241);
	assert(leapyears("1813-4354") == 616);
	assert(leapyears("772-1849") == 262);
	assert(leapyears("2228-7099") == 1182);
	assert(leapyears("1349-6325") == 1206);
	assert(leapyears("1803-3828") == 492);
	assert(leapyears("295-6278") == 1451);
	assert(leapyears("107-1821") == 416);
	assert(leapyears("2912-6566") == 887);
	assert(leapyears("1006-5181") == 1013);
	assert(leapyears("2876-9210") == 1536);
	assert(leapyears("1189-5481") == 1041);
	assert(leapyears("1325-1409") == 20);
	assert(leapyears("2665-3338") == 163);
	assert(leapyears("1886-3577") == 410);
	assert(leapyears("2951-4523") == 381);
	assert(leapyears("2651-7572") == 1194);
	assert(leapyears("2036-3126") == 264);
	assert(leapyears("1602-6986") == 1306);
	assert(leapyears("35-602") == 137);
	assert(leapyears("38-1709") == 405);
	assert(leapyears("801-2232") == 347);
	assert(leapyears("1285-5033") == 908);
	assert(leapyears("1265-7254") == 1452);
	assert(leapyears("1716-4551") == 688);
	assert(leapyears("2630-7508") == 1183);
	assert(leapyears("385-7421") == 1706);
	assert(leapyears("1127-5813") == 1137);
	assert(leapyears("1154-6034") == 1184);
	assert(leapyears("1378-8971") == 1841);
	assert(leapyears("925-8529") == 1844);
	assert(leapyears("1399-9450") == 1952);
	assert(leapyears("2031-7773") == 1393);
	assert(leapyears("1790-7283") == 1332);
	assert(leapyears("2642-5884") == 787);
	assert(leapyears("1084-4877") == 921);
	assert(leapyears("2934-6071") == 761);
	assert(leapyears("2074-8842") == 1641);
	assert(leapyears("2609-9866") == 1760);
	assert(leapyears("647-6876") == 1512);
	assert(leapyears("478-9783") == 2256);
	assert(leapyears("1561-3415") == 449);
	assert(leapyears("2535-4282") == 424);
	assert(leapyears("2920-6439") == 854);
	assert(leapyears("1601-9234") == 1851);
	assert(leapyears("728-6018") == 1284);
	assert(leapyears("1664-8395") == 1632);
	assert(leapyears("2489-3010") == 125);
	assert(leapyears("2768-9052") == 1525);
	assert(leapyears("2765-9052") == 1525);

	return 0;
}
