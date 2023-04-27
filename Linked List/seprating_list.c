#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node * next;
}node;

node * push(node*head,int data){
    node * temp=malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;
    head->next=temp;

    return temp;
}
void printlist(node* head){
    node * temp=head;
    while(temp){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void swap(node* a,node* b){
    int temp=a->data;
    a->data=b->data;
    b->data=temp;
}
void sort(node * head){
    node* temp;
    node* temp2=NULL;
    int s;
    do{
        s=0;
        temp=head;
        while(temp->next!=temp2){
        if(temp->data>temp->next->data){
            swap(temp,temp->next);
            s=1;
        }
        temp=temp->next;
        }
        temp2=temp;
    }while(s);
}

void seperate(node * head,int data){
    node * temp=head;
    while(temp->data!=data){
        temp=temp->next;
    }
    node * p1=head;
    while(p1->next!=temp){
        p1=p1->next;
    }
    node * h1=head;
    p1->next=NULL;
    node * h2=temp->next;
    printlist(h1);
    printlist(h2);
}
int main(){
    node * head=malloc(sizeof(node));
    head->data=4;
    head->next=NULL;
    node* ptr=head;
    ptr=push(ptr,3);
    ptr=push(ptr,2);
    ptr=push(ptr,6);
    ptr=push(ptr,1);
    ptr=push(ptr,4);

    printlist(head);
    sort(head);
    printlist(head);
    seperate(head, 4);
    printlist(head);
    return 0;
}