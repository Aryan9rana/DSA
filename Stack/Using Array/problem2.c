#include <stdio.h>
#include <stdlib.h>
#define MAX 50

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
void prime_fac(int num){
    int i=2;
    while(num!=1){
        while(num%i==0){
            push(i);
            num=num/i;
        }
        i++;
    }
    printf("Prime factors of number: ");
    while(top!=-1){
        printf("%d ",pop());
    }
}
int main(){
    int num;
    printf("enter a number:");
    scanf("%d", &num);
    prime_fac(num);
    return 0;
}