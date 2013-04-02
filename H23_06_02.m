clear all
close all

% (1)
A1 = [1, 1; 2, 2];
rank(A1)

% (2)
B1 = [1, 3; 4, -3];
dB1 = det(B1)
[V1, D1] = eig(B1)
D1(2, 2)
V1(:, 2)
error = B1 * V1(:, 2) - D1(2, 2) * V1(:, 2)

% (3)
F1 = [1, 1; 2, -3]
g1 = [3; -4]
X1 = inv(F1) * g1