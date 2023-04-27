#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * link;
};
struct node* add_node(struct node*,int);
void add_pos ( struct node *, int , int);
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
    head->data=1;
    head->link=NULL;
    struct node * ptr=NULL;
    ptr=add_node(head,2);
    ptr=add_node(ptr,3);
    ptr=add_node(ptr,4);
    printdata(head);
    add_pos(head,5,3);
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

void add_pos ( struct node *head, int data, int pos){
    struct node* ptr2= malloc(sizeof(struct node));
    ptr2->data=data;
    ptr2->link=NULL;
    struct node* ptr = head;
    pos--;
    while(pos!=1){
        ptr=ptr->link;
        pos--;
    }
    ptr2->link=ptr->link;
    ptr->link= ptr2;
printf("Node added\n");
}