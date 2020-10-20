#include <stdio.h>

void cough(int n);

int main(void)
{
    cough(3);
}

// Cough once
void cough(int n)
{
    for (int i = 0; i < n; i++) {
        printf("cough\n");
    }
}
