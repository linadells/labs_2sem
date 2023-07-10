#include<stdio.h>
#include<math.h>
#define n 3

float det(float a[n][n], int row, int col) {
	return (a[0][0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * a[2][0] + a[1][0] * a[2][1] * a[0][2] -
		a[0][2] * a[1][1] * a[2][0] - a[1][0] * a[0][1] * a[2][2] - a[2][1] * a[1][2] * a[0][0]);
}
void ind(int i, int* i1, int* i2) {
	if (!i) { *i1 = 1, * i2 = 2; }
	if (i == 1) { *i1 = 0, * i2 = 2; }
	if (i == 2) { *i1 = 0, * i2 = 1; }
}
int main() {
	float a[n][n] = { {94,67,-37}, {67,51,-28}, {-37,-28,16} }, b[n] = {-32, -10,8},/*{ {3.75,-0.28,0.17},{2.11,-0.11,-0.12},{0.22,-3.17,1.81} }, b[n] = { 0.75,1.11,0.05 },*/
		x[n], detA, detK[n], temp[n][n], aOb[n][n];
	int tempI1, tempI2, tempJ1, tempJ2;
	printf("Matrix:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("% .2f ", a[i][j]);
		}
		printf("% .2f\n", b[i]);
	}

	detA = det(a, n, n);
	printf("det A=%f\n", detA);
	if (!detA) printf("Det=0, equation cannot be solved");
	else {
		printf("\nKrammar method:\n");
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					temp[i][j] = a[i][j];
				}
				temp[i][k] = b[i];
			}
			detK[k] = det(temp, n, n);
			x[k] = detK[k] / detA;

			printf("\n%i Matrix:\n", k+1);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					printf("% .2f ", temp[i][j]);
				}
				printf("\n");
			}
			printf("\ndet%i=%f\n", k + 1, x[k]);
		}
		printf("\nx1=%f\nx2=%f\nx3=%f\n", x[0], x[1], x[2]);

		printf("\nMatrix method:\n\n", x[0], x[1], x[2]);
		for (int i = 0; i < n; i++) {
			x[i] = 0;
		}
		printf("Matrix A*:\n");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ind(i, &tempI1, &tempI2);
				ind(j, &tempJ1, &tempJ2);
				int o = 1;
				if ((i + j) % 2) o = -1;
				temp[i][j] = o *( a[tempI1][tempJ1] * a[tempI2][tempJ2] - a[tempI1][tempJ2] * a[tempI2][tempJ1]);
				printf("% .4f ", temp[i][j]);
			}
			printf("\n");
		}
	}
	printf("\nMatrix A~:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			aOb[i][j] = temp[j][i];
			printf("% .4f ", aOb[i][j]);
		}
		printf("\n");
	}
	printf("\nMatrix A^(-1):\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			aOb[i][j] = temp[j][i]/detA;
			x[i] += aOb[i][j] * b[j];
			printf("% .4f ", aOb[i][j]);
		}
		printf("\n");
	}
	printf("\nx1=% f\nx2=% f\nx3=% f\n", x[0], x[1], x[2]);
	return 0;
}