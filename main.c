#include <stdio.h>

int main(int argc, char *argv[])
{
    int max;
    printf("Enter you number: \n");
    scanf("%d", &max);

    for (int i = 1; i * i <= max; i++)
    {
        // проверка на автоморфность
        // определение числа цифр в числе
        int i_square = i * i;
        int is_sliced = 0;
        int slice_index = 1;
        while ((i_square > i) || (is_sliced == 0))
        {
            slice_index *= 10;
            i_square /= 10;
            is_sliced = 1;
        }


        if (i == (i * i)%slice_index)
        {
            printf("number %d is authomorphic. Its square is %d\n", i, i * i);
        }
    }

    return 0;
}