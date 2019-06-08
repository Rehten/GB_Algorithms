#include <stdio.h>

int main()
{
    int user_input;
    int result = 0;

    printf("welcome to my max int calculator\n");

    for (int i = 1; i <= 4 /* количество чисел для сравнения */; i++)
    {
        printf("number %d: ", i);
        scanf("%d", &user_input);
        if ((result < user_input) || (i == 1 /* на первой итерации всегда записывать */))
        {
            result = user_input;
            continue;
        }
    }

    printf("max number is %d: ", result);

    return 0;
}
