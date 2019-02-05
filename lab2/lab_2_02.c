/*
Q. in given array with  items find the  pair i ,j
 i.e. arr[i]^2+arr[j]^2=key
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void SearchPair(int arr[], int key, int size)
{
    int t = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if ((pow(arr[i], 2) + pow(arr[j], 2)) == key)
            {
                printf(" %d %d \t", i, j);
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