clear; clc;

% Visualization of 10.6.1
Eactual = csvread('ExplicitBLOCKACTUAL.csv');

Eestimate = csvread('ExplicitBLOCK.csv');
Eerror = csvread('ExplicitERROR.csv');
E8estimate = csvread('Explicit8BLOCK.csv');
E8error = csvread('Explicit8ERROR.csv');


figure(1);
% Actual Plot 
subplot(2,3,1);
mesh(Eactual);
xlim([0 11.5]);
title('Actual');
xlabel('X Value Index');
ylabel('Time Index');
zlabel('U Values');

% Explicit Estimate Plot
subplot(2,3,2);
mesh(Eestimate);
xlim([0 11.5]);
title('Explicit Estimate');
xlabel('X Value Index');
ylabel('Time Index');
zlabel('U Values');

% Explicit Estimate Error
subplot(2,3,3);
mesh(Eerror);
xlim([0 11.5]);
title('Explicit Error');
xlabel('X Value Index');
ylabel('Time Index');
zlabel('% Error');

% Explicit Estimate .8
subplot(2,3,5);
mesh(E8estimate);
xlim([0 11.5]);
title('Explicit .8 Estimate');
xlabel('X Value Index');
ylabel('Time Index');
zlabel('U Values');

% .8 Error
subplot(2,3,6);
mesh(E8error);
xlim([0 11.5]);
title('Explicit .8 ERROR');
xlabel('X Value Index');
ylabel('Time Index');
zlabel('% Error');
