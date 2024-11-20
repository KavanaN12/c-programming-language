#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct Stack{
    int top;
    double item[20];
}stack;
double evaluate(char postfix[30]);
void push(stack *Operand,double a);
double pop(stack *Operand);
double operation(char c,double op1,double op2);
int main(){
    double x;
    char postfix[30];
    printf("Enter the postfix Expression: \n");
    scanf("%s",postfix);
    x=evaluate(postfix);
    printf("%.2f",x);
}
double evaluate(char postfix[30]){
    stack Operand;
    double op1,op2,V;
    Operand.top=-1;
    char c;
    for(int i=0;(c=postfix[i])!='\0';i++){
        if(isdigit(c)){
            push(&Operand,(int)(c-'0'));
        }
        else{
            op1=pop(&Operand);
            op2=pop(&Operand);
            V=operation(c,op2,op1);
            push(&Operand,V);
        }
    }
    return pop(&Operand);
}
void push(stack *Operand,double a){
    Operand->top=Operand->top+1;
    Operand->item[Operand->top]=a;
}
double pop(stack *Operand){
    return Operand->item[(Operand->top)--];
}
double operation(char c,double op1,double op2){
    switch(c){
        case '+':
            return op1+op2;
        case '-':
            return op1-op2;
        case '*':
            return op1*op2;
        case '/':
            return op1/op2;
    }
}