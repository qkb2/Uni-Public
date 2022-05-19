#include <stdio.h>
int main(int argc, char const *argv[]) {
    int a;
    scanf("%d", &a);

    for (int num = 1; num <= a; num++) {
        int S_num = 0;
        for (int j = 1; j <= num/2; j++) {
            if (num%j == 0) {
                S_num += j;
            }
        }

        int S_friend = 0;
        for (int j = 1; j <= S_num/2; j++) {
            if (S_num%j == 0) {
                S_friend += j;
            }
        }

        if (S_friend == num) {
            printf("Pair of %d and %d\n", num, S_num);
        }
    }
    
    return 0;
}
