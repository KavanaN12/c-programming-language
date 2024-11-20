/*continious subarray that gives maximum sum*/

#include<stdio.h>

int main()
{
    int array[]={-1,454,34,-224,78,29,2343};
    int n,a=0,b=0;
    n=sizeof(array)/4;
    printf("%d is n value\n",n);
    for (int i = 0; i < n ; i++)
    {
        int a=0;
        for (int j = i; j<n; j++)
        {
          if(a+array[j]>a)
          {
            a+=array[j];
          }
          else
          {
            break;
          }
          
        }
        if(a>b)
        {
            b=a;
        }
    }
    printf("%d",b);
    return 0;
}