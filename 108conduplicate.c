/*to check weather there is repitation of same element in an array*/

#include<stdio.h>

int main(){
    int arr[]={23,45,1,3,4,766,23};
    int n,a=0;
    n=sizeof(arr)/4;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[i]==arr[j])
            {
                a=1;
                break;
            }
        }
        if(a==1)
        {
            break;
        }
    }
    if(a==1)
    {
       printf("true") ;
    }
    else
    {
        printf("false");
    }

}
