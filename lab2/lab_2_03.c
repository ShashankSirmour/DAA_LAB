/*
Q. in given array with  items find the   simultaneously chancge in increasing ordr to decreasing order

*/

#include <stdio.h>
#include <stdlib.h>

int  KSearch(int arr[],  int size)
{
    for (int i = 0; i < size; i++)
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
            return i;
}   

int main()
{
    int size;
    printf("enter size :");
    scanf("%d", &size);
    int *arr = (int *)malloc(sizeof(int) * size);
    printf("ENTER ARRAY : ");
    for (int i = 0; i < size; i++)
        scanf(" %d", &(arr[i]));
    printf("%d is k",KSearch(arr, size));
}