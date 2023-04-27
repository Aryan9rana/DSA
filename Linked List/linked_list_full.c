#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};
struct node* push(struct node* , int);
struct node * createlist();
void printlist(struct node * head);
struct node * delete(struct node *,int);
void search(struct node * head,int data);
int main(){
    struct node* head= createlist();
    printlist(head);
    int p;
    printf("Enter data to search: ");
    scanf("%d", &p);
    // head=delete(head,p);
    // printlist(head);
    search(head,p);
    return 0;
}
struct node * push(struct node * ptr,int data){
    struct node * temp=malloc(sizeof(struct node) );
    temp->data=data;
    temp->next=NULL;
    ptr->next=temp;

    return temp;
}

struct node * createlist(){
    struct node * head= malloc(sizeof(struct node));
    int n;
    printf("enter number of nodes: ");
    scanf("%d", &n);
   if (n!=0)
   { 
    int d;
    printf("enter head data: ");
    scanf("%d", &d);
    head->data=d;
    head->next=NULL;
    n--;
    struct node * ptr=head;
    for(int i=1 ;i<=n;i++){
        printf("enter data: ");
        scanf("%d", &d);
        ptr=push(ptr,d);
    }
        return head;
    }
    else return NULL;
}

struct node * delete(struct node * head,int pos)
{   struct node * temp=head;
    if(pos==1){
        temp=head;
        head=head->next;
        free(temp);
    }
    else{
        pos--;
        for(int i=1;i<pos;i++){
            temp=temp->next;
        }
        struct node * temp2=temp->next;
        temp->next=temp2->next;
        free(temp2);
    }
        return head;
}

void printlist(struct node * head){
    if(head==NULL){
        printf("List empty\n");
    }
    else{
        while(head!=NULL){
            printf("%d -> ",head->data);
            head=head->next;
        }
        printf("\n");
    }
}

void search(struct node * head,int data){

    if(head==NULL){
        printf("Not found");
        return;
    }
    if(head->data==data){
        printf("Found ");
        return;
    }
    search(head->next,data);
}