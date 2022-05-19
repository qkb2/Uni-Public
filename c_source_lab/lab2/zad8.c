#include <stdio.h>

int fun(int square, int num) {
    if (num == 0) {
        return 1;
    }
    if (num%10 != square%10) {
        return 0;
    }
    return fun(square/10, num/10);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (fun(i*i, i) == 1) {
            printf("%d\n", i);
        }
    }
    return 0;
}