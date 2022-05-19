#include <stdio.h>
int main(int argc, char const *argv[])
{
    int h;
    scanf("%d", &h);
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= h-i; j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= 2*i-1; k++)
        {
            printf("X");
        }
        printf("\n");
    }
    
    return 0;
}
