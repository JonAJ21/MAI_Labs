// Вариант 27
// Выделить предпоследнее десятичное число и 
// распечатать его цифры в системах счисления
// с основаниями 3, 7 и 11

#include <stdio.h>
#include <math.h>
#include <ctype.h>


int num_system(int num, int base) {
    int res = 0;
    while (num > 0) {
        res = (num % base) * 10 + res;
        num /= base;
    }
    return res;
} 



int main() {

    // Выделяем предполследнее число
    int flag = 1, state = 0, last_num = 0, penultimate_num = -1, prepenult_num = -1, temp;
    char symbol, previous_symbol;
    while (scanf("%c", &symbol) != EOF) {
        if ((symbol == ' ' || symbol == ',' || symbol == '\0' || symbol == '\t' || symbol == '\n') && flag == 0) {
            flag = 1;
            state = 0;
            prepenult_num = penultimate_num;
            penultimate_num = last_num;
            last_num = 0;
        } else if (isdigit(symbol) && state == 0) {
            flag = 0;
            last_num = last_num * 10 + (symbol - '0');
        } else if (isalpha(symbol) != 0 ) {
            flag = 0;
            state = 1;
            last_num = penultimate_num;
            penultimate_num = prepenult_num;
        }
    }
    printf("\n");
    printf("penultimate_num: %d lastnum: %d\n",penultimate_num, last_num);
    // Вывводим цифры предпоследнего числа в 3сс, 7сс, 11сс
    printf("\n %d", num_system(10,2));




    return 0;
}