clear all;
close all;
clc;

% (v)
a = 3.57;
x(1) = 0.2;
y(1) = x(1) + 0.001;
z(1) = y(1) + 0.001;
N = 100;

for k = 2 : N
    x(k) = a * (1 - x(k - 1)) * x(k - 1);
    y(k) = a * (1 - y(k - 1)) * y(k - 1);
    z(k) = a * (1 - z(k - 1)) * z(k - 1);
end

k = 1 : N;
figure(1);
plot(k, z, 'b', k, y, 'g', k, x, 'r');
axis([0, N, 0, 1]);
xlabel('Nomber of iterations k', 'FontSize', 14);
ylabel('x(k)', 'FontSize', 14);

% (vi)
a = 3.6;
x(1) = 0.2;
y(1) = x(1) + 0.001;
z(1) = y(1) + 0.001;
N = 100;

for k = 2 : N
    x(k) = a * (1 - x(k - 1)) * x(k - 1);
    y(k) = a * (1 - y(k - 1)) * y(k - 1);
    z(k) = a * (1 - z(k - 1)) * z(k - 1);
end

k = 1 : N;
figure(2);
plot(k, z, 'b', k, y, 'g', k, x, 'r');
axis([0, N, 0, 1]);
xlabel('Nomber of iterations k', 'FontSize', 14);
ylabel('x(k)', 'FontSize', 14);