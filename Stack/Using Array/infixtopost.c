#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;

void push(char data);
int pop();
int isempty();
void intopost();
int space(char);
int precedence(char a);

int main()
{
    printf("infix expression: ");
    gets(infix);
    printf("Postfix Expression= ");
    intopost(infix);
    for(int i=0;i<strlen(postfix);i++){
        printf("%c",postfix[i]);
    }
    return 0;
}

void push(char data)
{
    top = top + 1;
    stack[top] = data;
}

int pop()
{
    if (isempty())
    {
        printf("Stack Underflow!\n");
        exit(1);
    }
    else
    {
        char val = stack[top];
        top = top - 1;
        return val;
    }
}

int isempty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void intopost()
{
    int i,j = 0;
    char symbol, next;
    for ( i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        if(!space(symbol)){
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;

        case ')':

            while ((next = pop()) != '(')
            {   
                postfix[j++] = next;
            }
            break;
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
            while (!isempty() && precedence(stack[top]) >= precedence(symbol))
            {
                postfix[j++] = pop();
            }
            push(symbol);
            break;
        default:
            postfix[j++] = symbol;
        }
        }
    }
    while (!isempty())
    {
        postfix[j++] = pop();}

        postfix[j] = '\0';
    
    
}

int precedence(char a)
{
    if (a == '+' || a == '-')
        return 1;
    else if (a == '/' || a == '*')
        return 2;
    else if (a == '^')
        return 3;
    else
    return 0;
}

int space (char s){
    if (s==' '||s=='\t'){
        return 1;
    }
    else{
        return 0;
    }
}