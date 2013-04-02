% (1)
clear all;
close all;
imax = 5;
sum = 0;
for i = 0 : imax - 1;
    sum = sum + 1 / factorial(i);
end
sum

% (2)
clear all;
close all;
imax = 10;
seikai = exp(1);
y(1) = 1 / factorial(0);
error(1) = abs(seikai - y(1));
for i = 2 : imax;
    y(i) = y(i - 1) + 1 / factorial(i - 1);
    error(i) = abs(seikai - y(i));
end
k = 0 : imax - 1;
figure(1);
plot(k, y, 'b', k, error, 'r', [0, imax], [seikai, seikai], 'k');
figure(2);
semilogy(k, error, 'r');

% (3)
format long;
y(imax)
seikai
format short;
