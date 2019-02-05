/*
Q. in given array with  items find the  pair i ,j,k
 i.e. arr[i]+arr[j]+arr[k]=key
*/

#include <stdio.h>
#include <stdlib.h>

void SearchPair(int arr[], int key, int size)
{
    int t = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            for(int k=0;k<size;k++)
            if (arr[i] + arr[j]+arr[k] == key)
            {
                printf(" %d %d %d \t", i, j,k);
                t = 1;
            }

    if (!t)
        printf("NO PAIR PRESENT");
}

int main()
{
    int size, key;
    printf("enter size :");
    scanf("%d", &size);
    int *arr = (int *)malloc(sizeof(int) * size);
    printf("ENTER ARRAY : ");
    for (int i = 0; i < size; i++)
        scanf(" %d", &(arr[i]));
    printf("ENTER KEY : ");
    scanf("%d", &key);
    SearchPair(arr, key, size);
}