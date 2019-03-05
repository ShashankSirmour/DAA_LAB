/*
Q. Priority Queue implimaintation using heap
*/

#include <stdio.h>
#include <stdlib.h>

struct heap
{
    int data;
    int priority;
};

int size = 0;
int count = 0;
void heap_push(struct heap *h, int data, int priority)
{
    int index, parent;
    index = count++;
    for (; index; index = parent)
    {
        parent = (index - 1) / 2;
        if (h[parent].priority >= priority)
            break;
        h[index].data = h[parent].data;
        h[index].priority = h[parent].priority;
    }
    h[index].data = data;
    h[index].priority = priority;
}

void heap_display(struct heap *h)
{
    for (int i = 0; i < size; i++)
        printf("|%d| priority |%d|\n", h[i].data, h[i].priority);
}

int main()
{
    size = 4;
    struct heap *h = (struct heap *)malloc(sizeof(struct heap) * size);
    ;

    heap_push(h, 1, 1);
    heap_push(h, 2, 3);
    heap_push(h, 3, 4);
    heap_push(h, 4, 2);
    heap_display(h);
}