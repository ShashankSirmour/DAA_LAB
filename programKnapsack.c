#include <stdio.h>
#include <stdlib.h>
 
typedef struct node node;
 
struct node {
  
    long int weight;
    
    long int profit;
    node *next;
};
 
int validateNode(node *dst, node *ele)
{   node *temp = dst;
    while (temp != NULL) {
        if (temp->weight <= ele->weight && ele->profit <= temp->profit) {
            return 0;
        }
        
        temp = temp->next;
    }
    
    return 1;
}
node *mergeTree(node *dst, node *src)
{
    node *temp = src;
    
    while (temp != NULL) {
        node *next = temp->next;
        if (validateNode(dst, temp) == 1) {
            temp->next = dst;
            dst = temp;
        }
        else {
            free(temp);
        }
        
        temp = next;
    }
    
    return dst;
}
 node *addNode(long int maxWeight, node *tree1, long int weight, long int profit)
{
    if (weight <= maxWeight) {
        node *temp = tree1;
        
        node *tree2 = NULL;
        
        while (temp != NULL) {
            if (temp->weight + weight <= maxWeight) {
                node *insert = (node *) malloc(sizeof(node));
                
                if (insert == NULL) {
                    exit(1);
                }
                
                insert->weight = (temp->weight + weight);
                insert->profit = (temp->profit + profit);
                insert->next   = tree2;
                
                tree2 = insert;
            }
            temp = temp->next;
        }
        
        return mergeTree(tree2, tree1);
    }
    
    return tree1;
}
 
int main(int argc, char *argv[])
{
    long int maxWeight = 0;
    long int itemsNo   = 0;
    
    scanf("%ld", &maxWeight);
    
    node *tree = (node *) malloc(sizeof(node));
    
    if (tree == NULL) {
        exit(1);
    }
    tree->weight = 0;
    tree->profit = 0;
    tree->next   = NULL;
    
    for (long int weight, profit; scanf("%ld %ld", &weight, &profit) != EOF; itemsNo++) {
        tree = addNode(maxWeight, tree, weight, profit);
    }
    long int maxProfit = 0;
    while (tree != NULL) {
        node *next = tree->next;
        if (maxProfit < tree->profit) {
            maxProfit = tree->profit;
        }
        
        free(tree);
        tree = next;
    }
    
    printf("%ld\n", maxProfit);
    
    return 0;
}
