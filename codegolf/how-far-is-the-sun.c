/*

Introduction
tl;dr

Continuously output the current distance from the Earth to the Sun.

Simplified, the orbit of the Earth around the Sun is an ellipse. So the actual distance between both is constantly changing. This distance can be calculated for any given day using this formula:

d/AU=1-0.01672 cos(0.9856(day-4))

The equation can be split into the following parts2:

1 represents 1 AU (astronomical unit), equals 149,597,870.691 km
0.01672 is the orbital eccentricity between the Earth and the Sun
cos is of course the cosine function, but with argument in degrees rather than radians
0.9856 is 360° / 365.256363 days, a full rotation in one year, where 365.256363 is the length of a sidereal year, in mean solar days
day is the day of the year [1-365]
4 represents the offset to the perihelion, which is between 4th and 6th of January
The formula takes a whole day but for the purpose of this challenge – a continuously output – you have to be more accurate; or nothing much will happen till the next day. Simply add the percentage of the past time to the current day, like1:

day + (h * 3600 + m * 60 + s) / 864 / 100
A few Examples:

1 January, 23:59:59 1.99998842592593
1 January, 18:00:00 1.75
1 January, 12:00:00 1.50
1 January, 06:00:00 1.25
Input
This challenge has no input.

If your language can't get the current time, you can get it as an input to your program. Valid inputs are timestamps or complete date-time strings that suits the language best. Passing the current day alone (like 5 for 5th January or 5.25 for the same day at 6 o'clock) is not allowed.

Output
Output the current distance from the Earth to the Sun:

Output the value in km.
Update the value at least every second.
Example output:

152098342
If it doesn't increase your byte count, you can also pretty print the result:

152,098,342
152,098,342 km
Requirements
You can write a program or a function. If it is an anonymous function, please include an example of how to invoke it.
This is code-golf so shortest answer in bytes wins.
Standard loopholes are disallowed.
Example implementation
I've prepared an example implementation in JavaScript. It's neither competitive nor golfed.

// dayOfYear from http://stackoverflow.com/a/8620357/1456376
Date.prototype.dayOfYear = function() {
    var j1= new Date(this);
    j1.setMonth(0, 0);
    return Math.round((this-j1)/8.64e7);
}

// vars
var e = document.getElementById('view'),
    au = 149597870.691,
    deg2rad = Math.PI/180,
    date = now = value = null;

// actual logic
function calculate() {
    date = new Date();
    now = date.dayOfYear() + (date.getHours() * 3600 + date.getMinutes() * 60 + date.getSeconds()) / 864 / 100;
    value = 1 - 0.01672 * Math.cos(deg2rad * 0.9856 * (now - 4));
    // supported in Firefox and Chrome, unfortunately not in Safari
    e.innerHTML = Math.round(value * au).toLocaleString('en-US') + ' km';

    setTimeout(calculate, 1000);
}

// let's do this
calculate();
<div id="view"></div>

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

double
day(double yd, double h, double m, double s)
{
	return yd + (h * 3600 + m * 60 + s) / 864 / 100;
}

double
distance(double day)
{
	static const double au = 149597870.691;
	return (1 - 0.01672 * cos(0.9856 * (day - 4))) * au;
}

void
sim(void)
{
	struct tm tm;
	time_t t0, t1;
	char *p, *s;
	double d;

	t0 = 0;
	for (;;) {
		t1 = time(NULL);
		if (t1 != t0) {
			gmtime_r(&t1, &tm);

			s = asctime(&tm);
			p = strchr(s, '\n');
			if (p)
				*p = '\0';

			d = distance(day(tm.tm_yday, tm.tm_hour, tm.tm_min, tm.tm_sec));
			printf("%s (GMT): %.3f km\n", s, d);
		}
		t0 = t1;
	}
}

int
main(void)
{
	sim();
	return 0;
}
