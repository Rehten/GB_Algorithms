
#include <stdio.h>
#include <math.h>

// КОМАНДА ДЛЯ КОМПИЛЯЦИИ: gcc -o main main.c -lm - для поддержки math.h
// после сборки запуститьт объектный код: ./main

int calculateSquareEquality (int a, int b, int c, float* x1, float* x2) {
    float disc = (float)b * (float)b - 4 * (float)a * (float)c;

    // случай с D = 0 рассматривается так же, как и D > 0 - просто значения корней равны - решение принято для сокращения кода.
    if (disc >= 0) {
        *x1 = ((-1) * b + sqrt(disc))/2 * a;
        *x2 = ((-1) * b - sqrt(disc))/2 * a;
        return 1;
    } else {
        return -1;
    }


}

int main() {
    int a, b, c;
    float x1, x2;
    int resultCode;
    printf("Welcome to the square root finder.\n\n");
    printf("Square expression is ax2 + bx + c = 0. Find a,b и с:\n");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("c: ");
    scanf("%d", &c);

    resultCode = calculateSquareEquality(a, b, c, &x1, &x2);

    switch (resultCode) {
        case 1:
            printf("Square has two roots: x1 = %7.2f and x2 = %7.2f\n", x1, x2);
            break;
        case -1:
            printf("No roots\n");
            break;
        default:
            printf("Error\n");
            break;
    }

    return 0;
}
