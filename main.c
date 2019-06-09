#include <stdio.h>
struct ChessField {
    int x;
    int y;
};

int main(int argc, char *argv[])
{
    int a;
    int b;
    printf("Welcome to my squares and cubes program\n");

    printf("enter a: ");
    scanf("%d", &a);
    printf("enter b: ");
    scanf("%d", &b);

    if ((a <= b) && (a >=0) && (b >=0))
    {
        printf("a is equal %d, and b is equal to %d\n", a, b);

        for (int i = 0; i < b; i++)
        {
            if ((i * i >= a) && (i * i <= b))
            {
                printf("number %d: ", i);
                printf(", square: %d", i * i);
            }
            else
            {
                goto EndIteration; /* рискованный ход для оптимизации алгоритма по скорости */
            }

            if ((i * i * i >= a) && (i * i * i <= b))
            {
                printf(", cube: %d", i * i * i);
            }
            printf("\n");
            EndIteration:
                continue;
        }

        printf("calculation ended.");
    }
    else
        {
        printf("Error");
    }

    return 0;
}
