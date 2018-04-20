#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main(void)
{

    int x[]={2,3};

    swap(&x[0],&x[1]);

    printf("first X: %i Second X: %i\n", x[0], x[1]);
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}