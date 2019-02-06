/*
Q.finding min max using divide and conqure  technique

*/




#include <stdio.h>

int min(int arr[], int top, int bot)
{    if (top == bot)
        return arr[top];
    int mid = (top + bot) / 2;
    int a = min(arr, mid, bot);
    int b = min(arr, top, mid + 1);
    return a > b ? b : a;
}

int max(int arr[], int top, int bot)
{
    if (top == bot)
        return arr[top];
    int mid = (top + bot) / 2;
    int a = max(arr, mid, bot);
    int b = max(arr, top, mid + 1);
    return a > b ? a : b;
}
int main()
{
    int arr[] = {4, 2, 2, 4, 5};
    printf("%d", min(arr, 4, 0));
    printf("%d", max(arr, 4, 0));
}
