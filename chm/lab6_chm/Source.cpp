#include<iostream>
#include<cmath>
using namespace std;
#define N 3
#define M 5

int main() {
	double a[M][N] = {{2,2,-1}, {4,3,-1}, {8,5,-3},{3,3,-2},{1,2,-1}},
		b[M] = {-2,-1,-3,-4,12/*-3*/}, nA[N][N] = {0}, C[N] = {0},
		l[N][N] = { 0 }, x[N] = { 0 }, y[N] = { 0 };
	cout << "Matrix:\n"; 
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			printf("% 06.2lf ", a[i][j]);
		}
		printf("  % 06.2lf \n", b[i]);
	}
	cout << "\nNorm matrix:\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				nA[i][j] += a[k][i] * a[k][j];
				if(j==N-1)
					C[i] += a[k][i] * b[k];
			}
			printf("% 06.2lf ", nA[i][j]);
		}
		printf("  % 06.2lf\n", C[i]);
	}

	l[0][0] = sqrt(nA[0][0]);
	l[1][0] = nA[1][0] / l[0][0];
	l[2][0] = nA[2][0] / l[0][0];
	l[1][1] = sqrt(nA[1][1] - pow(l[1][0], 2));
	l[2][1] = (nA[2][1] - l[2][0] * l[1][0]) / l[1][1];
	l[2][2] = sqrt(nA[2][2] - pow(l[2][0], 2) - pow(l[2][1], 2));

	cout << "\nMatrix LY=C:" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("% 06.2lf ", l[i][j]);
		}
		printf("  % 06.2lf\n", C[i]);
	}

	for (int i = 0; i < N; i++)
	{
		y[i] = C[i]/l[i][i];
		for (int j = i + 1; j < N; j++)
			C[j] -= l[j][i] * y[i];
	}
	cout << "\nY:\n";
	for (int i = 0; i < N; i++)
		printf("y%d =% 06.2lf \n", i + 1, y[i]);

	cout << "\nMatrix L(t)X=Y:" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("% 06.2lf ", l[j][i]);
		}
		printf("  % 06.2lf\n", y[i]);
	}

	for (int i = N - 1; i >= 0; i--)
	{
		x[i] = y[i] / l[i][i];
		for (int j = i - 1; j >= 0; j--)
			y[j] -= l[i][j] * x[i];
	}


	cout<<"\nSolution of the system:\n";
	for (int i = 0; i < N; i++)
		printf("x%d =% 06.2lf \n", i + 1, x[i]);

	cout << "\nCalculation eror:\n";
	double error[M] = { 0 };
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			error[i] += x[j] * a[i][j];
		}
		error[i] -= b[i];
		error[i] = fabs(error[i]);
		printf("error %d =% 06.2lf \n", i + 1, error[i]);
	}
	return 0;
}

