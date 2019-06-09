#include <stdio.h>
enum Season
{
    Winter = 1,
    Spring = 2,
    Summer = 3,
    Autumn = 4
};

char* season_by_index(enum Season season_index)
{
    switch (season_index)
    {
        case Winter:
            return "Winter";
        case Spring:
            return "Spring";
        case Summer:
            return "Summer";
        case Autumn:
            return "Autumn";
        default:
            return "Error!";
    }
}

int main()
{
    int month_index;

    printf("Welcome to my Month Index calculator\n");

    printf("Enter month index: ");
    scanf("%d", &month_index);

    printf("Your season is %s", season_by_index(month_index != 12 ? month_index/3 + 1 : Winter));

    return 0;
}
