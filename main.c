#include <stdio.h>

int main(int argc, char *argv[])
{
    int a;
    int b;
    int c;

    printf("Enter a, b, c numbers: \n");

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    int nums[3] = {a, b, c};
    int rslt = nums[0];

    for (int i = 0; i < (sizeof(nums))/sizeof(nums[0]); i++)
    {
        if (nums[i] > rslt)
        {
            rslt = nums[i];
        }
    }

    printf("max number is %d", rslt);

    return 0;
}