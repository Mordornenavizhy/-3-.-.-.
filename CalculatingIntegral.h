#pragma once

#include <cmath>;
class CalculatingIntegral
{
	float a = -0.5;
	float b = 1.58;
	int n = 100 * 100;
	double h = (b - a) / n;
	float e = 2.718;
	float pi = 3.14;
	double x = a; 
	double integral = 0;
	double formula(double x) {
		return (pow(e,(0.3*x*x) )/ (sqrt(2*pi+x)));
	}

public:
	CalculatingIntegral();

	~CalculatingIntegral();

	double metodPrymoygolnikov();

	double metodTrapecii();

	double metodSimpsona();

};
