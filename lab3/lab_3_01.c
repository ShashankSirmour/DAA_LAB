/*
program to find cpu time to add two no.
*/


#include <stdio.h>
#include <time.h>
int add(int a, int b)
{
    int s = clock();

    int c = a + b;
    int e = clock();
    printf("%d", e - s);
}

int main()
{

    add(100000000000, 288888888888888);
}