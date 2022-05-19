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


int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int is = fun(n*n, n);
    printf("%d", is);
    return 0;
}
