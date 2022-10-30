t = -1:0.01:1;
x = cos(5*pi*t);
z = 1.4*exp(j*pi/2)*exp(j*5*pi*t);

% plot x and z together using blue and red colors with dotted and solid lines
plot(t, x, 'b-', t, real(z), 'r--'), grid on
title('Test plot of sinusoid');
xlabel('TIME (sec)');
pause;
