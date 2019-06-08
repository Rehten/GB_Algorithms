#include <stdio.h>

int main()
{
    int a;
    int b;

    printf("welcome to my variable reverse program!\n");

    printf("enter a val: ");
    scanf("%d", &a);

    printf("enter b val: ");
    scanf("%d", &b);

    a = b + a;
    b = a - b;
    a = a - b;

    printf("after reverse a is %d, and b is %d", a, b);


    return 0;
}
