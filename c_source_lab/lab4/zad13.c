#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char *nazwisko;
    char *imie;
    char *nrAlbumu;
} student;

typedef struct Grade {
    char *nrAlbumu;
    char *ocena;
} grade;

int searchByIndex(char *id, grade *gr, int len, char* grade) {
    for (int i = 0; i < len; i++) {
        if (strcmp(id, gr[i].nrAlbumu) == 0) {
            strcpy(grade, gr[i].ocena);
            return 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    student students[50];
    grade programowanie[50], fizyka[50];
    FILE* fstud = fopen("Studenci.txt", "r");
    FILE* fprog = fopen("Programowanie.txt", "r");
    FILE* ffiz = fopen("Fizyka.txt", "r");
    int i, N, M, K;
    char buff1[20], buff2[20], buff3[20];
    fscanf(fstud, "%d\n", &N);
    fscanf(fprog, "%d\n", &M);
    fscanf(ffiz, "%d\n", &K);
    // printf("test %d %d %d", N, M, K);
    for (i = 0; i < N; i++) {
        // printf("test %d", i);
        fscanf(fstud, "%s\n%s\n%s\n",
        buff1, buff2, buff3);
        // printf("%s", buff2);
        students[i].nazwisko = (char*) malloc((strlen(buff1)+1)*sizeof(char)); //alloc memory for a char* str
        students[i].imie = (char*) malloc((strlen(buff2)+1)*sizeof(char));
        students[i].nrAlbumu = (char*) malloc((strlen(buff3)+1)*sizeof(char));
        strcpy(students[i].nazwisko, buff1); //str conversion
        strcpy(students[i].imie, buff2);
        strcpy(students[i].nrAlbumu, buff3);
    }
    
    for (i = 0; i < M; i++) {
        fscanf(fprog, "%s\n%s\n",
        buff1, buff2);
        programowanie[i].nrAlbumu = (char*) malloc((strlen(buff1)+1)*sizeof(char));
        programowanie[i].ocena = (char*) malloc((strlen(buff2)+1)*sizeof(char));
        strcpy(programowanie[i].nrAlbumu, buff1);
        strcpy(programowanie[i].ocena, buff2);
        // printf("%s", programowanie[i].ocena);
    }

    for (i = 0; i < M; i++) {
        fscanf(ffiz, "%s\n%s\n",
        buff1, buff2);
        fizyka[i].nrAlbumu = (char*) malloc((strlen(buff1)+1)*sizeof(char));
        fizyka[i].ocena = (char*) malloc((strlen(buff2)+1)*sizeof(char));
        strcpy(fizyka[i].nrAlbumu, buff1);
        strcpy(fizyka[i].ocena, buff2);
    }

    fflush(stdin);
    char c = getchar();
    int flag = 0;
    while (c != 'Q') {
        if (c == 'N') {
            scanf("%s", buff1);
            for (i = 0; i < N; i++) {
                if (strcmp(buff1, students[i].nazwisko) == 0) {
                    printf("Imie: %s\nNazwisko: %s\nNr albumu: %s\n",
                    students[i].imie, students[i].nazwisko, students[i].nrAlbumu);
                    flag = searchByIndex(students[i].nrAlbumu, programowanie, M, buff2);
                    if (flag == 1)
                        printf("Ocena z programowania: %s\n", buff2);
                    flag = searchByIndex(students[i].nrAlbumu, fizyka, K, buff2);
                    if (flag == 1)
                        printf("Ocena z fizyki: %s\n", buff2);
                }
            }
        }
        else if (c == 'A') {
            scanf("%s", buff1);
            for (i = 0; i < N; i++) {
                if (strcmp(buff1, students[i].nrAlbumu) == 0) {
                    printf("Imie: %s\nNazwisko: %s\nNr albumu: %s\n",
                    students[i].imie, students[i].nazwisko, students[i].nrAlbumu);
                    flag = searchByIndex(buff1, programowanie, M, buff2);
                    if (flag == 1)
                        printf("Ocena z programowania: %s\n", buff2);
                    flag = searchByIndex(buff1, fizyka, K, buff2);
                    if (flag == 1)
                        printf("Ocena z fizyki: %s\n", buff2);
                    break;
                }
            }
        }
        c = getchar();
    }


    fclose(fstud);
    fclose(fprog);
    fclose(ffiz);
    return 0;
}
