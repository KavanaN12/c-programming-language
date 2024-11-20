#include<stdio.h>

int main()
{
    int rev[]={234,454,345,86,324};
    int n,a,b,c,d;
    n=sizeof(rev)/4;
    for (int i = 0; i < n/2 ; i++)
    {
        a=rev[i];
        rev[i]=rev[n-i-1];
        rev[n-i-1]=a;

    }
    for (int i = 0; i < n; i++)
    {
        printf("%d,\t",rev[i]);
    }
    printf("is the reverse of given array");
    
}