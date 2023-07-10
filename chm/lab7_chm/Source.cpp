#include<iostream>
#include<math.h>
using namespace std;
#define eps 0.001

double func1(double x) {
	return -0.5*(sin(x)-2);
}
double func2(double y) {
	return 0.7 - cos(y - 1);
}
double J(double x, double y) {
	return -sin(y - 1) * cos(x) - 2;
}
double X(double x, double y) {
	return -1.0 / J(x, y) * ((sin(x) + 2 * y - 2) * (-sin(y - 1)) - 2 * (cos(y - 1) + x - 0.7));
}
double Y(double x, double y) {
	return -1.0 / J(x, y) * (cos(x) * (cos(y - 1) + x - 0.7) - (sin(x) + 2 * y - 2));
}
int main() {
	double x0 = 0, y0 = 0, x = -0.3, y = 1.1;
	int k = 0;
	cout << "Equation\nsin x + 2y = 2\ncos(y - 1) + x = 0.7\n";
	cout << "\nZero aproximation:\nx=" << x << "\ny=" << y << endl<<"\tx\t   y\nIterations method\n";
	do {
		y0 = y;
		x0 = x;
		printf("%i: % lf  % lf\n", k, x, y);
		y = func1(x0);
		x = func2(y0);
		k++;
	} while (sqrt((y - y0)*(y - y0) + (x - x0)* (x - x0)) > eps);


	cout << "\nNewton method:\n";
	x0 = 0, y0 = 0, x = -0.3, y = 1.1, k = 0;
	cout << "\tx\t   y\n";
	do {
		y0 = y;
		x0 = x;
		printf("%i: % lf  % lf\n", k, x, y);
		x = x0 + X(x0, y0);
		y = y0 + Y(x0, y0);
		k++;
	} while (sqrt((y - y0) * (y - y0) + (x - x0) * (x - x0)) > eps);
	return 0;
}