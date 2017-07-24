clear; clc;

% Visualization of 10.6.2
Eactual = csvread('exact.csv');

Eestimate = csvread('implicitdata.csv');
Eerror = csvread('error.csv');


figure(1);
% Actual Plot 
subplot(3,1,1);
mesh(Eactual);
xlim([0 11.5]);
title('Actual');
xlabel('X Value Index');
ylabel('Time Index');
zlabel('U Values');

% Implicit Estimate Plot
subplot(3,1,2);
mesh(Eestimate);
xlim([0 11.5]);
title('Implicit Estimate');
xlabel('X Value Index');
ylabel('Time Index');
zlabel('U Values');

% Implicit Estimate Error
subplot(3,1,3);
mesh(Eerror);
xlim([0 11.5]);
title('Implicit Error');
xlabel('X Value Index');
ylabel('Time Index');
zlabel('% Error');

