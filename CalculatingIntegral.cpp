#include "pch.h"
#include "CalculatingIntegral.h"


CalculatingIntegral::CalculatingIntegral() {}

CalculatingIntegral::~CalculatingIntegral() {}


double CalculatingIntegral::metodPrymoygolnikov()//в моем случае я разбил ось абцисс на (b-a)/100*2 чтобы была максимальная точность
{
	while (b >= x) {
		integral += formula(x + h / 2); 
		x += h;
	}
	return h * integral;
}
double CalculatingIntegral::metodTrapecii()
{
	integral += (formula(a) + formula(b)) / 2;
	x = a + h;
	while (b - h >= x) {
		integral += formula(x);
		x += h;
	}
	return h * integral;
}
double CalculatingIntegral::metodSimpsona() {
    if (n % 2 != 0) n++; 
    integral = formula(a) + formula(b);
    x = a + h;
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            integral += 2 * formula(x);
        }
        else {
            integral += 4 * formula(x);
        }
        x += h;
    }
    return h / 3 * integral;
}