#include <stdio.h>


struct Towar {
    char nazwaTowaru[64];
    int liczbaSztuk;
    float cenaSztuki;
};


void mainLoop(struct Towar tablicaTowarow[], int arrLen) {
    char opt;
    int firstEmpty = 0;
    float sum = 0;

    while (1) {
        printf("Choose an option: ");
        fflush(stdin);
        scanf("%c", &opt);

        if (opt > 'Z') 
            opt += 'A'-'a';

        switch (opt) {
            case 'Q':
                printf("Quitting...");
                return;
            
            case 'N':
                if (firstEmpty < arrLen) {
                    printf("Enter product name, product amount and product value: ");
                    scanf("%s %d %f", &(tablicaTowarow[firstEmpty].nazwaTowaru), 
                    &(tablicaTowarow[firstEmpty].liczbaSztuk), &(tablicaTowarow[firstEmpty].cenaSztuki));
                    sum += tablicaTowarow[firstEmpty].cenaSztuki*tablicaTowarow[firstEmpty].liczbaSztuk;
                    firstEmpty++;
                }
                    
                else
                    printf("Array full.\n");
                
                break;

            case 'W':
                printf("Pokaz mi swoje towary\n");
                for (int i = 0; i < firstEmpty; i++)
                    printf("Towar %d: %s\n", i, tablicaTowarow[i].nazwaTowaru);
                break;

            case 'R':
                printf("Sum: %f\n", sum);
                break;

            default:
                printf("Command unrecognised. Try again\n");
                break;
        }
    }
}



int main(int argc, char const *argv[])
{
    struct Towar tablicaTowarow[50];
    mainLoop(tablicaTowarow, sizeof tablicaTowarow / sizeof (struct Towar));
    return 0;
}
