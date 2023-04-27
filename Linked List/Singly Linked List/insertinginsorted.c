#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *  next;
}node;

node* addnode(node*head, int data){
    node*temp=malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;
    head->next=temp;
    return temp;
}

void printdata(node*head){
    node*ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

node* insert(node * head, int data);


int main(){
    node*head=malloc(sizeof(node));
    head->data=1;
    head->next=NULL;
    node*ptr=head;
    ptr=addnode(ptr,2);
    ptr=addnode(ptr,3);
    ptr=addnode(ptr,4);
    ptr=addnode(ptr,5);
    printf("Sorted list before: \n");
    printdata(head);
    printf("Enter the number to be added: ");
    int el;
    scanf("%d", &el);
    head=insert(head, el);
    printdata(head);
    return 0;
}

node* insert(node*head, int data){
    node*temp=malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;
    int key = data;
    node*ptr=NULL;
    if(head==NULL||head->data>key){
        temp->next=head;
        head=temp;
    }
    else{
        ptr=head;
        while(ptr->next!=NULL&&ptr->data<key){
            ptr=ptr->next;
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }
    return head;
}