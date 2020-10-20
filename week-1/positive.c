#include <stdio.h>
#include <cs50.h>

int get_positive_int(void);

int main(void)
{
    int n = get_positive_int();
    printf("your choice: %d\n", n);
}

int get_positive_int(void)
{
    int n;
    do {
        n = get_int("positive integer: ");
    } while (n < 1);

    return n;
}
