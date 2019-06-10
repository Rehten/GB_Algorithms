#include <stdio.h>
#include <stdlib.h>

enum Actions
{
    AddOne = 5,
    MultiplyByTwo = 6
};

int calculator_way_recursion (int base, int max, int* result_count)
{
    if (base < max)
    {
        int plus_one = calculator_way_recursion(base + 1, max, result_count);
        if (plus_one == 1)
        {
            *result_count = *result_count + 1;
        }

        int multiply_two = calculator_way_recursion(base * 2, max, result_count);
        if (multiply_two == 1)
        {
            *result_count = *result_count + 1;
        }

        return 0;
    }
    else if (base == max)
    {
        return 1;
    }
    else
    {
        return -1;
    }

}

int main(int argc, char *argv[])
{
    int count = 0;
    calculator_way_recursion(3, 20, &count);
    printf("Total solutions is %d", count);
    return 0;
}
