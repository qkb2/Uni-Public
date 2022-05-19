#include <stdio.h>
#define LEN 5
#define STRLEN 100

int countStars(char *str, int len) {
    int i = 0;
    while (i < len && str[i] == '*') i++;
    return i;
}


int main(int argc, char const *argv[])
{
    FILE *fptr_read = fopen("zad7r.txt", "r");
    if (fptr_read == NULL) {
        printf("Loading failed.");
        return 0;
    }

    FILE *fptr_write = fopen("zad7w.txt", "w+");
    if (fptr_write == NULL) {
        printf("Loading failed.");
        return 0;
    }

    char str[STRLEN];
    int c1, c2, i, lastSub[LEN] = {0};
    while (fgets(str, 100, fptr_read) != NULL) {
        c1 = countStars(str, 100);
        // printf("stars: %d\n", c1);
        for (i = 0; i < c1; i++) {
            c2 = lastSub[i];
        }
        for (i; i < LEN; i++) {
            lastSub[i] = 0;
        }
        (lastSub[c1-1])++;

        for (i = 0; i < c1-1; i++) printf(" ", lastSub[i]);
        for (i = 0; i < c1; i++) printf("%d.", lastSub[i]);
        while (i < STRLEN && str[i] != '\0' && str[i] != '\n') {
            printf("%c", str[i]);
            i++;
        }
        printf("\n");
    }


    fclose(fptr_read);
    fclose(fptr_write);
    return 0;
}