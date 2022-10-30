/*

Create a function that takes a string of four numbers. These numbers represent two separat points on a graph known as the x-axis (horizontal axis) and y-axis (vertical axis). Each number corresponds as follows: "x1, y1, x2, y2". Calculate the distance between x and y.

Notes

All floats fixed to 2 decimal places (e.g. 2.34).

*/

#include <stdio.h>
#include <math.h>

double
shd(const char *s)
{
	int x1, x2, y1, y2;

	if (sscanf(s, "%d, %d, %d, %d", &x1, &y1, &x2, &y2) != 4)
		return 0;
	return hypot(x2 - x1, y2 - y1);
}

int
main(void)
{
	printf("%.2lf\n", shd("1,1,2,1"));
	printf("%.2lf\n", shd("1,1,3,1"));
	printf("%.2lf\n", shd("-5,1,3,1"));
	printf("%.2lf\n", shd("-5,2,3,1"));
	printf("%.2lf\n", shd("483100,880096,498332,178742"));
	printf("%.2lf\n", shd("26885,682420,385813,481230"));
	printf("%.2lf\n", shd("315460,678240,184384,737905"));
	printf("%.2lf\n", shd("540333,247351,823045,587302"));
	printf("%.2lf\n", shd("834075,628305,148595,700754"));
	printf("%.2lf\n", shd("315460,678240,184384,737905"));
	printf("%.2lf\n", shd("400952,189789,715885,397292"));
	printf("%.2lf\n", shd("789786,557695,480429,46433"));
	printf("%.2lf\n", shd("954482,291709,913515,385161'"));
	printf("%.2lf\n", shd("677296,794660,280956,438719"));
	printf("%.2lf\n", shd("344960,707215,816725,200684"));
	printf("%.2lf\n", shd("346931,739942,581888,910193"));
	printf("%.2lf\n", shd("483317,563372,997431,126527"));
	printf("%.2lf\n", shd("650623,239129,677039,151635"));
	printf("%.2lf\n", shd("804694,424841,432462,420555"));
	printf("%.2lf\n", shd("82254,248165,589831,236960"));
	printf("%.2lf\n", shd("428495,413115,380346,869134"));
	return 0;
}
