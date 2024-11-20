#include<stdio.h>
int main()
{
    int m,n,fact=1;
    printf("enter the number");
    scanf("%d",&m);
    n=m;
        for (int i = 0; i <=n; i++)
        {
            if(n>0 && (n-1)>0)
            {
                fact*=n*(n-1);
            }
            n-=2;
        }
        printf("the factorial of %d is %d",m,fact);
    return 0;
}