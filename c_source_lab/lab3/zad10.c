#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE *fptr_read = fopen("zad10r.txt", "r");
    if (fptr_read == NULL) {
        printf("Loading failed.");
        return 0;
    }

    FILE *fptr_write = fopen("zad10w.txt", "w+");
    if (fptr_write == NULL) {
        printf("Loading failed.");
        return 0;
    }

    char str[100], *pEnd;
    long n1, n2, n3, s;
    fprintf(fptr_write, "SUMA\n");
    while (fgets(str, 100, fptr_read) != NULL) {
        s = 0;
        n1 = strtol(str, &pEnd, 10);
        n2 = strtol(pEnd, &pEnd, 10);
        n3 = strtol(pEnd, NULL, 10);
        s = n1+n2+n3;
        // printf("| %ld | %ld | %ld | %ld\n", n1, n2, n3, s);
        fprintf(fptr_write, "| %ld | %ld | %ld | %ld\n", n1, n2, n3, s);
    }
    fclose(fptr_read);
    fclose(fptr_write);
    return 0;
}