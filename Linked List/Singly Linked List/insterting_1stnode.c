#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};
void printdata(struct node *head){
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->link;
    }
}
struct node * add_at_end(struct node * ptr, int data){
    struct node* temp = malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    ptr->link=temp;
    return temp;
}
struct node* add_beg(struct node* head,int data){
    struct node * temp = malloc(sizeof(struct node));
    temp->data= data;
    temp->link= head;
    head=temp;
    printf("node added\n");
    return head;
}
int main(){
    struct node *head=malloc(sizeof(struct node));
    head->data=1;
    head->link=NULL;
    struct node *ptr=NULL;
    ptr=head;
    ptr=add_at_end(ptr,2);
    ptr=add_at_end(ptr,3);
    ptr=add_at_end(ptr,4);
    
    printdata(head);
    head= add_beg(head,0);
    
    printdata(head);
    return 0;
}