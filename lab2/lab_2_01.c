/*
Q. in given array with duplicate items find the highest index in particular 
   Element search?
*/

#include <stdio.h>
#include <stdlib.h>

int SearchLargest(int arr[], int search, int size)
{
    if (size == 0)
        return -1;
    if (arr[size - 1] == search)
        return size;
    return SearchLargest(arr, search, size - 1);
}

int main()
{
    int size, search;
    printf("enter size :");
    scanf("%d", &size);
    int *arr = (int *)malloc(sizeof(int) * size);
    printf("ENTER ARRAY : ");
    for (int i = 0; i < size; i++)
        scanf(" %d", &(arr[i]));
    printf("ENTER search : ");
    scanf("%d", &search);
    search = SearchLargest(arr, search, size);
    (search != -1) ? printf("present at %d", search) : printf("not present");
}