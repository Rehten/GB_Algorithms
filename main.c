#include <stdio.h>

int power_without_recursion(int a, int b)
{
    if (b != 0)
    {
        int result = 1;
        while (b > 0)
        {
            result *= a;
            b--;
        }

        return result;
    }
    else
    {
        return 1;
    }
}

int power_recursion(int a, int b)
{
    if (b != 0)
    {
        return a * (b != 1 ? power_recursion(a, b - 1) : 1);
    }
    else
    {
        return 1;
    }
}

int power_recursion_optimized(int a, int b)
{
    if (b > 1)
    {
        int c = power_recursion_optimized(a, b/2);
        return (c * c * (b%2 == 0 ? 1 : a));
    }
    else if (b == 1)
    {
        return a;
    }
    else if (b == 0)
    {
        return 1;
    }
}

int main(int argc, char *argv[])
{
    int a;
    int b;

    printf("Multiply a * a, b times\n");
    printf("enter a: ");
    scanf("%d", &a);
    printf("enter b: ");
    scanf("%d", &b);

    printf("result without recursion is: %d\n", power_without_recursion(a, b));
    printf("result with recursion is: %d\n", power_recursion(a, b));
    printf("result with recursion is: %d\n", power_recursion_optimized(a, b));

    return 0;
}
