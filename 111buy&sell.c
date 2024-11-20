/*buy element in array on a day and sell the other 
day(can sell only if you buy before that) such that
profit is maximum*/

#include<stdio.h>

int main()
{
    int arr[]={7,1,5,3,6,4};
    int n,a,b,c,d;
    a=b=c=d=0;
    n=sizeof(arr)/4;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if(arr[i]-arr[j]<0)
            { 
                d=arr[j]-arr[i];
                if (d>c)
                {
                a=i+1;
                b=j+1;
                c=d;
                }
            }
        }
        
    }
    printf("Buy on day %d (value=%d),\nSell on day %d (value=%d),\nThe maximum Profit is %d",a,arr[a],b,arr[b],c);
    return 0;
}