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

    printf("Choose formatting option: 1 or 2: ");
    int choice = 1;
    scanf("%d", &choice);
    printf("\n");

    char str[STRLEN];
    int c, x, i, lastSub[LEN] = {0};
    while (fgets(str, 100, fptr_read) != NULL) {
        c = countStars(str, 100);
        // printf("stars: %d\n", c1);
        for (i = c; i < LEN; i++) {
            lastSub[i] = 0;
        }
        x = (lastSub[c-1])++;

        for (i = 0; i < c-1; i++)
            fprintf(fptr_write, "  ", lastSub[i]);
        if (choice != 2)
            for (i = 0; i < c; i++)
                fprintf(fptr_write, "%d.", lastSub[i]);
        else {
            switch (c) {
            case 1:
                fprintf(fptr_write, "%c.", (char) 'A'+x);
                break;
            case 2:
                fprintf(fptr_write, "%d.", x+1);
                break;
            case 3:
                fprintf(fptr_write, "%c.", (char) 'a'+x);
                break;
            case 4:
                fprintf(fptr_write, "(%d)", x+1);
                break;
            case 5:
                fprintf(fptr_write, "(%c)", (char) 'a'+x);
                break;
            default:
                break;
            }
        }
        
        i = c;
        while (i < STRLEN && str[i] != '\0' && str[i] != '\n') {
            fprintf(fptr_write, "%c", str[i]);
            i++;
        }
        fprintf(fptr_write, "\n");
    }

    fclose(fptr_read);
    fclose(fptr_write);
    return 0;
}