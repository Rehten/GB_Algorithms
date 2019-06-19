#include <stdio.h>
#include <stdlib.h>

// ВАЖНО!!! ПРОЧИТАТЬ ВЕСЬ КОММЕНТАРИЙ!!!
// Сысоев - часть 05 - вычислитель выражений (задания 03 + 05)
// суть следующая - нужно ввести строку(без пробелов и табов), начинающуюся с любых скобок (например (1+2)) - и вычислитель должен выдать 3
// для хардкора используются три вида скобок, причем [1+2] = 3*3 = 9, а {1+2} = 3+3 = 6;
// таким образом выражение {1+[2+(3+4)]} -> {1+[2+7]} -> {1+9+9} -> {19} -> 19+19 -> 38
// НЕЛЬЗЯ ВВОДИТЬ ПРОБЕЛЫ!!!p
struct StackFrame {
    int num;
    struct StackFrame* next;
};

struct BracketStackFrame {
    // хранит открывающие скобки. При встрече в строке закрывающей скобки, один стековый кадр должен освободиться
    char bracket;
    struct BracketStackFrame* next;
};

struct BracketStackFrame* next_bracket(struct BracketStackFrame* prev)
{
    struct BracketStackFrame* rslt = malloc(sizeof(struct BracketStackFrame));
    rslt->next = prev;
    return rslt;
}

void clear_frame(struct BracketStackFrame* frame)
{
    free(frame);
}

char cur_open_brace(char open_brace)
{
    switch (open_brace)
    {
        case '{':
            return '{';
        case '[':
            return '[';
        case '(':
            return '(';
        default:
            return 'o';
    }
}

char cur_closed_brace(char cur_brace)
{
    switch (cur_brace)
    {
        case '}':
            return '}';
        case ']':
            return ']';
        case ')':
            return ')';
        default:
            return 'c';
    }
}

char next_closed_brace(char open_brace)
{
    switch (open_brace)
    {
        case '{':
            return '}';
        case '[':
            return ']';
        case '(':
            return ')';
        default:
            return 'c';
    }
}

char prev_open_brace(char closed_brace)
{
    switch (closed_brace)
    {
        case '{':
            return '{';
        case ']':
            return '[';
        case ')':
            return '(';
        default:
            return 'o';
    }
}

void print_zstring(char* string, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (string[i] == 'z')
        {
            string[i] = '\0';
        }
    }

    printf("%s", string);
}

void is_string_valid(char* string, int length)
{
    int is_valid = 1;
    struct BracketStackFrame* first = calloc(sizeof(struct BracketStackFrame), 1);
    first->bracket = string[0];
    first->next = NULL;
    struct BracketStackFrame* buffer = first;
    char next_closed_bracket = next_closed_brace(first->bracket);

    for (int i = 0; i < length; i++)
    {
        if ((buffer == NULL) && ((cur_open_brace(string[i]) != 'o') || (cur_closed_brace(string[i]) != 'c')))
        {
            is_valid = 0;
            break;
        }
        if ((cur_closed_brace(string[i]) != 'c') && (next_closed_bracket != cur_closed_brace(string[i]))) {
            printf("\n%c\n", string[i]);
            is_valid = 0;
            break;
        }
        if (cur_open_brace(string[i]) != 'o')
        {
            buffer = next_bracket(buffer);
            buffer->bracket = cur_open_brace(string[i]);
            next_closed_bracket = next_closed_brace(string[i]);
            printf("\n next open is %c, and closed is %c", buffer->bracket, next_closed_bracket);
        }
        if (string[i] == next_closed_brace(buffer->bracket))
        {
            struct BracketStackFrame* b = buffer;
            buffer = buffer->next;
            clear_frame(b);
            printf("\n closed %c", next_closed_bracket);
            next_closed_bracket = next_closed_brace(buffer->bracket);
            printf(", next closed %c", next_closed_bracket);
        }
        if (string[i] == 'z')
        {
            break;
        }
    }


    if (is_valid)
    {
        printf("\nString is valid");
    }
    else
    {
        printf("\nERROR!!! String is invalid");
    }
}

int main(int argc, char *argv[])
{
    int length = 5000;
    char* user_expression = calloc(sizeof(char), (size_t)length);
    for (int i = 0; i < length; i++)
    {
        if (i + 1 != length)
        {
            user_expression[i] ='z';
        }
        else
        {
            user_expression[i] ='\0';
        }
    }

    printf("Enter your expression: ");
    scanf("%s", user_expression);

    is_string_valid(user_expression, length);

    printf("\nYou entered: ");
    print_zstring(user_expression, length);

    return 0;
}
