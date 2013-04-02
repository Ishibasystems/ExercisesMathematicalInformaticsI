% (b)
A(:, :, 1) = [0, 8, 10, 8; 0, -2, 0, 2];
angle = 2 * pi / 5;
figure(1);

for j = 0 : 20
    Ca = cos(angle);
    Sa = sin(angle);
    zCa = cos(pi / 18);
    zSa = sin(pi / 18);
    R = [Ca, -Sa; Sa, Ca];
    A(:, :, 1) = [zCa, -zSa; zSa, zCa] * A(:, :, 1);
    for i = 2 : 5
        A(:, :, i) = R * A(:, :, i - 1);
    end
    
    hold off
    for i = 1 : 5
        fill([A(1, :, i), A(1, 1, i)], [A(2, :, i), A(2, 1, i)], 'g');
        axis square;
        hold on
        axis([-10, 10, -10, 10]);
    end
    M(j + 1) = getframe;
end

movie(M, 1)
