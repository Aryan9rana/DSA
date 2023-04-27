//stack[0] as topmost element of stack
#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int stack[MAX];
int first=-1;

void push(int data);
int pop(void);
void print_stack(void);
void isfull();
void isempty();
int peek();


int main(){
    int data;
    push(1);
    push(2);
    push(3);
    push(4);
    print_stack();
    data=pop();
    data=pop();
    data=pop();
    printf("%d\n",data);
    isempty();
    isfull();
    int v=peek();
    printf("%d\n",v);

    return 0;
}

void push(int data){
    first=first+1;
    for(int i =first; i>=0;i--){
        stack[i]=stack[i-1];
    }
    stack[0]=data;
}

 int pop(void){
    if(first==-1){
        printf("Stack Underflow!\n");
        exit(1);
    }

    int value= stack[0];
    for(int i=0;i<first;i++){
        stack[i]=stack[i+1];
    }
    first=first-1;
    return value;
} 
void print_stack(void){
    if(first==-1){
        printf("Stack is Empty\n");
        return;
    }
    for(int i=0;i<=first;i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}
  
void isfull(){
    if(first==MAX-1){
        printf("stack is Full\n");
        return ;
    }
    else{
        printf("Not FULL\n");
        return ;
    }
}
void isempty(){
    if(first==-1){
        printf("stack is empty\n");
        return ;
    }
    else{
        printf("Not empty\n");
        return ;
    }
}

int peek(){
    if(first==-1){
        printf("stack underflow\n");
        exit(1);
    }
    return stack[0];
}