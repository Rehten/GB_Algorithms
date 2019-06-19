#include <stdio.h>
#include <stdlib.h>


// Сысоев - Перевод десятичной в двоичную на стеке
struct StackFrame {
    int num[5000];
    struct StackFrame* next;
};

struct StackFrame* next_frame(struct StackFrame* prev)
{
    prev->next = malloc(sizeof(struct StackFrame));
    return prev->next;
}

int main(int argc, char *argv[])
{
    struct StackFrame* current = malloc(sizeof(struct StackFrame));

    while (current != NULL)
    {
        current = next_frame(current);
        printf("\nCurrent is %p", current);
    }

    printf("Error, too much memory allocated");

    return 0;
}
