clear all; close all;
n = 10;
x(1) = 1;
c = 1;
d = 1;
for i = 1 : n
    c = c / i;
    d = 2 * d;
    x(i + 1) = x(i) + c * d;
end
