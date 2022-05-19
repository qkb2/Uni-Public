#include <stdio.h>

int fun(int n, int s) {
    s += n%10;
    n /= 10;
    if (n == 0) {
        return s;
    }
    return fun(n, s);
}


int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int s = fun(n, 0);
    printf("%d", s);
    return 0;
}
