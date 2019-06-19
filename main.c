#include <stdio.h>
#include <stdlib.h>


// Сысоев - Перевод десятичной в двоичную на стеке
struct StackFrame {
    int num;
    struct StackFrame* next;
};

int main(int argc, char *argv[])
{
    printf("Welcome to the decimal to binery converter");
    int decimal_number;
    int* binary = calloc(sizeof(int), 100);

    printf("\nEnter decimal: ");
    scanf("%d", &decimal_number);

    printf("Your number is %d\n", decimal_number);
    struct StackFrame* first_frame;
    struct StackFrame* buffer = NULL;
    int is_stack_empty = 1;

    while (decimal_number != 0)
    {
        struct StackFrame* frame = calloc(sizeof(struct StackFrame), 1);
        if (decimal_number == 1)
        {
            frame->num = decimal_number;
            decimal_number = 0;
        }
        else
        {
            frame->num = decimal_number%2;
        }
        frame->next = NULL;
        if (is_stack_empty == 1)
        {
            first_frame = frame;
            buffer = frame;
            is_stack_empty = 0;
        }
        else
        {
            buffer->next = frame;
            buffer = frame;
        }

        decimal_number /= 2;

    }

    buffer = first_frame;

    //Распечатка данных со стека
    printf("Your number in binery is: ");
    while (buffer->next != NULL)
    {
        printf("%d", buffer->num);
        buffer = buffer->next;
    }
    // распечатка последнего числа
    printf("%d", buffer->num);

    return 0;
}
