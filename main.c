#include <stdio.h>
#include <stdlib.h>

int binary_find (int val, int arr[])
{
    int rslt[2] = {0, 0};

    return *rslt;
}

void print_binary_find (int* rslt)
{
    printf("\nResult of Binary finding: { %d, %d, };", rslt[0], rslt[1]);
}

int main(int argc, char *argv[])
{
    int target_array[25];

    printf("Array: { ");
    for (int i = 0; i < sizeof(target_array) / sizeof(target_array[0]); i++)
    {
        target_array[i] = i * 3;

        if (i != 0)
        {
            printf(", ");
        }
        printf("%d", target_array[i]);
    }
    printf(" }");

    int find_rslt = binary_find(1, target_array);

    print_binary_find(&find_rslt);
    return 0;
}
