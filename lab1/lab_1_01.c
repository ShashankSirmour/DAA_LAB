/*----------------------------------------------------------
Q. program to impliment diffrent sorting function 
1. Bubble
2.Selection
3.Insertion
---------------------------------------------------------------*/

#include<stdio.h>


void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void Bubble(int arr[],int size){
    int track;
    for(int i=0;i<size-1;i++){
        track=0;
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr,j,j+1);
                track=1;
            }
            if(track==0) return;
        }
    }
}

void Insertion(int arr[],int size){
    for(int i=1;i<size;i++)
        for(int j=i;j>0;j--)
            if(arr[j]<arr[j-1])
                swap(arr,j,j-1);
            else break;
}

void Selection(int arr[],int size){
    for(int i=0;i<size-1;i++){
        int temp=i;
        for(int j=i+1;j<size;j++)
            if(arr[temp]>arr[j])
                temp=j;
        swap(arr,i,temp);
    }

}
void Display(int arr[],int size){
    for(int i=0;i<size;i++)
        printf(" %d \t",arr[i]);

}

int main(){
int size=5;
int arr[]={5,4,3,2,1};
Bubble(arr,size);
Display(arr,size);
Insertion(arr,size);
Display(arr,size);
Selection(arr,size);
Display(arr,size);
}
