% scalar operations
pi*pi - 10
sin(pi/4)
% ans holds the last result
ans^2

x = sin(pi/5)
cos(pi/5)
y = sqrt(1 - x*x)
ans

% complex operations
z = 3 + 4i, w = -3 + 4j
real(z), imag(z)
% vector constructor
abs([z, w])
conj(z + w)
angle(z)
exp(j*pi)
exp(j*[pi/4, 0, -pi/4])

% arrays
jkl = 0:6
jkl = 2:4:17
jkl = 99:-1:88
ttt = 2:1/9:4
tpi = pi*[0:0.1:2]

% array indexing
% concatenation
xx = [zeros(1, 3), linspace(0, 1, 5), ones(1, 4)]
xx(4:6)
size(xx)
length(xx)
xx(2:2:length(xx))

yy = [];
for k=-5:5
	yy(k+6) = cos(k*pi/3);
end
yy

% plotting
x = [-3 1 0 1 3]
y = x.*x - 3*x
z = x+y*sqrt(-1)

plot(x, y)
pause;
% plots real vs imag
plot(z)
pause;
