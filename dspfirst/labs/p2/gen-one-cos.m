function [x, t] = one_cos(amplitude, frequency, phase, duration)
	t = 0:1/(20*frequency):duration;
	x = amplitude*cos(2*pi*frequency*t + phase);
end

[x, t] = one_cos(95, 100, pi/5, 0.025);
plot(t, x);
pause;
