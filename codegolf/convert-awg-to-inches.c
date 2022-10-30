/*

AWG (American Wire Gauge) is a common way of specifying wire sizes. Your task in this challenge is to convert from a given gauge to the diameter of the wire in inches.

The size in inches for the gauges from 4/0 to 40 are shown in the table below:

Gauge to inches table
| AWG | Diameter (Inches) |
|-----|-------------------|
| 4/0 | 0.46              |
| 3/0 | 0.4096            |
| 2/0 | 0.3648            |
| 1/0 | 0.3249            |
| 1   | 0.2893            |
| 2   | 0.2576            |
| 3   | 0.2294            |
| 4   | 0.2043            |
| 5   | 0.1819            |
| 6   | 0.162             |
| 7   | 0.1443            |
| 8   | 0.1285            |
| 9   | 0.1144            |
| 10  | 0.1019            |
| 11  | 0.0907            |
| 12  | 0.0808            |
| 13  | 0.072             |
| 14  | 0.0641            |
| 15  | 0.0571            |
| 16  | 0.0508            |
| 17  | 0.0453            |
| 18  | 0.0403            |
| 19  | 0.0359            |
| 20  | 0.032             |
| 21  | 0.0285            |
| 22  | 0.0253            |
| 23  | 0.0226            |
| 24  | 0.0201            |
| 25  | 0.0179            |
| 26  | 0.0159            |
| 27  | 0.0142            |
| 28  | 0.0126            |
| 29  | 0.0113            |
| 30  | 0.01              |
| 31  | 0.00893           |
| 32  | 0.00795           |
| 33  | 0.00708           |
| 34  | 0.0063            |
| 35  | 0.00561           |
| 36  | 0.005             |
| 37  | 0.00445           |
| 38  | 0.00397           |
| 39  | 0.00353           |
| 40  | 0.00314           |

Clarifications

For gauges less than 0, you can take the input as either 3/0 or 000
You only have to support from the given 4/0 to 40
The Wikipedia page has some helpful formulas you can try to use if you don't want to hardcode everything
Output your answers to at least 3 sig-figs
This code-golf, so shortest code in bytes wins!

*/

#include <stdio.h>
#include <math.h>

// https://www.powerstream.com/Wire_Size.htm
double
awg2inches(double awg)
{
	return .005 * pow(92, (36 - awg) / 39);
}

int
main(void)
{
	int i;

	for (i = -4; i <= 40; i++)
		printf("%2d %.06f\n", i, awg2inches(i));
	return 0;
}
