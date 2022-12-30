/*
Вариант 27
После каждых двух цифр вставить абсолютное значение их разности
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Number of tests: ");
    scanf("%d", &n);
    while (n--) {
        long long num, a, b, res, temp, i, sign = 0;
        printf("Input your num: ");
        scanf("%lld", &num);
        if (num < 0) {
            num = num * (-1);
            sign = 1;
        }
        i = 0;
        temp = 0;
        res = 0;
        while (num > 9) {
            a = num % 10;
            num = num / 10;
            b = num % 10;
            num = num / 10;
            num = ((num * 10 + abs(a - b)) * 10 + b) * 10 + a;
            res = (num % 1000) * (long long)(pow(1000,i)) + temp;
            num = num / 1000;
            temp = res;
            i++;
        }
        res = num * (long long)(pow(1000, i)) + res;
        if (sign == 1) {
            res = res * (-1);
        }
        printf("Result: %lld\n", res);
    }

    return 0;
}