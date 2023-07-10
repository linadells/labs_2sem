#include<iostream>
#include<cmath>
using namespace std;
double f(double x) {
	return (log(1 + x) / (1 + x + 3 * x * x));
}
int main() {
	double a = 0, b = 2, h, x, i = 0, i2=0, eps, step=10;
	cout << "Function: log(1+x)/(1+x+3*x^2)\nEnter accuracy:";
	cin >> eps;
	cout << "\nMethod of right rectangles\n";
	do {
		i2 = i;
		h = (a + b) / step;
		x = a;
		while (x < b) {
			i += f(x);
			x += h;
		}
		i -= f(a);
		i *= h;
		step *= 2;
	} while ((fabs(i - i2)) > eps || step==20);
	cout << "Integral:" << i << endl << "Step=" << step << endl;

	cout << "\nMethod of left rectangles";
	step = 10;
	do {
		h = (a + b) / step;
		x = a;
		i2 = i;
		i = 0;
		while (x < b - h) {
			i += f(x);
			x += h;
		}
		step *= 2;
		i *= h;
	} while ((fabs(i - i2)) > eps || step == 20);
	cout << "\nIntegral:" << i << endl<<"Step="<< step <<endl;

	cout << "\nMethod of central rectangles\n";
	
	step = 10;
	do {
		h = (a + b) / step;
		i2 = i;
		i = 0;
		x = a + h / 2;
		while (x < b) {
			i += f(x);
			x += h;
		}
		step *= 2;
		i *= h;
	} while ((fabs(i - i2)) > eps || step == 20);
	cout << "Integral:" << i << endl << "Step=" << step << endl;

	cout << "\nMethod of trapeze";
	step = 10;
	do {
		h = (a + b) / step;
		i2 = i;
		x = a;
		i = 0;
		while (x < b - h) {
			x += h;
			i += f(x);
		}
		step *= 2;
		i += (f(a) + f(b)) / 2;
		i *= h;
	} while ((fabs(i - i2)) > eps || step == 20);
	cout << "\nIntegral:" << i << endl << "Step=" << step << endl;

	cout << "\nSimpsons method";
	step = 10;
	do {
		h = (a + b) / step;
		i2 = i;
		x = a;
		i = 0;
		for (int n = 0; n < step; n++) {
			if (!n || n == step) {
				i += f(x);
			}
			else if (n % 2) {
				i += (f(x) * 4);
			}
			else {
				i += (f(x) * 2);
			}
			x += h;
		}
		step *= 2;
		i *= h / 3;
	} while ((fabs(i - i2)) > eps || step == 20);
	cout << "\nIntegral:" << i << endl << "Step=" << step << endl;
	return 0;
}