#include <stdio.h>

void fun(int i, char str[]){
    if (i >= 0) {
        //printf("check");
        putchar(str[i--]);
        fun(i, str);
    }
}



int main(int argc, char const *argv[])
{
    char str[10];
    scanf("%s", &str);
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    --i;
    //printf("%d", i);
    fun(i, str);

    return 0;
}
