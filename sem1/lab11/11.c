// Вариант 27
// Выделить предпоследнее десятичное число и 
// распечатать его цифры в системах счисления
// с основаниями 3, 7 и 11


#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Функция для ввода строки
char *get_string(int *len) {
    *len = 0;
    int capacity = 1;
    char *s = (char*) malloc(sizeof(char));
    char c = getchar();
    while (c != '\n') {
        s[(*len)++] = c;
        if (*len >= capacity) {
            capacity *= 2;
            s = (char*) realloc(s, capacity * sizeof(char));
        }
        c = getchar();
    }
    s[*len] = '\0';
    return s;
}
// Функция реверса строки
void reverse (char* str) {
    int n = strlen(str);
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        char ch = str[i];
        str[i] = str[j];
        str[j] = ch;
    }
}

int main() {
    // Находим предпоследнее число
    int len, state = 0;
    char *s = get_string(&len);
    char *last_num = (char*) malloc(1);
    char *penultimate_num = (char*) malloc(1);
    printf("%s ; len = %d", s, len);
    int l = 0;
    for (int i = 0; i < len; i++) {
        if (isdigit(s[i]) && state == 0) {
            last_num = (char*) realloc(last_num, ++l * sizeof(char) + 1);
            last_num[l - 1] = s[i];
            last_num[l] = '\0';
            
        } else if (isdigit(s[i]) && state == 1) {
            free(penultimate_num);
            penultimate_num = (char*) malloc(strlen(last_num));
            strcpy(penultimate_num,last_num);
            free(last_num);
            l = 0;
            last_num = (char*) malloc(++l + 1); 
            last_num[l - 1] = s[i];
            last_num[l] = '\0';
            state = 0;
        } else {
            state = 1;
        }
    }
    
    printf("penultimate_num: %s \n",penultimate_num);
    // Переводим цифры предпоследнего числа в 3сс, 7сс, 11сс
    for (int i = 0; i < strlen(penultimate_num); i++)
    {
        printf("%d: ", penultimate_num[i] - '0');
        for (int j = 3; j < 12; j++)
        {
            if (j == 3 || j == 7 || j == 11) {
                char *ss = (char*) malloc(0);
                int l = 0;
                int num = penultimate_num[i] - '0';
                while (num > 0) {
                    ss = (char*) realloc(ss, ++l * sizeof(char) + 1);
                    ss[l - 1] = (num % j) + 48;
        
                num /= j;
                }
                ss[l] = '\0';
                reverse(ss);
                if (strlen(ss) > 0) {
                    printf("%dсс: %s, ",j, ss);
                } else {
                    printf("%dcc: 0, ", j);
                }
                free(ss);
            }
        }
        printf("\n");
    }
    
    return 0;
}