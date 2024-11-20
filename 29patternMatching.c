#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int endIndices(char s[100],char p[100]);
void studyPattern(char p[100],int sp[100]);
int kmpAlgorithm();
int main(){
    char s[100];
    printf("Enter the main String:\n");
    scanf("%s",&s);
    char p[100];
    printf("Enter the pattern:\n");
    scanf("%s",&p);
    int key=0,x=0;
    int sp[100];
    printf("Enter 1: via End indices\nEnter 2: via KMP Algorithm\n");
    scanf("%d",&key);
    switch (key)
    {
    case 1:
        x=endIndices(s,p);
        break;
    
    default:
        studyPattern(p,sp);
        x=kmpAlgorithm(s,p,sp);
        break;
    }
    if(x!=-1){
        printf("%d is the index of pattern\n",x);
    }
    else{
        printf("Pattern not found\n");
    }
    return 0;
}
int endIndices(char s[100],char p[100]){
    int start=0,lasts=strlen(s)-1,end=strlen(p)-1,lastp=strlen(p)-1;
    int j=0,i=start;
    while (j<=lastp && end<=lasts)
    {
        if(s[end]==p[lastp]){
            for (i = start; i < end; i++)
            {
                if(s[i]==p[j]){
                    j++;
                }
                else{
                    end++;
                    start++;
                    j=0;
                    break;
                }
                if(j==lastp){
                    return start;
                }
            } 
        }
        else{
            end++;
            start++;
        }
    }
    return -1;
    
}
void studyPattern(char p[100],int sp[100]){
    sp[0]=-1;
    int i=0,j=1,k=-1;
    while(j<strlen(p)){
        if(p[i]!=p[j] && i<=0){
            k=-1;
            sp[j]=k;
            j++;
        }
        else if(p[i]!=p[j] && i>0){
            k=-2;
            i--;
        }
        else{
            sp[j]=++k;
            i++;
            j++;
        }
    }
}
int kmpAlgorithm(char s[100],char p[100],int sp[100]){
    int lens=strlen(s);
    int lenp=strlen(p);
    int l=0,m=0;
    while (l<lens && m<lenp)
    {
        if(s[l]==p[m]){
            l++;
            m++;
        }
        else{
            if(sp[m]>0){
                m=sp[m];\
                l++;
            }
            else if(m==0){
                l++;
            }
            else{
                m=0;
            }
        }
    }
    if(m==lenp){
        return l-m;
    }
    return -1;
}