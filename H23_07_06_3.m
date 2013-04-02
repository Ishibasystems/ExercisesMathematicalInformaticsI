clear all
close all
clc

% (i)
fprintf('(i)\n');
n = 10;

2 - (1 / 2) ^ n
2

%(ii)
fprintf('(ii)\n');
n = 100;
s(1) = 1 + 1/2;
for i = 2 : n
    s(i) = s(i - 1) + 1 / (2 ^ i);
end

k = 0 : n - 1;
figure(1);
plot(k, s, 'b');
axis([0, n, 0, 2]);
xlabel('Nomber of iterations n', 'FontSize', 14);
ylabel('S_n', 'FontSize', 14);

format long;
s(10)
2 - (1 / 2) ^ 10
