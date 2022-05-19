#include <stdio.h>
#include <math.h>

void fun(double (*A)[15], double (*B)[15], double (*R)[15], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double a = A[i][j], b = B[i][j];
            R[i][j] = (a == b) ? 1 : 0;
        }
    }
}

void writeMatrixFromUserInput(double (*A)[15], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fflush(stdin);
            scanf("%lf", &(A[i][j]));
        }
    }
}

void printMatrix(double (*A)[15], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%lf ", A[i][j]);
        }
        printf("\n");
    }
}


int main(int argc, char const *argv[])
{
    double A[15][15], B[15][15], R[15][15];
    int n, m;
    printf("Enter the dimensions: ");
    scanf("%d %d", &n, &m);
    printf("Enter the numbers of matrix A: ");
    writeMatrixFromUserInput(A, n, m);
    printf("Enter the numbers of matrix B: ");
    writeMatrixFromUserInput(B, n, m);
    fun(A, B, R, n, m);
    printMatrix(R, n, m);
    return 0;
}
