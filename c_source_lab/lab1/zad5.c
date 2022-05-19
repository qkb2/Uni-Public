#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a;
    scanf("%d", &a);
    for (int i = 1; i <= a; i++)
    {
        int S = 0;
        for (int j = 1; j <= i/2; j++)
        {
            if (i%j == 0)
            {
                S += j;
            }
            
        }
        if (S == i)
        {
            printf("%d \n", i);
        }
        
    }

    return 0;
}
