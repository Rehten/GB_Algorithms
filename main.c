#include <stdio.h>

int main(int argc, char *argv[])
{
    int N;
    int K;
    int C = 0; /* Частное от деления N на K */
    int O = 0; /* Остаток от деления N на K */
    printf("Welcome to my N-K Program!\n");

    printf("Enter N: ");
    scanf("%d", &N);
    printf("Enter K: ");
    scanf("%d", &K);

    if ((N > 0) && (K > 0))
    {
        while (N > 0)
        {
            N -= K;
            C++;

            if (N < 0)
            {
                O = N + K;
            }
        }

        printf("Chastnoe is: %d, Ostatok is: %d", C, O);
    }

    return 0;
}
