% play a sine wave at 2000hz with 11025 samples/sec for 0.9 seconds
fs = 11025;
f = 2000;
duration = 0.9;
t = 0:(1/fs):duration;
x = sin(2*pi*f*t);
soundsc(x, fs);
