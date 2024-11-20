#include<stdio.h>
int main()
{
    int m,n,fact=1;
    printf("enter the number");
    scanf("%d",&m);
    n=m;
    for (int i = 1; i <=n ; i++)
    {
        if(n>0)
        {
        fact*=i;
        }
    }
    printf("the factorial of %d is %d",m,fact);
    return 0;
}