/*

My father who was a really good APLer and taught me all the basics of APL (and much more), passed away on this day, five years ago.
In preparation for 50 Years of APL, I found this patent letter (translated for the convenience of those who do not read Danish) for a handwritten logo.
It explains a major reason for APL never gaining a large user base – a reason which of course applies to all of this community's amazing golfing languages too:

A 3497/77                           Req. 29th Aug. 1977 at 13

EASIER COMMUNICATION MEANS FASTER CODING MEANS FEWER CODERS MEANS …

Henri Brudzewsky, engineering consultancy company, Mindevej 28, Søborg,

class 9, including computers, especially APL coded computers,
class 42: IT service agency company, especially during use of APL coded computers.

Task
Produce infinitely repeating output of the text EASIER COMMUNICATION MEANS FASTER CODING MEANS FEWER CODERS MEANS  with no newlines. You may begin the text with EASIER or FASTER or FEWER.

*/

#include <stdio.h>

int
main(void)
{
	for (;;)
		printf("EASIER COMMUNICATION MEANS FASTER CODING MEANS FEWER CODERS MEANS");

	return 0;
}
