f = 4000;
T = 2 * 1/f;

A1 = 2;
A2 = 1.25 * A1;
tm1 = 2;
tm2 = 30;

t = -T:T/25:T;
x1 = A1*cos(2*pi*f*(t - tm1));
x2 = A2*cos(2*pi*f*(t - tm2));
x3 = x1 + x2;

subplot(3, 1, 1)
plot(t, x1)

subplot(3, 1, 2)
plot(t, x2)

subplot(3, 1, 3)
plot(t, x3)

pause;
