#include <stdio.h>
#include <stdlib.h>

struct Result
{
    int rslt_val;
    int rslt_index;
};

struct Result binary_find (int val, int arr[])
{
    struct Result rslt = {0, 0};

    return rslt;
}

void print_binary_find (struct Result rslt)
{
    printf("\nResult of Binary finding: { rslt_val: %d, rslt_index: %d };", rslt.rslt_val, rslt.rslt_index);
}

int main(int argc, char *argv[])
{
    int arr_size;
    int arr_multiply;
    printf("Enter arr size: ");
    scanf("%d", &arr_size);
    printf("Enter arr member multiply constant(for 3 - arr[1] == 3, arr[2] == 6): ");
    scanf("%d", &arr_multiply);
    int target_array[arr_size];

    printf("Array: { ");
    for (int i = 0; i < sizeof(target_array) / sizeof(target_array[0]); i++)
    {
        target_array[i] = (i + 1) * arr_multiply;

        if (i != 0)
        {
            printf(", ");
        }
        printf("%d", target_array[i]);
    }
    printf(" }");

    struct Result find_rslt = binary_find(1, target_array);

    print_binary_find(find_rslt);
    return 0;
}
