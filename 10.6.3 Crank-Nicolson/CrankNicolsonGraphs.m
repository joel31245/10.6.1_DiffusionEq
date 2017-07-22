clear; clc;

% Visualization of 10.6.3
Eactual = csvread('CNBLOCKACTUAL.csv');

Eestimate = csvread('CNBLOCK.csv');
Eerror = csvread('CNERROR.csv');
E8estimate = csvread('CN8BLOCK.csv');
E8error = csvread('CN8ERROR.csv');


figure(1);
% Actual Plot 
subplot(2,3,1);
mesh(Eactual);
xlim([0 11.5]);
title('Actual');
xlabel('X Value Index');
ylabel('Time Index');
zlabel('U Values');

% CN Estimate Plot
subplot(2,3,2);
mesh(Eestimate);
xlim([0 11.5]);
title('Crank-Nicolson Estimate');
xlabel('X Value Index');
ylabel('Time Index');
zlabel('U Values');

% CN Estimate Error
subplot(2,3,3);
mesh(Eerror);
xlim([0 11.5]);
title('Crank-Nicolson Error');
xlabel('X Value Index');
ylabel('Time Index');
zlabel('% Error');

% CN Estimate .8
subplot(2,3,5);
mesh(E8estimate);
xlim([0 11.5]);
title('Crank-Nicolson .8 Estimate');
xlabel('X Value Index');
ylabel('Time Index');
zlabel('U Values');

% CN .8 Error
subplot(2,3,6);
mesh(E8error);
xlim([0 11.5]);
title('Crank-Nicolson .8 ERROR');
xlabel('X Value Index');
ylabel('Time Index');
zlabel('% Error');
