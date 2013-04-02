clear all;
close all;

% (1-i)
x1 = -10:2:10;
x2 = -10:0.2:10;
i1 = length(x1);
for i = 1:i1
	y1(i) = x1(i) ^ 2 - 2 * x1(i) - 3;
end
i2 = length(x2);
for i = 1:i2
	y2(i) = x2(i) ^ 2 - 2 * x2(i) - 3;
end

figure(1);
plot(x1, y1, '-r', x2, y2, '-b'); hold on
plot([-10, 10], [0, 0], 'k'); hold on
plot([0, 0], [-10, 50], 'k'); hold on
axis([-10, 10, -10, 50]);
legend('10 divisions', '100 divisions')
xlabel('x', 'FontSize', 14);
xlabel('y', 'FontSize', 14);

% (1-ii)
x1 = 0:0.5:5;
x2 = 0:0.05:5;
i1 = length(x1);
for i = 1:i1
	y1(i) = exp(-2 * x1(i)) * cos(10 * x1(i));
end
i2 = length(x2);
for i = 1:i2
	y2(i) = exp(-2 * x2(i)) * cos(10 * x2(i));
end

figure(2);
plot(x1, y1, '-r', x2, y2, '-b'); hold on
% plot([0, 5], [0, 0], 'k'); hold on
% plot([0, 0], [-0.6, 1], 'k'); hold on
axis([0, 5, -0.6, 1]);
legend('10 divisions', '100 divisions')
xlabel('x', 'FontSize', 14);
xlabel('y', 'FontSize', 14);

% (2)
angle = 2 * pi / 3;
Ca = cos(angle);
Sa = sin(angle);
R = [Ca, -Sa; Sa, Ca];
P(:, 1) = [5; 0];
P(:, 2) = R * P(:, 1);
P(:, 3) = R * P(:, 2);

dtheta = 2 * pi /100;
theta = 0:dtheta:2 * pi;
x = 5 * cos(theta);
y = 5 * sin(theta);

figure(3);
plot([P(1, :), P(1, 1)], [P(2, :), P(2, 1)]);
axis square; hold on;
plot(x, y, 'k'); hold on
plot([-6, 6], [0, 0], 'k'); hold on
plot([0, 0], [-6, 6], 'k');
axis([-6, 6, -6, 6]);
