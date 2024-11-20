#include<stdio.h>

int main()
{
    int array[]={1,3,3,454,654,5654,345};
    int n,a;
    n=sizeof(array)/4;
    //sorting of an array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1 ; j++)
        {
            if(array[j]<array[j+1])
            {
                a=array[j];
                array[j]=array[j+1];
                array[j+1]=a;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",array[i]);
    }
    printf("%d is the maximum of given array\n",array[0]);
    printf("%d is the minimum of given array",array[n-1]);
    return 0;
}