#include <stdio.h>
#include <stdlib.h>


// Сысоев - Реализация бинарного поиска
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
    int step_size = length/2;
    int i = step_size;

    if ((val > arr[length - 1]) || (val < arr[0]))
    {
        rslt.rslt_val = val;
        rslt.rslt_index =  -1;
        is_complete = 1;
    }

    while (is_complete != 1)
    {
        rslt.try_count++;
        if (arr[i - 1] != val)
        {
            step_size > 1 ? (step_size = step_size/2 + step_size%2) : (step_size);
            rslt.rslt_val = arr[i - 1];
            rslt.rslt_index = i - 1;
            printf("\n%d try: { value: %d, index: %d, tries: %d };", rslt.try_count, rslt.rslt_val, rslt.rslt_index, rslt.try_count);
            if (arr[i - 1] < val)
            {
                i += step_size;
                continue;
            }
            else if (arr[i - 1] > val)
            {
                i -= step_size;
                continue;
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
    int target_array[arr_size];

    printf("Array: { ");
    for (int i = 0; i < sizeof(target_array) / sizeof(target_array[0]); i++)
    {
        target_array[i] = (i + 1);

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
