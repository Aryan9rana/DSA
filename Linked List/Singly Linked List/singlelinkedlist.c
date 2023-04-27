#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};
 void countofnodes(struct node* ); 
void printdata(struct node* );
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

    printf("address of head pointer %u\n",head);
    printf("address of link pointer in first node %u\n",head->link);
    printf("address of link pointer in 2nd node %u\n",head->link->link);
    printf("address of current pointer %u\n",current);

    countofnodes(head); 
    printdata(head);

    return 0;
}

 void countofnodes(struct node *head){
    int count=0;
    if(head==NULL){
        printf("the linked list is empty");
    }
    struct node *ptr2=NULL;
    ptr2=head;
    while(ptr2!=NULL){
        count++;
        ptr2=ptr2->link;
    }
    printf("number of nodes = %d\n",count);
} 
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