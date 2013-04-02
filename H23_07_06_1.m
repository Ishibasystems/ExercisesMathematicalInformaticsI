clear all
close all
clc

A = [2, 0, 1; 0, 2, -1; 1, -1, 1]

[x, y] = size(A);

if (x == y)

    % (i)
    fprintf('(i)\n');
    rank(A)
    det(A)

    % (ii)
    fprintf('(ii)\n');
    [V, D] = eig(A);
    
    V1 = V(:, 1)
    V2 = V(:, 2)
    V3 = V(:, 3)

    D1 = D(1, 1)
    D2 = D(2, 2)
    D3 = D(3, 3)

    % (iii)
    fprintf('(iii)\n');

    for i = 1 : max(x, y)
      error = A * V(:, y) - D(x, y) * V(:, y)
    end
    
    dot(V1, V2)
    dot(V2, V3)
    dot(V3, V1)
    
else
    fprintf('ê≥ï˚çsóÒÇ≈ÇÕÇ†ÇËÇ‹ÇπÇÒ\n');
end
