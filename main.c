#include <stdio.h>
#include <stdlib.h>


// Сысоев - Нахождение количества маршрутов с препятствиями
void print_str (int count)
{
    char* rslt = malloc(sizeof(char) * 10);
    for (int i = 0; i < 10; i++)
    {
        if (count > 0)
        {
            // сюда поступит только число от 1 до 10; - сужающих преобразований быть не должно
            switch (count%10)
            {
                case 1:
                    rslt[i] = '1';
                    break;
                case 2:
                    rslt[i] = '2';
                    break;
                case 3:
                    rslt[i] = '3';
                    break;
                case 4:
                    rslt[i] = '4';
                    break;
                case 5:
                    rslt[i] = '5';
                    break;
                case 6:
                    rslt[i] = '6';
                    break;
                case 7:
                    rslt[i] = '7';
                    break;
                case 8:
                    rslt[i] = '8';
                    break;
                case 9:
                    rslt[i] = '9';
                    break;
                default:
                    rslt[i] = '0';
                    break;
            }
            count /= 10;
        }
        else
        {
            rslt[i] = ' ';
        }
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%c", rslt[9 - i]);
    }
}

int main(int argc, char *argv[])
{
    int** matrix = NULL;
    int matrix_size;

    printf("Enter matrix size: ");
    scanf("%d", &matrix_size);

    matrix = malloc(sizeof(int*) * matrix_size);

    for (int i = 0; i < matrix_size; i++)
    {
        matrix[i] = malloc(sizeof(int) * matrix_size);

        for (int j = 0; j < matrix_size; j++)
        {
            if ((i == 0) || (j == 0) || ((j == matrix_size - 1) || (i == matrix_size - 1)))
            {
                matrix[i][j] = 1;
            }
            else
            {
                // в 80% случаев генерирует 1, в остальных 0
                matrix[i][j] = rand()%100 < 80 ? 1 : 0;
            }
        }
    }

    // print matrix
    for (int i = 0; i < matrix_size; i++)
    {
        print_str(i + 1);
        printf(" row: [ ");
        for (int j = 0; j < matrix_size; j++)
        {
            printf(" %d", matrix[i][j]);
        }
        printf("  ]\n");
    }

    return 0;
}
