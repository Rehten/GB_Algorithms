#include <stdio.h>

// I work on MinGW Windows and its compiler bad support russian
enum AgeEnds {
    Goda = 1,
    God = 2,
    Let = 3
};

char* age_end_by_index (enum AgeEnds ends)
{
    switch (ends)
    {
        case Goda:
            return "goda";
        case God:
            return "god";
        case Let:
            return "let";
        default:
            return "Error!";
    }
}

enum AgeEnds index_from_int (int num)
{
    // Цель - взять лишь последние два числа
    int num_data[2] = {0, 0};
    num_data[0] = (num/10)%10;
    num_data[1] = num%10;

    switch (num_data[0])
    {
        case 1:
            return Let;
        default:
            if (num_data[1] == 1)
            {
                return God;
            }
            else if ((num_data[1] > 1) && (num_data[1] < 5))
            {
                return Goda;
            }
            else
            {
                return Let;
            }
    }
}

int main()
{
    int human_age;
    printf("Welcome to my human age program\n");
    printf("enter human age: ");
    scanf("%d", &human_age);

    printf("%d %s", human_age, age_end_by_index(index_from_int(human_age)));

    return 0;
}
