#include <stdio.h>
#include <stdlib.h>


// Сысоев - Нахождение наибольшей общей подпоследовательности
struct Result {
    char* string;
    int length;
};

int main(int argc, char *argv[])
{
    char* string_one = calloc(sizeof(char), 10);
    char* string_two = calloc(sizeof(char), 10);

    printf("Enter two strings: max length is 10, after last three letters :wq program exit from string enter mode\n");
    printf("\nEnter first string: - any letter. :wq for finished");
    for (int i = 0; i < 10; i++)
    {
        scanf("%c", &string_one[i]);
    }

    printf("\nFirst string is: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%c", string_one[i]);
    }

    printf("\nEnter second string: - any letter. :wq for finished");
    for (int i = 0; i < 10; i++)
    {
        scanf("%c", &string_two[i]);
    }

    printf("\nSecond string is: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%c", string_two[i]);
    }

    struct Result* results = calloc(sizeof(struct Result), 10);
    int rslt_index = 0;

    for (int i = 0; i < 10; i++)
    {
        results[rslt_index].length = 0;
        results[rslt_index].string = calloc(sizeof(char), 10);
        for (int j = 0; j < 10; j++)
        {
            if (string_one[i] == string_two[j])
            {
                results[rslt_index].string[results[rslt_index].length] = string_one[i];
                results[rslt_index].length++;
            }
        }
        printf("\n Solution %d length is %d and string is: ", rslt_index + 1, results[rslt_index].length);
        for (int k = 0; k < results[rslt_index].length; k++)
        {
            printf("%c", results[rslt_index].string[k]);
        }
        rslt_index++;
    }

    int rslt_successful_index = 0;
    for (int i = 0; i < 10; i++)
    {
        if (results[i].length > results[rslt_successful_index].length)
        {
            rslt_successful_index = i;
        }
    }

    printf("\n\nGeneral subtype of two types is: ");
    for (int i = 0; i < results[rslt_successful_index].length; i++)
    {
        printf("%c", results[rslt_successful_index].string[i]);
    }

    return 0;
}
