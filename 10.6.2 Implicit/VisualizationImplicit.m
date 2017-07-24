clear; clc;

% Visualization of 10.6.2
Eactual = csvread('ImplicitBLOCKACTUAL.csv');

Eestimate = csvread('ImplicitBLOCK.csv');
Eerror = csvread('ImplicitERROR.csv');
E8estimate = csvread('Implicit8BLOCK.csv');
E8error = csvread('Implicit8ERROR.csv');


figure(1);
% Actual Plot 
subplot(2,3,1);
mesh(Eactual);
xlim([0 102.5]);
title('Actual');
xlabel('X Value Index');
ylabel('Time Index');
zlabel('U Values');

% Implicit Estimate Plot
subplot(2,3,2);
mesh(Eestimate);
xlim([0 102.5]);
title('Implicit Estimate');
xlabel('X Value Index');
ylabel('Time Index');
zlabel('U Values');

% Implicit Estimate Error
subplot(2,3,3);
mesh(Eerror);
xlim([0 102.5]);
title('Implicit Error');
xlabel('X Value Index');
ylabel('Time Index');
zlabel('% Error');

% Implicit Estimate .8
subplot(2,3,5);
mesh(E8estimate);
xlim([0 11.5]);
title('Implicit .8 Estimate');
xlabel('X Value Index');
ylabel('Time Index');
zlabel('U Values');

% Implicit .8 Error
subplot(2,3,6);
mesh(E8error);
xlim([0 11.5]);
title('Implicit .8 ERROR');
xlabel('X Value Index');
ylabel('Time Index');
zlabel('% Error');
