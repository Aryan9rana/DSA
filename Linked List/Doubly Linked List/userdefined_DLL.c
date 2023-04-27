#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node * prev;
    int data;
    struct node * next;
}node;
node* add_toEmpty(node * head,int data){
    node* temp=malloc(sizeof(node));
    temp->prev=NULL;
    temp->next=NULL;
    temp->data=data;
    head=temp;
    return head;
}
node *add_end(node * head,int data){
    node * temp= malloc(sizeof(node));
    temp->prev=head;
    temp->data=data;
    temp->next=NULL;

    head->next=temp;
    temp->prev=head;
    return temp;
}
void printdata(node* head){
    node * ptr=head;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
node * createlist(node* head);
node *  deletenode(node * head,int pos);
node* reverselist(node* head);
int main(){
    node* head=NULL;
    int position;
    head= createlist(head);
    printf("Data in list :\n");
    printdata(head);
    printf("enter node to be deleted: ");
    scanf("%d", &position);
    head=deletenode(head,position);
    printdata(head);
    head= reverselist(head);
    printdata(head);
    return 0;
}

node * createlist(node* head){
    int n,data;
    printf("Enter the number of nodes you want in a linked list: ");
    scanf("%d", &n);
        if(n==0){
            return head;
        }
    printf("Enter data for node 1: ");
        scanf("%d", &data);
        head=add_toEmpty(head, data);

        node * ptr=head;
    for(int i=2;i<=n;i++){
            printf("Enter the data for %d node: ",i);
            scanf("%d", &data);
            ptr= add_end(ptr,data);
        }
    return head;
}

node * deletenode(node* head, int pos){
    node * temp=head;
    int p = pos;
    if(pos==1){
        head=head->next;
        free(temp);
        temp=NULL;
    }
    
        node * temp1,*temp2;
        temp1=head;
        temp=head;
        while(pos>1){
            temp1=temp1->next;
            pos--;
        }
        if(temp1->next==NULL){
            temp2=temp1->prev;
            temp2->next=NULL;
            free(temp1);
            
        }
        else{
        temp2=temp1->prev;
        temp1->next->prev=temp2;
        temp2->next=temp1->next;
        free(temp1);
        temp1=NULL;

    }
    printf("Node deleted at position: %d\n",p);
    return head;
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