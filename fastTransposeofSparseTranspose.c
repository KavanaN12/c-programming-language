#include<stdio.h>
typedef struct{
    int col;
    int row;
    int value;
} terms;
terms s[50], t[50];
int sparseMatrix(int a[10][10], terms s[50], int row, int col);
void displayMatrix(terms s[50],int k);
void simpleTranspose(terms s[50],terms t[50]);
void fastTranspose(terms s[50],terms t[50]);
int main(){
    int a[10][10], row=0,col=0,k=0,l=0;
    printf("Enter the no of elements in row\n");
    scanf("%d",&row);
    printf("Enter the no of colunm\n");
    scanf("%d",&col);
    printf("Enter the matrix\n"); 
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("the array entered is \n");
    for(int i=0;i<row;i++){ 
        for(int j=0;j<col;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    k=sparseMatrix(a,s,row,col);
    printf("Sparse Matrix: \n");
    displayMatrix(s,k); 
    printf("Enter 1 for simple Transpose,\tEnter 2 for fast Transpose:\n");
    scanf("%d",&l);
    switch (l)
    {
    case 1:
        printf("Simple sparse transpose: \n");
        simpleTranspose(s,t);
        break;
    case 2:
        printf("Fast sparse transpose: \n");
        fastTranspose(s,t);
        break;
    
    default:
        printf("Enter correct value\n");
        break;
    }
    return 0;
}

int sparseMatrix(int a[10][10],terms s[50], int row, int col){
    int k=1;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(a[i][j]!=0){
                s[k].row=i;
                s[k].col=j;
                s[k].value=a[i][j]; 
                k++; 
            } 
        } 
    } 
    s[0].value=k-1;
    s[0].row=row; 
    s[0].col=col;
    return k;
}

void displayMatrix(terms s[50], int k){
    printf("\n");
    for(int i=0;i<k;i++){
        printf("%d\t%d\t%d\n",s[i].row,s[i].col,s[i].value);
    }
}

void simpleTranspose(terms s[50],terms t[50]){
    int m=1;
    for(int i=0;i<=s[0].value;i++){
        for(int j=i;j<=s[0].value;j++){
            if(s[j].col==i){
                t[m].row=s[j].col;
                t[m].col=s[j].row;
                t[m].value=s[j].value;
                m++;
            }
        }
    }
    t[0].row=s[0].col;
    t[0].col=s[0].row;
    t[0].value=s[0].value;
    displayMatrix(t,m);
}

void fastTranspose(terms s[50],terms t[50]){ 
    int a[s[0].col],d;
    for(int i=0;i<s[0].col;i++){
        a[i]=0;
    }
    int b[s[0].col+1];
    for(int i=0;i<(s[0].col+1);i++){
        b[i]=0;
    }
    for(int i=1;i<=s[0].value;i++){
        a[s[i].col]++;
    }
    b[0]=1;
    for(int i=1;i<(s[0].col+1);i++){
        b[i]=b[i-1]+a[i-1];
    }
    
    for (int i = 1; i <= s[0].value; i++)
    {
        if(b[s[i].col]!=0){
            d=b[s[i].col];
            b[s[i].col]++;
            t[d].col=s[i].row;
            t[d].row=s[i].col;
            t[d].value=s[i].value;
        }
    }
    d++;
    t[0].col=s[0].row;
    t[0].row=s[0].col;
    t[0].value=s[0].value;
    displayMatrix(t,d);
}
