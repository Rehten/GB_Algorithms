#include <stdio.h>
#include <stdlib.h>

enum Actions
{
    AddOne = 5,
    MultiplyByTwo = 6
};

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

void calculator_way_array ()
{
    int base = 3;
    int succeed_solutions_number = 0;
    int arr_length = 20 - base;
    int* arr = (int *)calloc((size_t)arr_length, sizeof(int));
    int solutions_count = power_without_recursion(2/* количество типов в enum */, arr_length);

    /* тестируем, что будет при каждом экшене. В случае корректного решения записываем его в таблицу */
    while (solutions_count != 0)
    {
        int try_number = solutions_count;
        int iter = 0;
        while (try_number != 0)
        {
            arr[iter] = try_number%2 + 5 /* чтобы проверить заполненные поля (незаполненные не могут быть выше 1 */;
            if (try_number > 1)
            {
                try_number /= 2;
            }
            else
            {
                try_number -= 1;
            }
            iter++;
        }

        iter = 0;

        for (int i = 0; i < arr_length; i++)
        {
            if (base < 20)
            {
                switch (arr[i])
                {
                    case AddOne:
                        base += 1;
                        break;
                    case MultiplyByTwo:
                        base *= 2;
                        break;
                    default:
                        break;
                }
            }
            else if (base >= 20)
            {
                for (int j = 0; j < arr_length; j++)
                {
                    if (j >= i)
                    {
                        arr[j] = 0;
                    }
                }
                goto Label;
            }
        }

        Label:

        if (base == 20)
        {
            succeed_solutions_number++;
            printf("%d succeed solution! base is: %d, actions list: ", succeed_solutions_number, base);

            for (int i = 0; i < arr_length; i++)
            {
                if (arr[i] >= 5)
                {
                    printf(", %d - ", i);
                    if (arr[i] == AddOne)
                    {
                        printf("+1");
                    }
                    else if (arr[i] == MultiplyByTwo)
                    {
                        printf("x2");
                    }
                }
            }
            printf("\n");

        }

        for (int i = 0; i < arr_length; i++)
        {
            arr[i] = 0;
        }

        base = 3;

        solutions_count--;
    }

    free(arr);
}

void calculator_way_recursion ()
{

}

int main(int argc, char *argv[])
{
    calculator_way_array();
    calculator_way_recursion();
    return 0;
}
