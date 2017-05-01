y = [7.39 54.60 403.43 2980.96];
x = [1 2 3 4];

n = length(y);
logy = log(y); %z = ln(y)

wsp0 = 0;
wsp1 = 0;

z(x) = wsp0 + wsp1*x; %f(x) = z

%f1(x)=(x-x1)/(x0-x1)*f(x0) + (x-x0)/(x1-x0)*f(x1);
iloczynXZ = x .* logy;
wsp1Licznik = n * sum(iloczynXZ) - sum(x)*sum(logy);
wsp1Mianownik = n * sum(x.^2) - (sum(x))^2;
wsp1 = wsp1Licznik/wsp1Mianownik;

sredniaX = mean(x);
sredniaz = mean(logy);

wsp0 = sredniaz - wsp1 * sredniaX;

wspB = wsp1;
wspA = exp(wsp0);
f(x) = wspA * exp(wspB*x);
