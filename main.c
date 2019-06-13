#include <stdio.h>
#include <stdlib.h>


// Сысоев - Реализация пузырьковой, шейкерной, сортировки выбором и их сравнения
struct Result
{
    int rslt_val_length;
    int* rslt_val;
    int try_count;
};

void print_rslt(struct Result rslt)
{
    printf("\nResult Output:>> { array: ");
    for (int i = 0; i < rslt.rslt_val_length; i++)
    {
        if (i != 0)
        {
            printf(", ");
        }
        printf("%d", rslt.rslt_val[i]);
    }
    printf(" }, tries: %d }", rslt.try_count);


}

void swap_items(int* a, int* b)
{
    *b += *a;
    *a = *b - *a;
    *b = *b - *a;
}

struct Result sort_bubble(int* arr, int length)
{
    // аллокация памяти под копию массива
    int* sorted_arr = malloc(sizeof(arr[0]) * length);
    int is_complete = 0;
    struct Result rslt;
    rslt.rslt_val = sorted_arr;
    rslt.rslt_val_length = length;
    rslt.try_count = 0;

    // копирование массива
    for (int i = 0; i < length; i++)
    {
        sorted_arr[i] = arr[i];
    }

    while (is_complete == 0)
    {
        is_complete = 1;
        for (int i = 0; i < length - 1; i++)
        {
            if (sorted_arr[i] > sorted_arr[i + 1])
            {
                swap_items(&sorted_arr[i], &sorted_arr[i + 1]);
                is_complete = 0;
            }
            rslt.try_count++;
        }

    }

    return rslt;
}

struct Result sort_cocktail(int* arr, int length)
{
    // аллокация памяти под копию массива
    int* sorted_arr = malloc(sizeof(arr[0]) * length);
    int is_complete = 0;
    int reach = length - 1;
    int start = 0;
    int loop_direction = 1; /* 1 - прямо, (-1) - обратно */
    int* reach_element; /* самый большой при нечетном проходе, самый малый при четном */
    struct Result rslt;
    rslt.rslt_val = sorted_arr;
    rslt.rslt_val_length = length;
    rslt.try_count = 0;

    // копирование массива
    for (int i = 0; i < length; i++)
    {
        sorted_arr[i] = arr[i];
    }

    while (is_complete == 0)
    {
        is_complete = 1;
        if (loop_direction == 1)
        {
            reach_element = &sorted_arr[reach];
            for (int i = start; i < reach; i++)
            {
                if (sorted_arr[i] > sorted_arr[i + 1])
                {
                    swap_items(&sorted_arr[i], &sorted_arr[i + 1]);
                    is_complete = 0;
                }
                if (sorted_arr[i] > *reach_element)
                {
                    *reach_element = sorted_arr[i];
                }
                if ((i + 1 == reach) && (sorted_arr[reach] != *reach_element))
                {
                    swap_items(&sorted_arr[i + 1], reach_element);
                    is_complete = 0;
                }
                rslt.try_count++;
            }
            reach--;
        }
        else if (loop_direction == -1)
        {
            reach_element = &sorted_arr[start];
            for (int i = reach; i > start; i--)
            {
                if (sorted_arr[i - 1] > sorted_arr[i])
                {
                    swap_items(&sorted_arr[i - 1], &sorted_arr[i]);
                    is_complete = 0;
                }
                if (sorted_arr[i] < *reach_element)
                {
                    *reach_element = sorted_arr[i];
                }
                if ((i - 1 == start) && (sorted_arr[i - 1] != *reach_element))
                {
                    swap_items(&sorted_arr[i - 1], reach_element);
                    is_complete = 0;
                }
                rslt.try_count++;
            }
            start++;
        }
        loop_direction *= (-1);

    }

    return rslt;
}

int main(int argc, char *argv[])
{
    int arr_size;printf("Enter arr size: ");
    scanf("%d", &arr_size);
    int target_array[arr_size];

    for (int i = 0; i < sizeof(target_array) / sizeof(target_array[0]); i++)
    {
        printf("Program:>> enter %d member: ", i);
        scanf("%d", &target_array[i]);
    }

    printf("Program Output:>> { ");
    for (int i = 0; i < sizeof(target_array) / sizeof(target_array[0]); i++)
    {
        if (i != 0)
        {
            printf(", ");
        }
        printf("%d", target_array[i]);
    }
    printf(" }");

    printf("\nBubble sort result: ");
    print_rslt(sort_bubble(target_array, arr_size));
    printf("\nCocktail sort result: ");
    print_rslt(sort_cocktail(target_array, arr_size));

    return 0;
}
