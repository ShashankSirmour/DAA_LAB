#include<stdio.h>


int size=6;


struct a{
	int profit;
	int count;
};

void display(int arr[],int size){

for(int i=0;i<size;i++)
printf(" %d \t",arr[i]);
}


void main(){

struct a data[size];
int arr[size];
printf("Enter Data");
for(int i=0;i<size;i++){
scanf("%d",&data[i].profit);
scanf("%d",&data[i].count);
arr[size]=data[i].profit/data[i].count;
}


display(arr,size);




}

