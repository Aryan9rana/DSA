#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX];
int top=-1;

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
void binary(int num){
    int i=2;
    int reminder;
    while(num!=0){
        reminder=num%i;
        push(reminder);
        num=num/i;
    }
    printf("Binary: ");
    while(top!=-1){
        printf("%d ",pop());
    }
}

int main(){
    int num;
    printf("enter a number:");
    scanf("%d", &num);
   binary(num);
    return 0;
}