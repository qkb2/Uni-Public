#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Komputer {
    char *nazwa;
    char *producent;
    float cena;
};


void newComputer(struct Komputer *firstEmptyPtr) {
    char name[64], manufactor[64];
    float price;
    printf("Enter product name, manufactor name and price: ");
    scanf("%64s %64s %f", &name, &manufactor, &(firstEmptyPtr->cena));
    firstEmptyPtr->nazwa = (char*) malloc((strlen(name)+1)*sizeof(char)); //alloc memory for a char* str
    firstEmptyPtr->producent = (char*) malloc((strlen(manufactor)+1)*sizeof(char));
    strcpy(firstEmptyPtr->nazwa, name); //str conversion
    strcpy(firstEmptyPtr->producent, manufactor);
}


int getKeyByProdName(struct Komputer * tablicaKomputerow[], int isEmpty[], int arrLen, char *searchedTerm) {
    for (int i = 0; i < arrLen; i++) {
        if (isEmpty[i] == 0 && !strcmp(searchedTerm, tablicaKomputerow[i]->nazwa)) { //strcmp throws 0 if comparison successful
            return i;
        }
    }
    return -1; //if not in array then return -1 (search unsuccessful)
}


int getFirstFreeKey(int isEmpty[], int arrLen) {
    for (int i = 0; i < arrLen; i++) {
        if (isEmpty[i]) {
            isEmpty[i] = 0; //get the first free (1) position key, set it to occupied (0), then return its key
            return i;
        }
    }
    return -1; //if none are free then return -1
}


void delByKey(struct Komputer * tablicaKomputerow[], int key, int isEmpty[]) {
    free(tablicaKomputerow[key]->nazwa);
    free(tablicaKomputerow[key]->producent);
    free(tablicaKomputerow[key]);
    tablicaKomputerow[key] = (struct Komputer *) malloc(sizeof (struct Komputer));
    isEmpty[key] = 1;
}


void allComputers(struct Komputer * tablicaKomputerow[], int isEmpty[], int arrLen) {
    for (int i = 0; i < arrLen; i++) {
        if (!isEmpty[i]) {
            printf("%s\n", tablicaKomputerow[i]->nazwa);
        }
    }
}


void mainLoop(struct Komputer * tablicaKomputerow[], int isEmpty[], int arrLen) {
    char opt, str[64];
    int firstEmpty = 0, x = 0;

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
                x = getFirstFreeKey(isEmpty, arrLen);
                if (x != -1) {
                    newComputer(tablicaKomputerow[x]);
                }
                else
                    printf("Array full.\n");
                break;

            case 'W':
                printf("Pokaz mi swoje towary\n");
                allComputers(tablicaKomputerow, isEmpty, arrLen);
                break;

            case 'S':
                printf("Enter the computer model name: ");
                scanf("%64s", str);
                x = getKeyByProdName(tablicaKomputerow, isEmpty, arrLen, str);
                if (x != -1) {
                    printf("Data about %s: manufactor: %s, price: %f\n", 
                    tablicaKomputerow[x]->nazwa, tablicaKomputerow[x]->producent, tablicaKomputerow[x]->cena);
                }
                else
                    printf("Product not found.\n");
                break;

            case 'U':
                printf("Enter the computer model name: ");
                scanf("%64s", str);
                x = getKeyByProdName(tablicaKomputerow, isEmpty, arrLen, str);
                if (x != -1) {
                    printf("Deleting %s", tablicaKomputerow[x]->nazwa);
                    delByKey(tablicaKomputerow, x, isEmpty);
                }
                else
                    printf("Product not found.\n");
                break;

            default:
                printf("Command unrecognised. Try again\n");
                break;
        }
    }
}


int main() {
    struct Komputer * tablicaKomputerow[100];
    int isEmpty[100];
    for (int i = 0; i < 100; i++) {
        tablicaKomputerow[i] = (struct Komputer *) malloc(sizeof (struct Komputer));
        isEmpty[i] = 1;
    }
    mainLoop(tablicaKomputerow, isEmpty, 100);
}