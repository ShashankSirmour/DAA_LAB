#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void minHeapDelete(int arr[], int *n, int pos)
{
    arr[pos] = arr[*n - 1];
    *n -= 1;
    buildMaxHeap(arr, n);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d\t",arr[i]);
    printf("\n");    
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr,n);
    maxHeapify(arr, n);
    printArray(arr, n);
}