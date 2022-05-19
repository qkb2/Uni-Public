#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int amount;
    int sum;
    struct Node *next;
} node;

node * insert(node* last, int val) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->sum = val;
    new_node->amount = 1;
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
    node* last = &head;

    char *pStart = (char*) malloc((100)*sizeof(char)), *pEnd;
    int len = 0, i = 0;
    int n;
    while (fgets(pStart, 100, fptr_read) != NULL) {
        // printf("test1: %s\n", pStart);
        i = 0;
        if (head.next == NULL)
            last = &head;
        else last = head.next;

        while (1) {
            n = strtol(pStart, &pEnd, 10);
            if (pStart == pEnd) break;
            if (len == i) {
                len++;
                last = insert(last, n);
            }
            else {
                last->amount += 1;
                last->sum += n;
                last = last->next;
            }
            i++;
            pStart = pEnd;
            // printf("test %d: %d %d\n", i, last->amount, last->sum);
        }
    }

    last = &head;
    i = 0;
    fflush(fptr_write);
    fprintf(fptr_write, "SUMA:");
    while (i < len) {
        fflush(fptr_write);
        fprintf(fptr_write, " %lf", last->sum);
        last = last->next;
    }
    fflush(fptr_write);
    fprintf(fptr_write, "SREDNIA:");
    last = &head;
    i = 0;   
    while (i < len) {
        fflush(fptr_write);
        fprintf(fptr_write, " %lf", last->sum/last->amount);
        last = last->next;
    }
    fclose(fptr_read);
    fclose(fptr_write);
    return 0;
}