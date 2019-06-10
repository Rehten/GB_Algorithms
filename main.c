#include <stdio.h>

void binary_print(int decimal)
{
    if (decimal > 1)
    {
        binary_print(decimal/2);
        printf("%d", decimal%2);
    } else {
        printf("%d", decimal%2);
    }
}

int main(int argc, char *argv[])
{
    int decimal;

    printf("Enter decimal number. Program convert it to binary\n");
    scanf("%d", &decimal);
    printf("Binary is: ");

    binary_print(decimal);

    return 0;
}
