#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
}*head;


void createlist(int n);
void printlist();
void reverse();
struct node* middle();
void insert_at_pos(int pos, int data);
struct node * newnode(struct node* ptr, int data);



int main(){
    int n;
    printf("Enter the Number of nodes: ");
    scanf("%d", &n);
    createlist(n);
    printlist();
    // reverse();
    // printf("After reversal: ");
    // printlist();
    struct node * mid=middle();
    printf("mid= %d\n",mid->data);
    insert_at_pos(2,mid);
    printlist();
    return 0;
}

void createlist(int n){
    int d;
    printf("Enter data for node 1:");
    scanf("%d", &d);
    head=malloc(sizeof(struct node));
    head->data=d;
    head->next=NULL;
    struct node * ptr=head;
    for ( int i= 2;i<=n;i++)
    {   

        printf("Enter data for node %d: ",i);
        scanf("%d", &d);
        ptr=newnode(ptr,d);
        
    }
}

void printlist(){
    struct node * temp=head;
    while(temp!=NULL){
        printf("%d-->",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void reverse(){
    
    struct node * t1=head;
   struct  node * t2=NULL;
   struct  node * t3=NULL;
    while(t1!=NULL)
    {
        t3=t1->next;
        t1->next=t2;
        t2=t1;
        t1=t3;

    }
    head=t2;

}

struct node * middle(){
    struct node * mid=NULL;
    struct node * slow=head;
    struct node * fast=head;

    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
    }
    mid=slow;
    return mid;
}
struct node * newnode(struct node* ptr, int data)
{
    struct node * new=malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    ptr->next=new;

    return new;
}
void insert_at_pos(int pos, int data){
    struct node * new= malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    if(pos==1){
        new->next=head;
        head=new;
    }
    struct node * t=head;
 
    while(pos!=2){
        t=t->next;
        pos--;
    }
    new->next=t->next;
    t->next=new;
}