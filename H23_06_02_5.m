clear all;
close all;

% (1)
A = [1, 2; 3, 4];
b = [2; -1];
A*b
b'*A
inv(A)

% (2)
for i = 1:9
    t(i) = (i - 1) * pi / 4;
    st(i) = sin(t(i));
end
t
st

% (3)
sum = 0;
for i = 100
    sum = sum + i;
end
sum

% (4)
x = [1, 1, 2, 3, 3];
y = [1, 3, 2, 3, 1];
figure(1);
plot(x, y);
figure(2);
plot(x, y); hold on
plot(x, y, '*');
axis([0, 4, 0, 4]);
xlabel('x');
ylabel('y');

% (5)
figure(3);
plot(t, st);
figure(4);
plot(t, st); hold on
plot([0, 7], [0, 0], 'k');
xlabel('k', 'FontSize', 14);
ylabel('sin(kpi/4)', 'FontSize', 14);
