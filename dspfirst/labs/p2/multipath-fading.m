function delay = time_delay_direct(transmitter, vehicle)
	delay = norm(vehicle - transmitter, 2) / 3e8;
end

function delay = time_delay_reflected(transmitter, reflector, vehicle)
	delay = time_delay_direct(transmitter, reflector) + time_delay_direct(reflector, vehicle);
end

function x = signal(amplitude, frequency, phase, transmitter, reflector, vehicle, t)
	t1 = time_delay_direct(transmitter, vehicle);
	t2 = time_delay_reflected(transmitter, reflector, vehicle);
	x = amplitude*cos(2*pi*frequency*(t - t1) + phase) - amplitude*cos(2*pi*frequency*(t - t2) + phase);
end

amplitude = 1;
phase = 0;
frequency = 3;
transmitter = [0, 1500];
reflector = [100, 900];
vehicle = 0;
t = 0:1/(100*frequency):2*pi;
for i = 1:length(t)
	x(i) = signal(amplitude, frequency, phase, transmitter, reflector, vehicle, t(i));
end
plot(t, x);
pause;
