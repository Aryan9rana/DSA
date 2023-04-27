#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};
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
void add_at_end(struct node *, int);
int main(){
     struct node *head=NULL;
    head=malloc(sizeof(struct node));
    head->data=30;
    head->link=NULL;

    struct node *current=malloc(sizeof(struct node));
    current->data=31;
    current->link=NULL;
    head->link=current;

    current=malloc(sizeof(struct node));
    current->data=33;
    current->link=NULL;
    head->link->link=current;
    printdata(head);
    int a;
    printf("Enter data to add at end of the linked list: ");
    scanf("%d", &a);
    add_at_end(head,a);
    printdata(head);
    return 0;
}

void add_at_end(struct node *head, int data){
struct node *temp=NULL;
temp=malloc(sizeof(struct node));
temp->data=data;
temp->link=NULL;
struct node* ptr= NULL;
ptr=head;
while(ptr->link!=NULL){
    ptr=ptr->link;
}
ptr->link= temp;

 printf("new node added\n"); 
}