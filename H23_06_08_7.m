clear all;
close all;
clc;

% (1)
a = 1;
b = 1;
c = 1;
D = b ^ 2 - 4 * a * c;
if D > 0
    x1 = (- b + sqrt(D)) / (2 * a)
    x2 = (- b - sqrt(D)) / (2 * a)
elseif D == 0
    x = - b / (2 * a)
else
    fprintf('é¿êîâÇÕÇ†ÇËÇ‹ÇπÇÒ\n');
end

% (2)
clear all;
close all;

n = 65;
k = 1;
for i = 1:n
    if mod(n, i) == 0
        d(k) = i;
        k = k + 1;
    end
end
d
ld = length(d)

% (3)
clear all;
close all;

n = 17;
k = 1;
for i = 1:n
    if mod(n, i) == 0
        d(k) = i;
        k = k + 1;
    end
end
d
ld = length(d)
if ld == 2
    fprintf('%dÇÕëfêîÇ≈Ç†ÇÈ\n', n);
end
