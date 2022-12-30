// Вариант 12
// 1 3 4 10
// 2 5 9 11
// 6 8 12 15
// 7 13 14 16
#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main() {
    // Считываем количество строк (столбцев)
    int n;
    scanf("%d",&n);
    // Заполняем массив размером n * n
    int i = 1, j = 1, k = 0, c = 0, state = 0, t = 0;
    int m[n * n];
    while (t < n * n) {
        scanf("%d", &m[t]);
        t++;
    }
 
    // Начинаем обход в заданном порядке
    while (k < n * n) {
        if (i == 1 && j == 1) {
            c = (i - 1) * n + (j - 1);
            k++;
            printf("%d ", m[c]);
            if (n == 1) {
                break;
            }
        }
        if (state == 0) {
            while (j != 1 && i != n) {
                j--;
                i++;
                k++;
                c = (i - 1) * n + (j - 1);
                printf("%d ", m[c]);
            }
            if (i < n) {
                i++;
                k++;
                c = (i - 1) * n + (j - 1);
                printf("%d ", m[c]);
            } else {
                j++;
                k++;
                c = (i - 1) * n + (j - 1);
                printf("%d ", m[c]);
            }
            state = 1;
        }
        if (state == 1) {
            while (j != n && i != 1) {
                j++;
                i--;
                k++;
                c = (i - 1) * n + (j - 1);
                printf("%d ", m[c]);
            }
            if (j < n) {
                j++;
                k++;
                c = (i - 1) * n + (j - 1);
                printf("%d ", m[c]);
            } else {
                i++;
                k++;
                c = (i - 1) * n + (j - 1);
                printf("%d ", m[c]);
            }
            state = 0;
        }

    }
    printf("\n");
    
    
    

    return 0;
}