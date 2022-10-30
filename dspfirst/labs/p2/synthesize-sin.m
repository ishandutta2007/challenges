% Ak*cos(2*pi*fk*t + pk) = real part of Xk*exp(j*2*pi*fk*t) where Xk = Ak*exp(j*pk)

function [x, t] = syn_sin(fk, Xk, fs, dur, tstart)
	t = tstart : 1/fs : dur+tstart;
	x = zeros(1, length(t));
	for i = 1:length(fk)
		x += Xk(i)*exp(j*2*pi*fk(i)*t);
	end
end

[x, t] = syn_sin([0, 100, 250], [10, 14*exp(-j*pi/3), 8*j], 10000, 0.1, 0);
[xn, tn] = syn_sin([0.5, 0.5, 0.5], [2, 2*exp(-j*pi*1.25), (1-j)], 10000, 2*pi, -0.5);
subplot(2, 1, 1);
plot(t, real(x));
subplot(2, 1, 2);
plot(tn, real(xn));
pause;
