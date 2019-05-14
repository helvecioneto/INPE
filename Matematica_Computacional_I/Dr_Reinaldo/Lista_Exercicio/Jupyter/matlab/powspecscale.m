function [beta,x] = powspecscale(x, pflag)
% beta = powspecscale(x, pflag) calculates the power spectral density, 
% S(f), scaling coefficient, beta, satisfying S(f) ~ f^{-beta}. 
% A Welch window is used to reduce spectral leakage. 
% The bin size is given by the distance between the first two points. 
% A log-log plot of S(f) against f is provided when pflag=1.  Default: plag=0.
% Copyright (c) 2005 Patrick E. McSharry (patrick@mcsharry.net)
     
if nargin < 2 
   pflag = 0;
end

N = length(x);

% Ensure data has a mean of zero
x = x - mean(x);

% Welch window 
w = 1 - (([1:N]' - N/2)/(N/2)).^2;
Wss = mean(w.^2);

% calculate the spectrum 
k = N/2;
s0 = (1/Wss)*(2/N)*abs(fft(w.*x)).^2;
s = s0(1:k);
f = [1:k]'/N; 
lf = log10(f);
S = log10(s);

% estimate bin size as distance between first two points on log frequency scale 
lf1 = log10(f(1));
lf2 = log10(f(2));
lfk = log10(f(k));
dlfb = lf2 - lf1;

% bin the data 
lfrange = lfk - lf1;
Nlfb = ceil(lfrange/dlfb);
lfb = lf1-0.5*dlfb + [1:Nlfb]*dlfb;

ind = find( (lfb(1)-0.5*dlfb <= lf) & (lf <= lfb(1)+0.5*dlfb) );
nind(1) = length(ind);
Slfb(1) = mean(S(ind));     
for i=2:Nlfb-1
   ind = find( (lfb(i)-0.5*dlfb < lf) & (lf <= lfb(i)+0.5*dlfb) );
   nind(i) = length(ind);
   Slfb(i) = mean(S(ind));     
end 
ind = find( (lfb(Nlfb)-0.5*dlfb < lf));
nind(Nlfb) = length(ind);
Slfb(Nlfb) = mean(S(ind));     

% fit a line to the log-log plot
A = ones(Nlfb,2);
A(:,2) = lfb';
a = pinv(A)*Slfb';
Slfbpred = A*a;

if pflag == 1
%figure;
%subplot(2,1,1)
%plot(x)
%xlabel('t')
%ylabel('f(t)')
%title('Serie')
%subplot(2,1,2)
loglog(f,s,'k.-');
hold on;
loglog(10.^lfb, 10.^Slfb,'k.','MarkerSize',14);
loglog(10.^[lfb(1) lfb(Nlfb)], 10.^[Slfbpred(1) Slfbpred(Nlfb)],'k');
xlabel('frequency (Hz)','FontSize',14);
ylabel('PSD[|sfu|^2/Hz]','FontSize',14);
hold off;
title(['S(f) ~ f^{-\alpha} with \alpha = ' num2str(-a(2)) ]);
end

beta = - a(2);
