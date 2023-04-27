#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * link;
};
struct node* add_node(struct node*,int);
void printdata(struct node *head){
    
    if(head==NULL){
        printf("the linked list is empty");
    }
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->link;
    }
}
int main(){
    struct node *head= malloc(sizeof(struct node));
    head->data=20;
    head->link=NULL;
    struct node * ptr=NULL;
    ptr=add_node(head,60);
    ptr=add_node(ptr,120);
    ptr=add_node(ptr,180);
    printdata(head);
    return 0;
}

struct node* add_node(struct node * ptr, int data){
     struct node * temp=malloc(sizeof(struct node));
     temp->data=data;
     temp->link=NULL;

     ptr->link=temp;
     return temp;
}