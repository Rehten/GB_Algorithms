#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_with_crand ()
{
    return (rand() * time(NULL))%100;
}

int rand_without_crand ()
{
    int a, b;
    b = time(NULL)%10;
    a = time(NULL)%10 * time(NULL)%10;

    return (a * (time(NULL)%100 + time(NULL)%2) + b) % 100;
}

int main(int argc, char *argv[])
{
    printf("%d, %d", rand_with_crand(), rand_without_crand());

    return 0;
}