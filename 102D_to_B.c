#include<stdio.h>
#include<math.h>
int pows(int x,int y);
int main(){
    int a,b,d,i,e,f;
    long c;
    a=b=c=e=0;
    i=0;
    printf("enter the decimal digit(less than 1024):\n");
    scanf("%d",&d);
    if(d<1024)
    {
    f=d;
    b=d%2;
    
    while (pow(2,e)<=d)
    {
        e++;
    }
    while(i<e)
    {
        a=d/2;
        //printf("%d\n",a);
        b=d%2;
        //printf("%d\n",b);
        c=(b*pows(10,i))+c;
        //printf("%ld\n",c);
        d=a;
        //printf("%d\n",d);
        i++;
        //printf("%d\n",i);
    }
    printf("Binary format of Decimal %d:  %ld",f,c);
    }
    else{
        printf("enter numbers below 1023 only");
    }
    return 0;
}
int pows(int x,int y){
    long fact=1;
    int z;
    if(y!=0){
        for (z=0;z<y;z++)
        {
            fact=fact*x;
        }
        return fact;
    }
    else{
        return 1;
    }
    //its not giving 10 power 10 a proper value,therefore
    //use only upto 1023
}