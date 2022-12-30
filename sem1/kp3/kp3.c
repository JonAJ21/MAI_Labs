#include <stdio.h>
#include <math.h>

long double epsilon() {
    long double e = 1;
    long double eps;
    while(1 < (1 + e)){
        eps = e;
        e /= 2;
    }
    return eps;
}

unsigned long long factorial(unsigned long long a) {
    unsigned long long ans = 1;
    for (unsigned long long i = 1; i <= a; ++i) {
        ans *= i;
    }
    return ans;
}

long double module(long double a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

long double f(long double x) {
    return sin(x) * sin(x);
}

long double taylor(long double x, unsigned long long *iters, long double eps, long double k) {
    long double sum = 0, curr, next = 0, temp;
    for (unsigned long long i = 0; i <= 1000; ++i) {
        *iters = i;
        curr = next;
        
        next = pow(-1, i) * (pow(2, 2 * (i + 1) - 1) * pow(x, 2 * (i + 1))) / (long double) factorial(2 * (i + 1));
        temp = module(curr - next);
        if (temp < k * eps && i != 0) {
            break;
        }
        sum += curr;
    }
    return sum;
}

int main() {
    unsigned long long n_t, n;
    long double eps = epsilon(), k = 3112500, a = 0, b = 1, x = a;

    printf("\nZadannaya functsiya: f(x) = sin(x) * sin(x)");
    printf("\nEnter number of x's iterations: ");
    scanf("%lld", &n);

    long double dx = (b - a) / (long double) n;

    printf("\n|x       |chast. summa ryada dlya f |znachenie functsii f(x)   |chislo iteratsiy\n");

    for (; x <= b + eps; x += dx) {
        printf("|%.5Lf ", x);
        printf("|%.23Lf ", taylor(x, &n_t, eps, k));
        printf("|%.23Lf ", f(x));
        printf("|%2lld ", n_t);
        printf("\n");
    }
    printf("\nMachine-calculated epsillon = %.30Lf\n", eps);
    printf("Coefficient = %.1Lf\n\n", k);
    return 0;
}