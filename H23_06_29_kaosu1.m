clear all;
close all;
clc;

% (i)
a = 0.7;
x(1) = 0.2;
N = 100;

for k = 2 : N
    x(k) = a * (1 - x(k - 1)) * x(k - 1);
end

k = 1 : N;
figure(1);
plot(k, x, 'b');
axis([0, N, 0, 1]);
xlabel('Nomber of iterations k', 'FontSize', 14);
ylabel('x(k)', 'FontSize', 14);

% (ii)
a = 1.7;
x(1) = 0.2;
N = 100;

for k = 2 : N
    x(k) = a * (1 - x(k - 1)) * x(k - 1);
end

k = 1 : N;
figure(2);
plot(k, x, 'b');
axis([0, N, 0, 1]);
xlabel('Nomber of iterations k', 'FontSize', 14);
ylabel('x(k)', 'FontSize', 14);

% (iii)
a = 2.7;
x(1) = 0.2;
N = 100;

for k = 2 : N
    x(k) = a * (1 - x(k - 1)) * x(k - 1);
end

k = 1 : N;
figure(3);
plot(k, x, 'b');
axis([0, N, 0, 1]);
xlabel('Nomber of iterations k', 'FontSize', 14);
ylabel('x(k)', 'FontSize', 14);

% (iv)
a = 3.2;
x(1) = 0.2;
N = 100;

for k = 2 : N
    x(k) = a * (1 - x(k - 1)) * x(k - 1);
end

k = 1 : N;
figure(4);
plot(k, x, 'b');
axis([0, N, 0, 1]);
xlabel('Nomber of iterations k', 'FontSize', 14);
ylabel('x(k)', 'FontSize', 14);

% (v)
a = 3.57;
x(1) = 0.2;
N = 100;

for k = 2 : N
    x(k) = a * (1 - x(k - 1)) * x(k - 1);
end

k = 1 : N;
figure(5);
plot(k, x, 'b');
axis([0, N, 0, 1]);
xlabel('Nomber of iterations k', 'FontSize', 14);
ylabel('x(k)', 'FontSize', 14);

% (vi)
a = 3.6;
x(1) = 0.2;
N = 100;

for k = 2 : N
    x(k) = a * (1 - x(k - 1)) * x(k - 1);
end

k = 1 : N;
figure(6);
plot(k, x, 'b');
axis([0, N, 0, 1]);
xlabel('Nomber of iterations k', 'FontSize', 14);
ylabel('x(k)', 'FontSize', 14);