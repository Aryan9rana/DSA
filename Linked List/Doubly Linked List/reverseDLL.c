#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    struct node * prev;
    int data;
    struct node *next;
}node;
node * addnode(node * head,int data){
    node* temp=malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;
    
    temp->prev=head;
    head->next=temp;

    return temp;
}
void printdata(node* head){
    node * ptr=head;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
node* reverselist(node* head){
    node* temp,*temp2;
    temp=head;
    temp2=temp->next;
    temp->next= NULL;
    temp->prev=temp2;
    while (temp2!=NULL)
    {
        temp2->prev=temp2->next;
        temp2->next=temp;
        temp=temp2;
        temp2=temp2->prev;
    }
    head=temp;
    printf("Reversed list is:\n");
return head;
}
int main(){
    node * head=malloc(sizeof(node));
    head->prev=NULL;
    head->data=1;
    head->next=NULL;
    node * ptr=NULL;
    ptr=addnode(head,2);
    ptr=addnode(ptr,3);
    ptr=addnode(ptr,4);
    printdata(head);
    head=reverselist(head);
    printdata(head);
    return 0;
}