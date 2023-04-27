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

void printdata (struct node* head){
    struct node *ptr=head;
    if(head==NULL){
        printf("Linked list is empty\n");
    }
    while(ptr!=NULL){
        printf("%d\n", ptr->data);
        ptr=ptr->link;
    }
}

struct node * del_list(struct node * head);

int main(){
    struct node* head= malloc(sizeof(struct node));
    head->data=1;
    head->link=NULL;
    struct node * ptr=NULL;
    ptr=addnode(head,2);
    ptr=addnode(ptr,3);
    ptr=addnode(ptr,4);

    printdata(head);
    head=del_list(head);
    if(head==NULL){
        printf("head is NULL\n");
    }
    printdata(head);

    return 0;
}

struct node * del_list(struct node * head){
    struct node * temp=head;
    while(temp!=NULL){
        temp=temp->link;
        free(head);
        head=temp;
    }
    printf("list deleted succesfully\n");
    return head;
}