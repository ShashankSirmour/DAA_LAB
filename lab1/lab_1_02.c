/*
Q.Binary search implementation using array

*/

#include <stdio.h>
int BinarySearch(int arr[], int search, int top, int bot)
{

    if (bot > top)
        return 0;

    int mid = (top + bot) / 2;

    if (arr[mid] == search)
        return mid + 1;
    else if (arr[mid] < search)
        return BinarySearch(arr, search, top, mid + 1);
    else
        return BinarySearch(arr, search, mid - 1, bot);
}

int main()
{
    int size = 5;
    int arr[] = {1, 2, 3, 4, 5};
    printf("enter vlaue to search (in 1,2,3,4,5)");
    int search;
    scanf("%d", &search);
    search = BinarySearch(arr, search, size - 1, 0);
    search ? printf("present at %d", search) : printf("Not Present");
}