clear all
close all
clc

% (i)
r = 3;
n = 5;
angle = 2 * pi / n;
Ca = cos(angle);
Sa = sin(angle);
R = [Ca, -Sa; Sa, Ca];
P(:, 1) = [r; 0];

for i = 1 : n
    P(:, i + 1) = R * P(:, i);
end

dtheta = 2 * pi /100;
theta = 0 : dtheta : 2 * pi;
x1 = r * cos(theta);
y1 = r * sin(theta);

figure(1);
plot([P(1, :), P(1, 1)], [P(2, :), P(2, 1)]);
axis square; hold on;
plot(x1, y1, 'k'); hold on
plot([-r, r], [0, 0], 'k'); hold on
plot([0, 0], [-r, r], 'k');
axis([-r, r, -r, r]);

% (ii)
r = r * sin(2 * pi / n) / sin(pi / n) / 2
dtheta = 2 * pi /100;
theta = 0 : dtheta : 2 * pi;
x2 = r * cos(theta);
y2 = r * sin(theta);

figure(1);
plot(x2, y2, 'k'); hold on
