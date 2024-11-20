#include<stdio.h>
#include<math.h>
int main(){
    int a,b,c,d;
    a=b=c=0;
    printf("enter the binary digit:\n");
    scanf("%ld",&d);
    while(d>0)
    {
        a=d%10;
        if(a==0||a==1)
        {
        b+=a*pow(2,c);
        c++;
        }
        else
        {
            b=0;
            break;
        }
        d=d/10;
        
    }
    printf("the decimal digit is %d", b);
}