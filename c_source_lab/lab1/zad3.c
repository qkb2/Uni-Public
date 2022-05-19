#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n, m;
    double R=0, P=1;
    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            P = P*(i*i+j*j-1)/(2*i+3*j+4);
        }
        R += P;
        P = 1;
    }
    printf("%lf", R);

    return 0;
}
