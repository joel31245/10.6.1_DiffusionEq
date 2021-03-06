clear; clc;

% Visualization of 10.6.1.4 Gauss Method
Eactual = csvread('GaussBLOCKACTUAL.csv');

Eestimate = csvread('GaussBLOCK.csv');
Eerror = csvread('GaussERROR.csv');
% E8estimate = csvread('Gauss8BLOCK.csv');
% E8error = csvread('Gauss8ERROR.csv');


figure(1);
% Actual Plot 
subplot(1,3,1);
mesh(Eactual);
xlim([0 12.5]);
title('Actual');
xlabel('X Value Index');
ylabel('Time Index');
zlabel('U Values');

% Gauss Estimate Plot
subplot(1,3,2);
mesh(Eestimate);
xlim([0 12.5]);
title('Gauss Estimate');
xlabel('X Value Index');
ylabel('Time Index');
zlabel('U Values');

% Gauss Estimate Error
subplot(1,3,3);
mesh(Eerror);
xlim([0 12.5]);
title('Gauss Error');
xlabel('X Value Index');
ylabel('Time Index');
zlabel('% Error');

% % Gauss Estimate .8
% subplot(2,3,5);
% mesh(E8estimate);
% xlim([0 11.5]);
% title('Gauss .8 Estimate');
% xlabel('X Value Index');
% ylabel('Time Index');
% zlabel('U Values');
% 
% % Gauss .8 Error
% subplot(2,3,6);
% mesh(E8error);
% xlim([0 11.5]);
% title('Gauss .8 ERROR');
% xlabel('X Value Index');
% ylabel('Time Index');
% zlabel('% Error');
