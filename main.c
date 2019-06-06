#include <stdio.h>

int main()
{
    double human_mass;
    double human_height;

    printf("Welcome to my mass index calculator for human body!\n");
    printf("enter mass: ");
    scanf("%lf", &human_mass);
    printf("\n");
    printf("human mass is: %.2f \n", human_mass);
    printf("enter height: ");
    scanf("%lf", &human_height);
    printf("\n");
    printf("human height is: %.2lf ", human_height);

    printf("human mass index is : %.2lf", (human_mass/(human_height * human_height)));
    return 0;
}
