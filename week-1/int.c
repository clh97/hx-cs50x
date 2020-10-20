#include <stdio.h>
#include <cs50.h>

int main(void) {
    int age = get_int("what is your age?\n");
    int days = age * 365;
    printf("you are at least %u days old.", days);
}
