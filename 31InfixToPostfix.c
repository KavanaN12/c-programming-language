#include<stdio.h>
#include<string.h>
#include<ctype.h>
typedef struct Stack{
    int a;
    char item[30];
}stack;
stack convertion(char eqn[30]);
void compare(stack *operator,char c,stack* pfexp);
char pop(stack *Operand);
void push(stack *Operand,char b);
int com(char key);
int main(){
    char eqn[30];
    stack pfexp;
    printf("Enter the expression:\n");
    scanf("%s",&eqn);
    pfexp=convertion(eqn);
    for(int i=0;i<=pfexp.a;i++){
        printf("%c",pfexp.item[i]);
    }
    return 0;
}
stack convertion(char eqn[30]){
    stack pfexp;
    stack operator;
    operator.a=pfexp.a=-1;
    char op,c;
    int k=0;
    for(int i=0;(c=eqn[i])!='\0';i++){
        if(isdigit(c)){
            push(&pfexp,c);
        }
        else if(c=='('){
            push(&operator,c);
        }
        else if(c==')'){
            while(com(c)!=com(operator.item[operator.a]) && operator.a>=0){
                op=pop(&operator);
                push(&pfexp,op);
            }
            if(com(c)==com(operator.item[operator.a])){
                pop(&operator);
            }
        }
        else{
            compare(&operator,c,&pfexp);
        }
    }
    k=operator.a;
    for(int i=0;i<=k;i++){
        op=pop(&operator);
        push(&pfexp,op);
    }
    return pfexp;
}
void compare(stack *operator,char c,stack* pfexp){
    char op1='+';
    if(operator->a>=0 ){
        if(com(c)<=com(operator->item[operator->a])){
            if(operator->item[operator->a]!='('){
                op1=pop(operator);
                push(pfexp,op1);
                compare(operator,c,pfexp);
            }
            else{
                push(operator,c);
            }
        }
        else{
            push(operator,c);
        }
    }
    else{
        push(operator,c);
    }
}
int com(char key){
    switch (key)
    {
    case '(':
    case ')':
        return 2;
        break;
    case '+':
    case '-':
        return 0;
        break;
    case '*':
    case '/':
        return 1;
        break;
    default:
        return 3;
        break;
    }
}
char pop(stack *Operand){
    return Operand->item[(Operand->a)--];
}
void push(stack *Operand,char b){
    Operand->item[++Operand->a]=b;
}