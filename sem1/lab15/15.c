// Вариант 12
// Циклический сдвиг элементов матрицы по спирали по (против) часовой стрелки на 3 элемента
#include <stdio.h>

int main() {
    // Считываем количество строк (столбцев)
    int n;
    scanf("%d", &n);

    // Заполняем массив размером n * n
    int t = 0;
    int mass[n * n];
    while (t < n * n) {
        scanf("%d", &mass[t]);
        t++;
    }

    // Задаем начальную точку (i строку и j столбец)
    int i = 1, j = 1;
    // Задаем границы, в которых совершаем обход
    int top_limit = 1, bottom_limit = n, right_limit = n, left_limit = 1;
    // Задаем переменные, нужные для сохранения предыдущих трёх значений
    int prev0 = 0, prev1 = 0, prev2 = 0, prev3 = 0;
    // Задаем переменные, нужные для сохранения индексов предыдущий трёх значений
    int c = 0, c2 = 0, c3 = 0;
    int c1 = 0;
    // Задаем начальное состояние (0 - идём вправо и вниз, 1 - идём влево и вверх)
    int state = 0;

    // Начинаем обход
    t = 0;
    for (int k = 0; k < n; k++) {
        // Проход первого элемента
        if (i == 1 && j == 1) {
            c = (i - 1) * n + (j - 1);
            prev3 = prev2;
            prev2 = prev1;
            prev1 = prev0;
            prev0 = mass[c];
            mass[c] = prev3;
            t++;
            if (t < 4) {
                c3 = c2;
                c2 = c1;
                c1 = c;
            }
        }
        // Совершаем проход вправо и вниз, запоминая при этом предыдущие значения и меняя нынешнее значение на то, что было 3 итерации назад
        if (state == 0) {
            while (j < right_limit) {
                j++;
                c = (i - 1) * n + (j - 1);
                prev3 = prev2;
                prev2 = prev1;
                prev1 = prev0;
                prev0 = mass[c];
                mass[c] = prev3;
                t++;
                if (t < 4) {
                    c3 = c2;
                    c2 = c1;
                    c1 = c;
                }
            }
            while (i < bottom_limit) {
                i++;
                c = (i - 1) * n + (j - 1);
                prev3 = prev2;
                prev2 = prev1;
                prev1 = prev0;
                prev0 = mass[c];
                mass[c] = prev3;
                t++;
                if (t < 4) {
                    c3 = c2;
                    c2 = c1;
                    c1 = c;
                }
            }
            // Меняем границы, в которых совершаем обход
            right_limit--;
            top_limit++;
            state = 1;
        }
        // Совершаем проход влево и вверх, запоминая при этом предыдущие значения и меняя нынешнее значение на то, что было 3 итерации назад
        if (state == 1) {
            while (j > left_limit) {
                j--;
                c = (i - 1) * n + (j - 1);
                prev3 = prev2;
                prev2 = prev1;
                prev1 = prev0;
                prev0 = mass[c];
                mass[c] = prev3;
                t++;
                if (t < 4) {
                    c3 = c2;
                    c2 = c1;
                    c1 = c;
                }
            }
            while (i > top_limit) {
                i--;
                c = (i - 1) * n + (j - 1);
                prev3 = prev2;
                prev2 = prev1;
                prev1 = prev0;
                prev0 = mass[c];
                mass[c] = prev3;
                t++;
                if (t < 4) {
                    c3 = c2;
                    c2 = c1;
                    c1 = c;
                }
            }
            // Меняем границы, в которых совершаем обход
            left_limit++;
            bottom_limit--;
            state = 0;
        }
    }
    // Присваиваем первым трём элементам массива, значения трёх последених, по которым прошли.
    mass[c3] = prev2;
    mass[c2] = prev1;
    mass[c1] = prev0;
    // Выводим полученную матрицу
    t = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mass[t]);
            t++;
        }
        printf("\n");
    }
    
    return 0;
}