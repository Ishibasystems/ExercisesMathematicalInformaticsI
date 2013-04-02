clear all;
close all;
clc;

m = 90;
n = 40;

for i = 1 : min(m, n)
    d(i) = 0;
    if mod(min(m, n), i) == 0
        d(i) = 1;
    end
end

k = 1;

for i = 1 : min(m, n)
    if d(i) == 1
        if mod(max(m, n), i) == 0
            ans(k) = i;
            k = k + 1;
        end
    end
end

ans

if k == 2
    fprintf('m‚Æn‚ÍŒÝ‚¢‚É‘f‚Å‚ ‚é\n');
end
