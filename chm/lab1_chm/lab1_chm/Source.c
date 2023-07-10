#include <stdio.h>
#include <math.h>

double func (double x) {
	return x * x * x - 3 * x * x + 6 * x + 3;
}
double funcDif(double x) {
	return 2 * x * x - 6 * x + 6;
}
double funcDif2(double x) {
	return 6 * x  - 6;
}
double gDif(double x) {
	return -x * x / 10 + x / 5 + 0.8;
}
double max(double x, double y) {
	if (x > y) return x;
	else return y;
}
double al(double a, double b) {
	a = max(fabs(funcDif(a)), fabs(funcDif(b)));
}
double g(double x, double a, double b) {
	int k = 1;
	if (funcDif((a + b) / 2) < 0) k = -1;
	return x - (func(x) / (k * al(a, b)));
}
int main() {
	double aTemp, bTemp, x;
	const double a, b, eps;
	int i = 0;
	printf("Enter a, b, eps:");
	scanf_s("%lf %lf %lf", &a, &b, &eps);
	printf("Dichotomy method\n");
	while (func(a) * func(b) > 0) {
		printf("There aren`t any roots of equation. \nEnter a, b, eps:");
		scanf_s("%lf %lf %lf", &a, &b, &eps);
	}
	aTemp = a;
	bTemp = b;
	x = (a+b) / 2;
	while(fabs(func(x)) > eps) {
		if (!func(x)) break;
		if (func(aTemp) * func(x) < 0) {
			bTemp = x;
		}
		else {
			aTemp = x;
		}
		x = (aTemp +bTemp) / 2;
		i++;
	}
	printf("x=%lf i=%i\n", x, i);


	printf("\nChord method\n");
	aTemp = a;
	bTemp = b;
	i = 0;
	if (func(b) * funcDif2(b) < 0) {
		double temp = a;
		aTemp = b;
		bTemp = temp;
	}
	x = aTemp - (func(aTemp) * (bTemp - aTemp)) / (func(bTemp) - func(aTemp));
	while(fabs(func(x)) > eps) {
		x = aTemp - (func(aTemp) * (bTemp - aTemp)) / (func(bTemp) - func(aTemp));
		aTemp = x;
		i++;
	}
	printf("x=%lf i=%i\n", x, i);

	printf("\nNewtons` method\n");
	aTemp = a;
	bTemp = b;
	i = 0;
	if (func(b) * funcDif2(b) < 0) {
		double temp = a;
		aTemp = b;
		bTemp = temp;
	}
	x = aTemp;
	do {
		aTemp = x;
		x = x-func(x)/funcDif(x);
		i++;
	}while (fabs(func(x)) > eps && fabs(x - aTemp) > eps);
	printf("x=%lf i=%i\n", x, i);

	printf("\nIterations method\n");
	aTemp = a;
	bTemp = b;
	i = 0;
	if (max(gDif(aTemp), gDif(bTemp)) > 1) {
		printf("Process is non-convergent on the interval. Enter another a and b:");
		scanf_s("%lf%lf", &aTemp, &bTemp);
	}
	double x0 = (aTemp+bTemp)/2;
	x = x0;
	 do {
		x0 = x;
		x = g(x0, aTemp, bTemp);
		i++;
	 } while (fabs(func(x) - func(x0)) > eps);
	printf("x=%lf i=%i\n", x, i);

	return 0;
}