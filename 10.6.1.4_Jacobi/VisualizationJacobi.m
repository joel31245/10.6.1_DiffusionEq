clear; clc;

% Visualization of 10.6.1.4 Jacobi Method
Eactual = csvread('JacobiBLOCKACTUAL.csv');

Eestimate = csvread('JacobiBLOCK.csv');
Eerror = csvread('JacobiERROR.csv');
E8estimate = csvread('Jacobi8BLOCK.csv');
E8error = csvread('Jacobi8ERROR.csv');


figure(1);
% Actual Plot 
subplot(2,3,1);
mesh(Eactual);
xlim([0 12.5]);
title('Actual');
xlabel('X Value Index');
ylabel('Time Index');
zlabel('U Values');

% Jacobi Estimate Plot
subplot(2,3,2);
mesh(Eestimate);
xlim([0 12.5]);
title('Jacobi Estimate');
xlabel('X Value Index');
ylabel('Time Index');
zlabel('U Values');

% Jacobi Estimate Error
subplot(2,3,3);
mesh(Eerror);
xlim([0 12.5]);
title('Jacobi Error');
xlabel('X Value Index');
ylabel('Time Index');
zlabel('% Error');

% Jacobi Estimate .8
subplot(2,3,5);
mesh(E8estimate);
xlim([0 11.5]);
title('Jacobi .8 Estimate');
xlabel('X Value Index');
ylabel('Time Index');
zlabel('U Values');

% Jacobi .8 Error
subplot(2,3,6);
mesh(E8error);
xlim([0 11.5]);
title('Jacobi .8 ERROR');
xlabel('X Value Index');
ylabel('Time Index');
zlabel('% Error');
