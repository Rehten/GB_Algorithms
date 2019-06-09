#include <stdio.h>

int main(int argc, char *argv[])
{
    int N;
    printf("Welcome to my N>0 Program!\n");

    printf("Enter N: ");
    scanf("%d", &N);

    while (N != 0)
    {
        if ((N%10)%2 == 0)
        {
            N /= 10;
        }
        else
        {
            printf("True - number is %d", N%10);
            // Оптимизация производительности - варианты без goto предполагают наличие еще одной переменной
            goto EndProgram; /* хотя может я просто хочу поиграться с goto */
        }
    }

    printf("False");

    EndProgram:
        return 0;
}
