#include <stdio.h>

int main()
{
    double human_mass;
    double human_height;

    printf("Welcome to my mass index calculator for human body!\n");
    printf("enter mass: ");
    scanf("%lf", &human_mass);
    printf("\n");
    printf("human mass is: %.2f ", human_mass);
    return 0;
}
