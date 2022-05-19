#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int amount;
    int sum;
    struct Node *next;
} node;

node * insert(node* last) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->sum = 0;
    new_node->amount = 0;
    new_node->next = NULL;
    last->next = new_node;
    return new_node;
}

int main(int argc, char const *argv[])
{
    FILE *fptr_read = fopen("zad8r.txt", "r");
    if (fptr_read == NULL) {
        printf("Loading failed.");
        return 0;
    }

    FILE *fptr_write = fopen("zad8w.txt", "w+");
    if (fptr_write == NULL) {
        printf("Loading failed.");
        return 0;
    }

    node head = {0, 0, NULL};
    node *last = &head;

    char *pStart = (char*) malloc((100)*sizeof(char)), *pEnd;
    int len = 0;
    int n;
    while (fgets(pStart, 100, fptr_read) != NULL) {
        last = &head;
        while (1) {
            n = strtol(pStart, &pEnd, 10);
            if (pStart == pEnd) break;
            pStart = pEnd;
            last->amount += 1;
            last->sum += n;
            if (last->next == NULL) {
                last = insert(last);
                len++;
            }
            else last = last->next;
            printf("test %d\n", n);
        }
    }

    last = &head;
    int i = 0;
    fflush(fptr_write);
    fprintf(fptr_write, "SUMA:");
    while (i < len) {
        fflush(fptr_write);
        fprintf(fptr_write, " %d", last->sum);
        last = last->next;
        i++;
    }
    fflush(fptr_write);
    fprintf(fptr_write, "\nSREDNIA:");
    last = &head;
    i = 0;   
    while (i < len) {
        fflush(fptr_write);
        fprintf(fptr_write, " %lf", (double) last->sum/last->amount);
        last = last->next;
        i++;
    }
    fclose(fptr_read);
    fclose(fptr_write);
    return 0;
}