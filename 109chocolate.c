/*to distribute attay elements to m number of
 people such that they have minimum difference 
 between the value of elements*/

#include<stdio.h>
int main(){
    int ac[]={7,3,2,4,9,12,56};
    int arr[]={12, 4,  7,  9,  2,  23, 25, 41, 30,
                  40, 28, 42, 30, 44, 48, 43, 50 };
    int n,m,a,b;
    n=sizeof(arr)/4;
    printf("enter the number of elements to be selected : ");
    scanf("%d",&m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if(arr[i]<arr[j])
            {
                a=arr[i];
                arr[i]=arr[j];
                arr[j]=a;
            }
            

        }
        
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\t",arr[i]);
    }
    b=arr[n-1];
    for (int i = 0; i <= n-m; i++)
    {
        a=0;
        a=arr[i+m-1]-arr[i];
        if(a<b)
        {
            b=a;
        }

    }
    printf("\nminimum difference is %d",b);
    
}