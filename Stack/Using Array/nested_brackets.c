#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top=-1;

void push(int data);
int pop(void);
int isfull();
int isempty();
int peek();
int check_exp(char * exp);
int match(char a, char b);

int main(){
    char exp[MAX];
    printf("Enter the algebric expression: ");
    gets(exp);
    int check;
    check =check_exp(exp);
    if(check==1) {
        printf("Expresion is valid\n");
    }
    return 0;
}



void push(int data){
    if(top==MAX-1){
        printf("Stack Overflow!\n");
        return;
    }
    top=top+1;
    stack[top]=data;
}

int pop(void){
    if(top==-1){
        printf("Stack Underflow!\n");
        exit(1);
    }

    int value= stack[top];
    top=top-1;
    return value;
}

int peek(){
    if (isempty()==1){
        exit(1);
    }
    return stack[top];
}
  
int isfull(void){
    if(top==MAX-1)
        return 1;
    
    else 
        return 0;
}
int isempty(void){
    if(top==-1)
        return 1;

    else
        return 0;
}

int check_exp (char * exp){
    int i,val;
    for (i=0;i<strlen(exp);i++){
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='['||exp[i]=='<'){
            push(exp[i]);
        }
        else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'||exp[i]=='>'){
            if(isempty()){
                    printf("Expresion is invalid stack empty\n");
                    return 0;
                }
            else{
            val=pop();
            if(!match(val,exp[i])){
                printf("Expression is invalid\n");
                return 0;
            }
            }
        }
    }
    if(isempty()){
        printf("Expresiion ballanced\n");
        return 1;
    }
    else{
        printf("Left brackets are more than right\n");
        return 0;
    }
}

int match(char a,char b){
    if(a=='('&&b==')'){
        return 1;
    }
    if(a=='{'&&b=='}'){
        return 1;
    }
    if(a=='['&&b==']'){
        return 1;
    }
    return 0;
}