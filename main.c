#include <stdio.h>
#include <stdlib.h>

struct Result
{
    int rslt_val;
    int rslt_index;
    int try_count;
};

struct Result binary_find (int val, int const arr[], int length)
{
    struct Result rslt = {0, 0, 0};
    int is_complete = 0;
    int i = length/2 + length%2;

    while (is_complete != 1)
    {
        rslt.try_count++;
        if (arr[i - 1] != val)
        {
            rslt.rslt_val = arr[i - 1];
            rslt.rslt_index = i - 1;
            printf("\n%d try: { value: %d, index: %d, tries: %d };", rslt.try_count, rslt.rslt_val, rslt.rslt_index, rslt.try_count);
            if (arr[i - 1] < val)
            {
                i += (i)/2;
            }
            else if (arr[i - 1] > val)
            {
                i -= (i)/2;
            }
        }
        else
        {
            rslt.rslt_val = val;
            rslt.rslt_index = i - 1;
            is_complete = 1;
        }
    }

    return rslt;
}

void print_binary_find (struct Result rslt)
{
    printf("\nResult of Binary finding: { value: %d, index: %d, tries: %d };", rslt.rslt_val, rslt.rslt_index, rslt.try_count);
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

    int finding_val;

    printf("\n\nSelect value for found: ");
    scanf("%d", &finding_val);

    struct Result find_rslt = binary_find(finding_val, target_array, sizeof(target_array) / sizeof(target_array[0]));

    print_binary_find(find_rslt);
    return 0;
}
