#include<iostream>
#include<math.h>
using namespace std;
#define N 4
double max(double a[], int size) {
	double max = a[0];
	for (int i = 0; i < size; i++) {
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

int main() {
	double a[N][N] = { {0.91,0.23,-0.44,-0.05}, {0.04,0.7,-0.31,0.15},{0.06,0.15, -0.83, -0.17},{0.72, -0.08, -0.05, 1.08} }, 
		b[N] = { 2.13,-0.18,1.44,2.42 }, alp[N][N] = { 0 }, beta[N] = { 0 }, x[N] = { 0 }, x0[N] = { 0 }, eps = 0.001, temp[N]={0}, tmp = 0;
	int m = 0;
	cout << "SLAR:\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("% .2lf x%i ", a[i][j], j+1);
		}
		printf("% .2lf \n", b[i]);
	}
	
	//находження альфа і бета
	for (int i = 0; i < N; i++) {
		beta[i] = b[i] / a[i][i];
		for (int j = 0; j < N; j++) {
			if(i!=j)
				alp[i][j] = -a[i][j] / a[i][i];
		}
	}
	//перевірка збіжності
	cout << "\nMatrix norm:\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i] += fabs(alp[i][j]);
		}
	}
	if (max(temp, N) > 1) {
		m++;
	}
	cout << "1 norm:" << max(temp, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i] += fabs(alp[j][i]);
		}
	}
	if (max(temp, N) > 1) {
		m++;
	}
	cout << "\n2 norm:" << max(temp, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmp += (alp[i][j])* (alp[i][j]);
		}
	}
	if (sqrt(tmp) > 1) {
		m++;
	}
	cout << "\n3 norm:" << sqrt(tmp);
	if(m==3){
		printf("\nMethod is divergent");
		return 0;
	}


	cout << "\n\nIteration method:\n";
	//нульове наближення
	for (int i = 0; i < N; i++) {
		x0[i] = beta[i];
	}
	//знаходження х
	cout << "\nIterations:\n";
	int k = 1;
	while(fabs(x[0]-x0[0])>eps && fabs(x[1] - x0[1]) > eps && fabs(x[2] - x0[2]) > eps && fabs(x[3] - x0[3]) > eps){
		cout << "k=" << k << ":";
		for (int i = 0; i < N; i++) {
			x0[i] = x[i];
			x[i] = beta[i];
			for (int j = 0; j < N; j++) {
				x[i] += alp[i][j]*x0[j];
			}
			cout << "x" << i + 1 << "=" << x[i]<<"\t";
		}
		k++;
		cout << endl;
	}
	cout << "\nSolution:\n";
	for (int i = 0; i < N; i++) {
		cout << "x" <<i+1<<"="<< x[i] << endl;
	}

	//зейдель
	cout << "\nZeidel method:";
	for (int i = 0; i < N; i++) {
		x0[i] = beta[i];
		x[i] = 0;
	}

	//знаходження х
	cout << "\nIterations:\n\n";
	k = 1;
	while (fabs(x[0] - x0[0]) > eps && fabs(x[1] - x0[1]) > eps && fabs(x[2] - x0[2]) > eps && fabs(x[3] - x0[3]) > eps) {
		cout << "k=" << k << ":";
		for (int i = 0; i < N; i++) {
			x0[i] = x[i];
			x[i] = beta[i];
			for (int j = 0; j < N; j++) {
				x[i] += alp[i][j] * x[j];
			}
			cout << "x" << i + 1 << "=" << x[i] << "\t";
		}
		k++;
		cout << endl;
	}
	cout << "\nSolution:\n";
	for (int i = 0; i < N; i++) {
		cout << "x" << i + 1 << "=" << x[i] << endl;
	}
	return 0;
}
