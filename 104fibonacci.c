#include<stdio.h>
int main()
{
    int m,n,o,p;
    printf("enterthe number of terms : ");
    scanf("%d", &m);
    n=0;o=1;
    if (m==0)
    {
        printf("enter valid number of terms you want");
    }
    else
    {
        for (int i = 1; i <=m ; i++)
        {
            printf("%d\t",n);
            p=n+o;
            n=o;
            o=p;
        }
    }
    return 0;
    
}