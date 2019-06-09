#include <stdio.h>

int main(int argc, char *argv[])
{
    int user_input = 1;
    int summ = 0;
    int index = 0;

    printf("Enter any numbers except 0 for finished calculation, then return middle arithemtical 2, 4, 6... finished 8\n");

    while (user_input != 0)
    {
        scanf("%d", &user_input);

        if (user_input%10 == 8)
        {
            index++;
            summ += user_input;
        }
    }

    printf("Average arythmetical is %.2f", (float)summ/(float)index);

    return 0;
}
