#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fptr = fopen("loremipsum.txt", "r");
    if (fptr == NULL) {
        printf("Loading failed.");
        return 0;
    }
    char s;
    scanf("%c", &s);
    int c = getc(fptr), sum = 0;
    while (c != EOF) {
        if (s == c) 
            sum += 1;
        c = getc(fptr);
    }
    fclose(fptr);
    printf("%c was found %d times in a file.", s, sum);
    return 0;
}
