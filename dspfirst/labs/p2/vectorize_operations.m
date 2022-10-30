% replace loops with vector operations

M = 200;
for k=1:M
	x(k) = k;
	y(k) = cos(0.001*pi*x(k)*x(k));
end
vy = cos(0.001*pi*(1:M).*(1:M));

N = 200;
for k=1:N
	xk(k) = k/50;
	rk(k) = sqrt(xk(k)*xk(k) + 2.25);
	sig(k) = exp(j*2*pi*rk(k));
end
vsig = exp(j*2*pi*sqrt(xk.*xk + 2.25));

subplot(2, 1, 1);
plot(x, y, 'ro-', x, vy, 'bo--');

subplot(2, 1, 2);
plot(xk, real(sig), 'mo-', xk, real(vsig), 'bo--');

pause;
