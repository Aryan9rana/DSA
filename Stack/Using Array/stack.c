#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int stack[MAX];
int top=-1;

void push(int data);
int pop(void);
void print_stack(void);
int isfull(void);
int main(){
    int data;
    push(1);
    push(2);
    push(3);
    push(4);
    data=pop();
    printf("%d\n",data);
    data=pop();
    printf("%d\n",data); 
    print_stack();
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
void print_stack(void){
    if(top==-1){
        printf("Stack is Empty\n");
        return;
    }
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
    printf("\n");
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