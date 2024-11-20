#include<stdio.h>
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))
void sort(int arr[],int n);
int binary(int arr[],int low,int high,int key);
int main(){
    int n;
    printf("Enter the number of elelments\n");
    scanf("%d",&n);
    int arr[n],key;
    printf("Enter the elelments\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,n);
    printf("Enter the key element\n");
    scanf("%d",&key);
    int x=binary(arr,0,n-1,key);
    if(x!=-1){
        printf("Element found at index %d",x);
    }
    else{
        printf("Element not found");
    }
    return 0;
}

void sort(int arr[],int n){
    int min,t;
    for(int i=0;i<n;i++){
        min=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        SWAP(arr[i],arr[min],t);
    }
}

int binary(int arr[],int low,int high,int key){
    while(high>=low){
        int mid=(low+high)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}