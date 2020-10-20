#include <stdio.h>
#include <cs50.h>

int main(void) {
    float price = get_float("what is the price?\n");
    printf("your total is %.2f\n", price * 1.0625);
}
