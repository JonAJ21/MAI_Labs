#include <stdio.h>
// Программа, возводящая число num в степень pow >= 0.
int main () {
    int num, pow, res;
    printf("Input num, pow: ");
    scanf("%d", &num);
    scanf("%d", &pow);
    res = num;
    if (pow == 0)
    {
        res = 1;
    }
    else{
        res = num;
    }

    for (int i = 1; i < pow; i++)
    {
        res = res * num;
    }

    printf("num = %d \n", num);
    printf("pow = %d \n", pow);
    printf("res = %d \n", res);
    return 0;
}