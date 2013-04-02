clear all;
close all;
imax = 10;
seikai = exp(1);
y(1) = 1 / factorial(0);
error(1) = abs(seikai - y(1));
theta = 10 ^ (-15);
i = 1;
while error(i) > theta
    i = i + 1;
    y(i) = y(i - 1) + 1 / factorial(i - 1);
    error(i) = abs(seikai - y(i));
end
k = 0 : i - 1;
figure(1);
plot(k, y, 'b', k, error, 'r', [0, i], [seikai, seikai], 'k');
figure(2);
semilogy(k, error, 'r');
format long;
y(i)
seikai
format short;
