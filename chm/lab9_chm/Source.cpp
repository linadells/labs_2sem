#include<iostream>
#include<cmath>
#define n 5
#define m 3
using namespace std;
void createMatr(double matr[][n + 1], int size, double norm[2][n+1]) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matr[i][j] = norm[0][i + j-1];
		}
		matr[i][size] = norm[1][i];
	}
	matr[0][0] = n + 1;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size + 1; j++) {
			printf("%7.2lf ", matr[i][j]);
		}
		cout << endl;
	}
}
void solve(double matr[][n+1], int size, double a[n]) {
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			double c = matr[j][i] / matr[i][i];
			for (int k = i; k <= size; k++)
				matr[j][k] -= c * matr[i][k];
		}
	}

	for (int i = size-1; i >= 0; i--)
	{
		a[i] = matr[i][size] / matr[i][i];
		for (int j = i - 1; j >= 0; j--)
			matr[j][size] -= matr[j][i] * (a[i]);
	}
}
int main() {
	//system("color b5");
	double x[n + 1] =  { 4.03,4.08,4.16,4.23,4.26,4.33 }, y[n + 1] = { 3.01,2.78,2.52,2.42,2.19,1.95 },
		norm[2][n+1] = { 0 }, a1[n], a2[n], a3[n], matr1[n][n+1], matr2[n][n + 1], matr3[n][n + 1];
	cout << "Matrix:\nx:";
	for (int i = 0; i < n + 1; i++) {
		printf("%.2lf ", x[i]);
	}
	cout << "\ny:";
	for (int i = 0; i < n + 1; i++) {
		printf("%.2lf ", y[i]);
	}
	cout << "\n\nNormal matrix:\n";
	for (int i = 0; i < n+1; i++) {
		for (int j = 0; j < n+1; j++) {
			norm[0][i] += pow(x[j], i+1);
		}
		printf("x^%d: %.2lf\n", i+1, norm[0][i]);
	}
	cout << endl;
	for (int i = 0; i < m+1; i++) {
		for (int j = 0; j < n + 1; j++) {
			norm[1][i] += y[j] * pow(x[j], i);
		}
		printf("y^%d: %.2lf\n", i, norm[1][i]);
	}

	cout << "\nMatrix for linear polynom:\n";
	createMatr(matr1, 2, norm);
	solve(matr1, 2, a1);
	printf("\nLinear polynom: %lf + %lf*x\n", a1[0], a1[1]);

	cout << "\nMatrix for square polynom:\n";
	createMatr(matr2, 3, norm);
	solve(matr2, 3, a2);
	printf("\nSquare polynom: %lf + %lf*x + %lf*x^2\n", a2[0], a2[1], a2[2]);


	cout << "\nMatrix for cubic polynom:\n";
	createMatr(matr3, 4, norm);
	solve(matr3, 4, a3);
	printf("\nCubic polynom: %lf + %lf*x + %lf*x^2 + %lf*x^3\n", a3[0], a3[1], a3[2], a3[3]);

	return 0;
}
