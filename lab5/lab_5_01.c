/*
Q.linear vs binary graph ploting 
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int LinearSearch(int arr[],int bot,int size,int search){
  if(bot==size)return -1;
  if(arr[bot]==search)
	return bot;
  return LinearSearch(arr,bot+1,size,search);
}

int BinarySearch(int arr[],int top,int bot,int search){
if(top<bot) return -1;
  
int mid=(top+bot)/2;
if(arr[mid]==search) return mid;
if(arr[mid]>search)
	return BinarySearch(arr, mid-1,bot,search);

return BinarySearch(arr,top,mid+1,search);
}

int main(){
int e,s,first,second,size,search;
for(int re=0;re<5;re++)
{
int *arr;

size=rand()%10;
arr=(int *)malloc(sizeof(int)*size);

for(int i=0;i<size;i++)
	arr[i]=rand()%10;

search=rand()%10;
s=clock();
LinearSearch(arr,0,size-1,search);
e=clock();
first=e-s;
s=clock();
BinarySearch(arr,size-1,0,search);
e=clock();
second=e-s;
printf("\nTime Linear %d and Binary %d for n %d",first,second,size);
 
free(arr);
}

}
