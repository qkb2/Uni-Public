#include <stdio.h>
#include <math.h>

void fun(double (*A)[50], double (*B)[50], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double x = A[i][j];
            if (x > -1) {
                B[i][j] = (sin(x)*sin(x)-3)/sqrt(x+1);
            }
            else B[i][j] = 3.31;
        }
    }
}

void writeMatrixFromUserInput(double (*A)[50], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fflush(stdin);
            scanf("%lf", &(A[i][j]));
        }
    }
}

void printMatrix(double (*A)[50], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%lf ", A[i][j]);
        }
        printf("\n");
    }
}


int main(int argc, char const *argv[])
{
    double A[50][50], B[50][50];
    int n, m;
    printf("Enter the dimensions: ");
    scanf("%d %d", &n, &m);
    printf("Enter the numbers: ");
    writeMatrixFromUserInput(A, n, m);
    fun(A, B, n, m);
    printMatrix(B, n, m);
    return 0;
}
