#include <stdio.h>

double arr_max(double *arr, int len) {
    int m = arr[0];
    for (int i = 1; i < len; i++) {
        if (m < arr[i]) {
            m = arr[i];
        }
    }
    return m;
}

double arr_min(double *arr, int len) {
    int m = arr[0];
    for (int i = 1; i < len; i++) {
        if (m > arr[i]) {
            m = arr[i];
        }
    }
    return m;
}

double arr_avg(double *arr, int len) {
    double S = 0;
    for (int i = 0; i < len; i++) S += arr[i];
    return S/len;
}

int main(int argc, char const *argv[])
{
    FILE* fpr = fopen("readfile.txt", "r");
    FILE* fpw = fopen("writefile.txt", "w+");
    int num, code;
    double pom[4], (*funptr[3])(double *arr, int len), val;
    funptr[1] = arr_max;
    funptr[2] = arr_min;
    funptr[0] = arr_avg;
    while (fscanf(fpr, "%d\n%lf\n%lf\n%lf\n%lf\n%d\n",
    &num, pom, pom+1, pom+2, pom+3, &code) != -1) {
        // printf("%d\n%lf\n%lf\n%lf\n%lf\n%d\n",
        // num, pom[0], pom[1], pom[2], pom[3], code);
        val = (*funptr[code])(pom, 4);
        fprintf(fpw, "%d\n%lf\n%d\n", num, val, code);
        fflush(fpw);
    }
    fclose(fpr);
    fclose(fpw);
    return 0;
}
