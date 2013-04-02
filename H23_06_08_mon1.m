clear all;
close all;
clc;

% (1)
n = 100;

k = 0;
for i = 1:n
    k = k + i ^ 2;
end
k

k = (2 * n + 1) * (n + 1) * n / 6

k = 0;
for i = 1:n
    k = k + i ^ 3;
end
k

k = ((n + 1) * n / 2) ^ 2

% (2)
r = 2;
n = 8;
angle = 2 * pi / n;
Ca = cos(angle);
Sa = sin(angle);
R = [Ca, -Sa; Sa, Ca];
P(:, 1) = [r; 0];
for i=1:n
    P(:, i + 1) = R * P(:, i);
end
dtheta = 2 * pi /100;
theta = 0:dtheta:2 * pi;
x = r * cos(theta);
y = r * sin(theta);

figure(3);
plot([P(1, :), P(1, 1)], [P(2, :), P(2, 1)]);
axis square; hold on;
plot(x, y, 'k'); hold on
plot([-6, 6], [0, 0], 'k'); hold on
plot([0, 0], [-6, 6], 'k');
axis([-6, 6, -6, 6]);
