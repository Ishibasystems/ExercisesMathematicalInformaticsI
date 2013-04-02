clear all;
close all;
clc;

% (v)
a = 3.57;
x(1) = 0.2;
N = 10000;

for k = 2 : N
    x(k) = a * (1 - x(k - 1)) * x(k - 1);
end

k = 1 : N;
figure(1);
plot(k, x, 'b');
axis([0, N, 0, 1]);
xlabel('Nomber of iterations k', 'FontSize', 14);
ylabel('x(k)', 'FontSize', 14);
figure(2);
hist(x, -0.05 : 0.1 : 1.05)
axis([0, 1, 0, 1]);
axis 'auto y'

% (vi)
a = 3.6;
x(1) = 0.2;
N = 10000;

for k = 2 : N
    x(k) = a * (1 - x(k - 1)) * x(k - 1);
end

k = 1 : N;
figure(3);
plot(k, x, 'b');
axis([0, N, 0, 1]);
xlabel('Nomber of iterations k', 'FontSize', 14);
ylabel('x(k)', 'FontSize', 14);
figure(4);
hist(x, -0.05 : 0.1 : 1.05)
axis([0, 1, 0, 1]);
axis 'auto y'
