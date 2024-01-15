//Шабанов Р.А.
//РС-з31
//Лабораторна робота №3
#include <stdio.h>
#include "methods.h"

int main() {
    double initial_guess;
    double epsilon;
    int max_iter;

    // Зчитуємо вхідні дані
    printf("Введіть початкове наближення: ");
    scanf("%lf", &initial_guess);
    printf("Введіть похибку обчислення epsilon: ");
    scanf("%lf", &epsilon);
    printf("Введіть максимальну кількість ітерацій: ");
    scanf("%d", &max_iter);

    // Викликаємо метод бісекції
    printf("\nРезультат методу бісекції:\n");
    Result result_bisection = bisection(initial_guess, epsilon, max_iter);
    printf("Значення кореня: %.6lf\n", result_bisection.root);
    printf("Значення функції у точці: %.6lf\n", f(result_bisection.root));
    printf("Кількість ітерацій: %d\n", result_bisection.iterations);

    // Викликаємо метод Ньютона
    printf("\nРезультат методу Ньютона:\n");
    Result result_newton = newton(initial_guess, epsilon, max_iter);
    printf("Значення кореня: %.6lf\n", result_newton.root);
    printf("Значення функції у точці: %.6lf\n", f(result_newton.root));
    printf("Кількість ітерацій: %d\n", result_newton.iterations);

    return 0;
}
