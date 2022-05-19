#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    double a, S=0;
    scanf("%d", &n);
    scanf("%lf", &a);
    for (int i = 1; i <= n; i++)
    {
        S += (a*i*i*i-7)/(i*i+1);
    }
    printf("%lf", S);

    return 0;
}
