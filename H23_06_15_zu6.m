% (a)
clear all;
close all;
A = [0, 8, 10, 8; 0, -2, 0, 2];
figure(1);
plot([A(1, :), A(1, 1)], [A(2, :), A(2, 1)]);
axis square;
axis([-10, 10, -10, 10]);

% (b)
A(:, :, 1) = [0, 8, 10, 8; 0, -2, 0, 2];
angle = 2 * pi / 5;
Ca = cos(angle);
Sa = sin(angle);
R = [Ca, -Sa; Sa, Ca];
for i = 2 : 5
    A(:, :, i) = R * A(:, :, i - 1);
end
figure(2);
for i = 1 : 5
    fill([A(1, :, i), A(1, 1, i)], [A(2, :, i), A(2, 1, i)], 'g');
    axis square;
    hold on
    axis([-10, 10, -10, 10]);
end
