clear all;
close all;
clc;

seikai = pi;
y(1) = 4;
error(1) = abs(seikai - y(1));
theta = 10 ^ (-2);
i = 1;
while error(i) > theta
    i = i + 1;
    y(i) = y(i - 1) + (-1) ^ (i - 1) / (2 * i - 1) * 4;
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
