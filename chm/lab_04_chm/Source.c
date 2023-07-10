#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define N 3 
void print_matrix(double** A, int row, int col) 
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("% .2lf\t", A[i][j]);
        printf("\n");
    }
}
void swap(double* a, double* b) 
{
    double temp = *a;
    *a = *b;
    *b = temp;
}
float det(float** a) {
    return (a[0][0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * a[2][0] + a[1][0] * a[2][1] * a[0][2] -
        a[0][2] * a[1][1] * a[2][0] - a[1][0] * a[0][1] * a[2][2] - a[2][1] * a[1][2] * a[0][0]);
}
int main()
{
    double c, *y = NULL, sum, *x=NULL, *b=NULL, **A=NULL, **L=NULL, **U=NULL, ** M=NULL;
    int num;
    FILE* file = fopen("in.txt", "r");
    if (!file) {
        printf("Eror eponing file");
        return 0;
    }
    fscanf(file, "%i", &num);
    
    M = (double**)malloc(num * sizeof(double*));
    A = (double**)malloc(num * sizeof(double*));
    L = (double**)malloc(num * sizeof(double*));
    U = (double**)malloc(num * sizeof(double*));
    x= (double*)malloc(num * sizeof(double));
    y = (double*)malloc(num * sizeof(double));
    b = (double*)malloc(num * sizeof(double));
    for (int i = 0; i < num + 1; i++) {
        M[i] = (double*)malloc((num + 1) * sizeof(double));
        A[i] = (double*)malloc((num + 1) * sizeof(double));
    }
    for (int i = 0; i < num; i++) {
        L[i] = (double*)malloc((num + 1) * sizeof(double));
        U[i] = (double*)malloc((num + 1) * sizeof(double));
    }
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num + 1; j++) {
            fscanf(file, "%lf", &M[i][j]);
        }
    }
    if (num == 3) {
        if (!det(M)) {
            printf("Det=0, SLAR can`t be solved");
            return 0;
        }
    }
        printf("Hayse method:\n\nMatrix:\n");

            for (int i = 0; i < num; i++) {
                for (int j = 0; j < num + 1; j++) {
                    A[i][j] = M[i][j];
                }
            }
        print_matrix(A, num, num + 1);

            for (int i = 0; i < num; i++)
            {
                for (int j = i + 1; j < num; j++)
                {
                    c = A[j][i] / A[i][i];
                    for (int k = i; k <= num; k++)
                        A[j][k] -= c * A[i][k];
                }
            }

        printf("\nTriangle matrix:\n");
        print_matrix(A, num, num + 1);

        for (int i = num - 1; i >= 0; i--)
        {
            x[i] = A[i][num] / A[i][i];
            for (int j = i - 1; j >= 0; j--)
                A[j][num] -= A[j][i] * x[i];
        }

        printf("\nSolution of the system:\n");
        for (int i = 0; i < num; i++)
            printf("x%d = % lf\n", i + 1, x[i]);

        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num + 1; j++) {
                U[i][j] = M[i][j];
                L[i][j] = 0;
            }
            L[i][i] = 1;
            b[i] = M[i][num];
        }
        printf("\nMethod LU-decomposition of matrix:\n");
        for (int i = 0; i < num; i++)
        {
            for (int j = i + 1; j < num; j++)
            {
                c = U[j][i] / U[i][i];
                for (int k = i; k <= num; k++)
                    U[j][k] -= c * U[i][k];
                L[j][i] = c;
            }
        }
        printf("\nMatrix L:\n");
        print_matrix(L, num, num);
        printf("\nMatrix U:\n");
        print_matrix(U, num, num);
        for (int i = 0; i < num; i++)
        {
            y[i] = b[i];
            for (int j = i + 1; j < num; j++)
                b[j] -= L[j][i] * y[i];
        }
        printf("\nY:\n");
        for (int i = 0; i < num; i++)
            printf("y%d = % lf\n", i + 1, y[i]);
        for (int i = num - 1; i >= 0; i--)
        {
            x[i] = y[i] / U[i][i];
            for (int j = i - 1; j >= 0; j--)
                y[j] -= U[j][i] * x[i];
        }

        printf("\nSolution of the system:\n");
        for (int i = 0; i < num; i++)
            printf("x%d = % lf\n", i + 1, x[i]);
        fclose(file);     
    
    return 0; 
}
