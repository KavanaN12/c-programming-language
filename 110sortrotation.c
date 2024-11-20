/*sort & make the given element first one,followed by others
 in rotation manner , ex: 123567489,given 4th element,sort 123456789,and then rotate 456789123 */

#include<stdio.h>

int main()
{
    int arr[]={9,8,44,5,3,1,2,7,6,0};
    int n,a,b,c,d,e,f;
    n=sizeof(arr)/4;
    c=n-1;
    printf("enter position of rotation");
    scanf("%d",&b);
    d=b;
    e=b;
    int ar2[n];
    for (int i = 0; i < n; i++)
    {
        ar2[i]=0;
    }
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
    printf("\n");
    for (int i = 0; i <= c-d; i++)
    {
        ar2[i]=arr[b];
        b++;
    }
    for (int j = 0; j < d; j++)
    {
        ar2[c-e+1]=arr[j];
        e--;
    }
    for (int k = 0; k < n; k++)
    {
        printf("%d\t",ar2[k]); 
    }
    for (int i = 0; i < n; i++)
    {
        if (d==ar2[i])
        {
           f=i;
           break;
        }
        else{
            f=-1;
        }
    }
    printf("\n%d is the position of given rotational position",f);
    return 0;
}