#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int stack[MAX];
int top=-1;

void printstack();
int isFull();
int isEmpty();
void push(int data);
int pop(void);

int main(){
    int choice,data,check;
    while(1){
        printf("1- Push\n");
        printf("2- Pop\n");
        printf("3- IsEmpty\n");
        printf("4- IsFull\n");
        printf("5- Print stack\n");
        printf("6- Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;

            case 2:
                printf("pop= ");
                int data=pop();
                printf("%d\n",data);
                break;

            case 3:
                check=isFull();
                if(check==1){
                printf("Stack is Full\n");
                break;
                }
                else{
                    printf("Stack is not full\n");
                    break;
                }
            case 4:
                check=isEmpty();
                if(check==1){
                printf("Stack is Empty\n");
                break;
                }
                else{
                    printf("Stack is not Empty\n");
                    break;
                }
            
            case 5:
                printstack();
                break;
            
            case 6:
                exit(1);
            break;
        }

    }
    return 0;
}
void push(int data)
{
    if(isFull()==1){
        printf("Stack Overflow!!\n");
        return;
    }
    top=top+1;
    stack[top]=data;
}

int pop(void){
    if(isEmpty()==1){
        printf("Stack UnderFlow!\n");
        exit(1);
    }
    int value = stack[top];
    top=top-1;
    return value;
}
int isFull(void){
    if(top==MAX-1)
        return 1;
    else
        return 0;
}
int isEmpty(void){
    if(top==-1)
        return 1;
    else
        return 0;
}
void printstack(void){
    if(isEmpty()==1){
        printf("Stack is empty\n");
        return;
    }
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
    printf("\n");
}