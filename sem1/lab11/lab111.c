// Вариант 27
// Выделить предпоследнее десятичное число и 
// распечатать его цифры в системах счисления
// с основаниями 3, 7 и 11

#include <stdio.h>
#include <math.h>
#include <ctype.h>

// Функция для перевода числа в другую систему счисления
int num_system(int num, int base) {
    int res = 0;
    int i = 1;
    while (num > 0) {
        res = (num % base) * i + res;
        num /= base;
        i *= 10;
    }
    return res;
} 
// Функция для подсчёта количества цифр в числе
int num_length(int num) {
    int length = 0;
    while (num > 0) {
        num /= 10;
        length++;
    }
    return length;
}


int main() {
    // Поик предпоследнего числа
    int flag = 1, state = 0, last_num = 0, penultimate_num = -1, temp = 0;
    char symbol;
    while (scanf("%c", &symbol) != EOF) {
        if ((symbol == ' ' || symbol == ',' || symbol == '\0' || symbol == '\t' || symbol == '\n') && flag == 0) {
            state = 0;
            flag = 1;
            if (temp == -1) {
                temp = 0;
                continue;
            }
            penultimate_num = last_num;
            last_num = temp;
            temp = 0;
        } else if (isdigit(symbol) && state == 0) {
            temp = temp * 10 + (symbol - '0');
            flag = 0;
        } else if (isalpha(symbol) != 0) {
            flag = 0;
            temp = -1;
            state = 1;
        } 
    }
    printf("Penultimate_num: %d\n",penultimate_num);
    // Вывводим цифры предпоследнего числа в 3сс, 7сс, 11сс
    int len = num_length(penultimate_num) - 1;
    while (penultimate_num > 0) {
        int n = penultimate_num / (int)pow(10,len);
        penultimate_num %= (int)pow(10,len);
        len--;
        printf("Number: %d ; 3cc: %d ; 7cc: %d ; 11cc: %d\n",n, num_system(n, 3), num_system(n, 7), num_system(n, 11));
    }

    return 0;
}