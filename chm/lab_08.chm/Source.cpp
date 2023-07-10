#include<iostream>
using namespace std;
#define n 10
int main() {
	double y[n] = { 0.86,0.819,0.779,0.741,0.705,0.67,0.638,0.606,0.577,0.549 },
		x[n] = { 0.15,0.2,0.25,0.3,0.35,0.4,0.45,0.5,0.55,0.6 }, x0 = 0.3119, res = 0,
       p,term, d[n][n] = {0}, prod;
    cout << "x:\ty:\n";
    for (int i = 0;i < n; i++) {
        printf("%.2lf\t%.2lf\n", x[i],y[i]);
    }
    for (int i = 0; i < n; ++i) {
        term = y[i];
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                term *= (x0 - x[j]) / (x[i] - x[j]);
            }
        }
        res += term;
    }
    cout << "\nLagrange method\nResult:" << res<<endl;

    for (int i = 0; i < n; i++) {
        d[i][0] = y[i];
    }
    cout << "\nNewtone method\nFinite differences:\n";
    for (int j = 1; j < n; j++) {
        for (int i = j; i < n; i++) {
            d[i][j] = (d[i][j - 1] - d[i - 1][j - 1]) / (x[i] - x[i - j]);
            printf("% 10.2lf ", d[i][j]);
        }
        cout << endl;
    }
    p = d[0][0];
    prod = 1;
    for (int j = 1; j < n; j++) {
        prod *= (x0 - x[j - 1]);
        p += d[j][j] * prod;
    }
    cout << "\nResult:" << p << endl;
	return 0;
}