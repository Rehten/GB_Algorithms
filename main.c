#include <stdio.h>
struct ChessField {
    int x;
    int y;
};

int main(int argc, char *argv[])
{
    struct ChessField field1 = {0, 0};
    struct ChessField field2 = {0, 0};

    printf("Welcome to my chessfields color compare program\n");

    printf("Enter x and y coordinates of field 1\n");
    printf("x-");
    scanf("%d", &field1.x);
    printf("y-");
    scanf("%d", &field1.y);

    printf("Enter x and y coordinates of field 2\n");
    printf("x-");
    scanf("%d", &field2.x);
    printf("y-");
    scanf("%d", &field2.y);

    printf("Field 1 is x-%d y-%d, Field 2 is x-%d and y-%d\n", field1.x, field1.y, field2.x, field2.y);

    int diff_x = (field1.x - field2.x) > 0 ? (field1.x - field2.x) : (field2.x - field1.x);
    int diff_y = (field1.y - field2.y) > 0 ? (field1.y - field2.y) : (field2.y - field1.y);

    printf("diff_x is %d, diff y is %d. Colors of field 1 and field 2 is equals: %s", diff_x, diff_y, (diff_x + diff_y)%2 == 0 ? "true" : "false");

    return 0;
}
