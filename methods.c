// methods.c
#include "methods.h"
#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x - 4;
}

double df(double x) {
    return 2 * x;
}

Result bisection(double initial_guess, double epsilon, int max_iter) {
    double a = initial_guess - 1.0;  // Initial lower bound
    double b = initial_guess + 1.0;  // Initial upper bound
    double c;

    // Ensure that f(a) and f(b) have opposite signs
    while (f(a) * f(b) >= 0) {
        a -= 1.0;
        b += 1.0;
    }

    Result result;
    result.iterations = 0;

    for (int i = 0; i < max_iter; i++) {
        c = (a + b) / 2.0;

        if (fabs(b - a) < epsilon || f(c) == 0.0) {
            printf("Метод бісекції зійшовся після %d ітерацій.\n", result.iterations);
            result.root = c;
            return result;
        }

        if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }

        result.iterations++;  // Increment the iteration count inside the loop
    }

    printf("Метод бісекції не зійшовся після %d ітерацій.\n", max_iter);
    result.root = c;
    return result;
}

Result newton(double x0, double epsilon, int max_iter) {
    Result result;
    result.iterations = 0;
    double x = x0;

    for (int i = 0; i < max_iter; i++) {
        double delta = f(x) / df(x);

        x = x - delta;

        if (fabs(delta) < epsilon || f(x) == 0.0) {
            printf("Метод Ньютона зійшовся після %d ітерацій.\n", result.iterations);
            result.root = x;
            return result;
        }

        result.iterations++;
    }

    printf("Метод Ньютона не зійшовся після %d ітерацій.\n", max_iter);
    result.root = x;
    return result;
}
