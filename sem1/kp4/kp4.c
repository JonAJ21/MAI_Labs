#include <stdio.h>
#include <math.h>

#include <unistd.h>

long double mabs(long double a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

long double f1(long double x) {
    return 2 * x * sinl(x) - cosl(x);
}

long double fd1(long double x) {
    return 3 * sinl(x) + 2 * x * cosl(x);
}

long double f2(long double x) {
    return powl(M_E, x) + sqrtl(1 + powl(M_E, 2*x)) - 2;
}

long double fd2(long double x) {
    return powl(M_E, x) + powl(M_E, 2 * x)/(sqrtl(1 + powl(M_E, 2*x)));
}

long double fi2(long double x) {
    return logl(2 - sqrtl(1 + powl(M_E, 2*x)));
}


long double dichotomy(long double a, long double b, long double e, long double (*f) (long double)) {
    long double c = (a + b) / 2., fb = f(b), fc = f(c);
    long double answ;
    if (c + e > b) {
        answ = c;
    } else if ((fc * fb) < 0) {
        answ = dichotomy(c, b, e, f);
    } else if ((fc * fb) > 0) {
        answ = dichotomy(a, c, e, f);
    } else {
        answ = c;
    }
    return answ;
}


long double iterations(long double x, long double e, long double (*f) (long double), long double (*fi) (long double)) {
    long double fx = fi(x);
    if (mabs(x - fx) < e) {
        return x;
    }
    return iterations(fx, e, f, fi);
}

long double newton(long double x, long double e, long double (*f) (long double), long double (*fd) (long double)) {
    long double fx = x - f(x)/fd(x);
    if (mabs(x - fx) < e) {
        return fx;
    }
    return newton(fx, e, f, fd);
}


long double calc_eps() {
    long double e = 1;
    long double eps;
    while(1 < (1 + e)){
        eps = e;
        e /= 2;
    }
    return eps;
}

int main() {
    long double eps = calc_eps(), k = 0.3;
    
    long double a1 = 0.4, b1 = 1.0;
    long double a2 = -1.0, b2 = 0.0;
    

    long double d1 = dichotomy(a1, b1, k * eps, f1), d2 = dichotomy(a2, b2, k * eps, f2);
    long double i2 = iterations((a1 + b2)/2., k * eps, f2, fi2);
    long double n1 = newton((a1 + b1)/2., k * eps, f1, fd1), n2 = newton((a2 + b2)/2., k * eps, f2, fd2);

    printf("\n_______________________________________________________________________________\n");
    printf("Function:            | Method:    | Root:                | Function at found x:  \n");
    printf("2*x*sin(x)-cos(x)    | Dichotomy  | %.18Lf | %.18Lf\n", d1, f1(d1));
    printf("2*x*sin(x)-cos(x)    | Iterations | None                 | None\n");
    printf("2*x*sin(x)-cos(x)    | Newton     | %.18Lf | %.18Lf\n", n1, f1(d1));
    printf("e^x+sqrt(1+e^(2x))-2 | Dichotomy  | %.17Lf | %.18Lf\n", d2, f2(d2));
    printf("e^x+sqrt(1+e^(2x))-2 | Iterations | %.17Lf | %.18Lf\n", i2, f2(d2));
    printf("e^x+sqrt(1+e^(2x))-2 | Newton     | %.17Lf | %.18Lf\n", n2, f2(d2));

    printf("\nMachine-calculated epsilon: %.20Lf\n", eps);
    return 0;
}
