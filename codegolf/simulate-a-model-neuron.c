/*

An Izhikevich neuron is a simple yet quite effective model of a biological neuron, designed for use in a discrete time-stepping simulation. In this golfing challenge, you will be implementing this model.

Parameters

This model involves only 7 variables organized into 2 differential equations, compared to the dozens of parameters of a physiologically accurate model.

v and u are the two state variables of the neuron. Here, v is the "fast" variable representing the cell potential over time, and u is the "slow" variable representing certain membrane properties.
The v variable is the most important one, as this is the output of the simulation.

a, b, c, and d are fixed constants that describe the properties of the neuron.
Different types of neurons have different constants, depending on the desired behavior.
Notably, c is the reset potential, which is the membrane potential the cell returns to after spiking.
I represents the input current to the neuron. In network simulations, this will change over time, but for our purposes we will treat I as a fixed constant.

The Model

This model has very simple pseudocode. First, we take the constant values of abcd and use them to initialize v and u:

v = c
u = b * c
Next, we loop through the simulation code as many times as desired. Each iteration represents 1 millisecond of time.

for 1..t:
  if v >= 30:    # reset after a spike
    v = c
    u = u + d
  v += 0.04*v^2 + 5*v + 140 - u + I
  u += a * (b*v - u)
  print v

  Certain real-world implementations include additional steps for numerical accuracy, but we aren't including those here.

Input

As input, your program/function should take the values of a, b, c, d, I, and t (the number of time steps to simulate).
Once set, none of these parameters will be changing during our simple simulation. The order of input does not matter: you can specify the order in which your program takes these parameters.

Output

Output will be a list of numbers representing the cell's membrane potential (given by variable v) over the course of the simulation. The list can be in any appropriate format.

You have the choice of whether to include the 0th value of the simulation (the initial configuration before any time has passed) in your output. For example, for an input of 0.02 0.2 -50 2 10 6 (for a b c d I t), an output of either

-50
-40
-16.04
73.876224
-42.667044096
-25.8262335380956
29.0355029192068
or

-40
-16.04
73.876224
-42.667044096
-25.8262335380956
29.0355029192068
is acceptable.

Your values do not have to be exactly the same as those above, depending on how your language handles floats.

Reference Implementation

Here is a TIO implementation I wrote in Perl to demonstrate the model.
The parameters are that of a "chattering" neuron from the paper linked above, and this serves as a demonstration of how this model is able to recreate some of the more complex properties of neurons, such as alternating between states of high and low activity.
If you look at the output, you can see where the neuron immediately spikes several times, but then waits a while before spiking several more times (despite the cell input voltage I being constant the whole time).

*/

#include <stdio.h>

void
sim(double a, double b, double c, double d, double I, int t)
{
	double u, v;
	int i;

	v = c;
	u = b * c;

	for (i = 0; i <= t; i++) {
		printf("%f\n", v);
		if (v >= 30) {
			v = c;
			u += d;
		}
		v += (0.04 * v * v) + (5 * v) + 140 - u + I;
		u += a * (b * v - u);
	}
}

int
main(void)
{
	sim(0.02, 0.2, -50, 2, 10, 6);
	return 0;
}
