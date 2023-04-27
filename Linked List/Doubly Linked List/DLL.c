#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node* prev;
    int data;
    struct node* next;
}node;
void printdata(node* head){
    node * ptr=head;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
node * add_beg(node*,int);
node* add_end(node*head,int data);
node * add_pos(node*head , int pos, int data);
int main(){
    node* head = malloc(sizeof(node));
    node *ptr =head;
    head->prev=NULL;
    head->data=1;
    head->next=NULL;
    printdata(head);
//   head=add_beg(head,0);
    ptr=add_end(head, 2);
    ptr=add_end(ptr, 3);
    ptr=add_end(ptr, 4);
    printdata(head);
    head=add_pos(head,5,5);
    printdata(head);
    return 0;
}

node * add_beg(node * head, int data){
    node * temp = malloc(sizeof(node));
    temp->data= data;
    temp->prev= NULL;
    temp->next= head;
    head->prev=temp;
    head=temp;
    printf("Node added at beginning\n");
    return head;
}

node* add_end(node*head,int data){
    node*temp=malloc(sizeof(node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;

    /* node*ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    } */
    head->next=temp;
    temp->prev=head;
    printf("Node added at the end\n");
    return temp;
}

node * add_pos(node*head , int pos, int data){
    int p=pos;
     node* temp=malloc(sizeof(node));
     temp->prev=NULL;
     temp->data=data;
     temp->next=NULL;
    if (pos==1){
        temp->prev=NULL;
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    else{
        node* ptr1=head;
        node* ptr2=head;
        pos--;
        while(pos!=1){
            ptr1=ptr1->next;
            pos--;
        }
        ptr2=ptr1->next;
        temp->prev=ptr1;
        temp->next=ptr2;
        ptr1->next=temp;
        ptr2->prev=temp;
    }
    printf("Node added at position %d\n",p);
    return head;
        
}