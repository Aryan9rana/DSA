#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
}*top=NULL;
void push(int data);
void printstack();
int pop();
int peek();
int main(){
    push(1);
    push(2);
    push(3);
    push(15);
    push(134);
    push(123);
    push(1324);
    push(1);
    printstack();
    int v= pop();
    printf("popped= %d\n",v);
    v=peek();
    printf("peek= %d\n",v);
    printstack();
    return 0;
}

void push(int data){
    struct node* new=malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;

    if(new==NULL){
        printf("Stack Overflow\n");
        exit(1);
    }
    new->next=top;
    top=new;

}

int pop(){
    if(top==NULL){
        printf("Stack is empty\n");
        exit(1);
    }
    
        struct node* temp=top;
        int value=temp->data;
        top=temp->next;
        free(temp);
        temp=NULL;
    
        return value;
}

int peek(){
    if(top==NULL){
        printf("Stack is empty\n");
        exit(1);
    }
    return top->data;
}
void printstack(){
    if(top==NULL){
        printf("Stack is empty\n");
        exit(1);
    }
    struct node* ptr=top;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
} 