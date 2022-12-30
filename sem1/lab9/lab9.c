/*
Вариант 12
Лунка, являющаяся пересечением двух кругов радиуса 10,
центр первого круга - в точке (-10;-10),
центр второго круга - в точке (-20;-20).
i[0] = -22, j[0] = 29, l[0] = 4,
i[k + 1] = signmin(i[k],j[k])max((i[k] + k)mod20,(j[k] + l[k]mod20)),
j[k + 1] = |max(i[k],j[k])| - kmin(j[k],l[k]),
l[k + 1] = |k - l[k])/((i[k] + j[k] + l[k])(i[k] + j[k] + l[k])mod5 + 1)
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int mod(int a, int b) {
    return a - floor((double)a / (double)b) * b;
}
int sign(int n) {
    if (n > 0) return 1;
    else if (n == 0) return 0;
    else return -1;
}
int Min(int a, int b) {
    if (a < b) return a;
    else return b;
}
int Max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int main() {
    int ik, jk, lk, ik1, jk1, lk1, k;
    ik = -22;
    jk = 29;
    lk = 4;
    k = 0;
    while (k <= 50 && (((ik + 10)*(ik + 10) + (jk + 10)*(jk + 10)) > 100 || ((ik + 20)*(ik + 20) + (jk + 20)*(jk + 20)) > 100)) {
        printf("k: %d , ik: %d , jk: %d , lk: %d\n",k,ik,jk,lk);
        ik1 = sign(Min(ik,jk)) * Max(mod((ik + k), 20), mod((jk + lk), 20));
        jk1 = abs(Max(ik, jk)) - k * Min(jk, lk);
        lk1 = (k - lk) / (mod(((ik + jk + lk) * (ik + jk + lk)), 5) + 1);
        ik = ik1;
        jk = jk1;
        lk = lk1;
        k++;
    }
    if (k > 50) {
        printf("Promax k: %d , ik: %d , jk: %d , lk: %d\n",k, ik, jk, lk);
    } else {
        printf("Popadanie k: %d , ik: %d , jk: %d , lk: %d\n",k, ik, jk, lk);
    }
    return 0;
}
