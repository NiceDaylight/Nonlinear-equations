// methods.h
#ifndef METHODS_H
#define METHODS_H

typedef struct {
    double root;
    int iterations;
} Result;

// Function declarations
double f(double x);
double df(double x);
Result bisection(double initial_guess, double epsilon, int max_iter);
Result newton(double x0, double epsilon, int max_iter);

#endif
