#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * link;
};
struct node * addnode(struct node * head,int data){
    struct node * ptr=malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=NULL;
    head->link=ptr;
    return ptr;
}
void printdata(struct node* head){
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr= ptr->link;
    }
}
struct node* reverse_list(struct node* head);
int main(){
    struct node* head= malloc(sizeof(struct node));
    head->data=1;
    head->link=NULL;
    struct node * ptr=NULL;
    ptr=addnode(head,2);
    ptr=addnode(ptr,3);
    ptr=addnode(ptr,4);
    printdata(head);
    head=reverse_list(head);
    printdata(head);
    return 0;
}

struct node* reverse_list(struct node* head){
    struct node * prev=NULL;
    struct node * next=NULL;
   while(head!=NULL){
    next=head->link;
    head->link=prev;
    prev=head;
    head=next;
   }
printf("Linked list reversed\n");
return prev;
}