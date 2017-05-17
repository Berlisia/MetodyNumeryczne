y = [7.39 54.60 403.43 2980.96];
x = [1 2 3 4];

n = length(y);
logy = log(y); %z = ln(y)

%z(x) = wsp0 + wsp1*x; %f(x) = z

%f1(x)=(x-x1)/(x0-x1)*f(x0) + (x-x0)/(x1-x0)*f(x1);
iloczynXZ = x .* logy;
wsp1Licznik = n * sum(iloczynXZ) - sum(x)*sum(logy);
wsp1Mianownik = n * sum(x.^2) - (sum(x))^2;
wsp1 = wsp1Licznik/wsp1Mianownik;

sredniaX = mean(x);
sredniaz = mean(logy);
wsp0 = sredniaz - (wsp1 * sredniaX);
wspA = exp(wsp0);
wspB = wsp1;
f(x) = wspA * exp(wspB*x);

%Dok³adnoœæ regresji
logf = log(f); %przjescie na skale logarytmiczna
sredniaY = mean(logf);

roznicay = logf - sredniaY;
roznicay2 = roznicay.^2;
St = sum(roznicay2);
Sy = (St/(n-1))^(1/2);
roznicaDlaSr = logf - wsp0 - wsp1 .* x;
Sr = sum((roznicaDlaSr).^2);
Syx = (Sr/(n-2))^(1/2);

%wspó³czynnik korelacji
r = abs(((St - Sr)/St)^(1/2));


