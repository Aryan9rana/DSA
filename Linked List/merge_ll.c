#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * next;
}node;

node * push(node*head,int data);
void add_beg(node ** head,int data);
void printlist(node* head);
// node* mid_node( node * head);
// node * merge(node * a, node* b);
// node * mergesort(node* head);

node * bubblesort(node * head);
int main(){
    node* head=malloc(sizeof(node));
    head->data=4;
    head->next=NULL;
    node * ptr= head;
    ptr= push(ptr,2);
    ptr= push(ptr,8);
    ptr= push(ptr,6);
    ptr= push(ptr,4);
    add_beg(&head, 0);
    printlist(head);
   head= bubblesort(head);
    printlist(head);
    return 0;
}

// node * mergesort(node* head){
//     if(head==NULL||head->next==NULL){
//         return head;
//       }
//     node *mid= mid_node(head);
//       node * first;
//       node * second;
//     first = head;
//     second=mid->next;
//     mid->next=NULL;
//     first=mergesort(first);
//     second= mergesort(second);
//     head= merge(first , second);
//     return head;
// } 

node * push(node*head,int data){
    node * temp=malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;
    head->next=temp;

    return temp;
}
void add_beg(node ** head,int data){
    node * new=malloc(sizeof(node));
    new->data=data;
    new->next=(*head);
    (*head)=new;
}
void printlist(node* head){
    node * temp=head;
    while(temp){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}
// node* mid_node( node * head){
//     node * slow= head;
//     node * fast= head->next;
//     while(fast!=NULL){
//         fast=fast->next;
//         if(fast!=NULL){
//         slow = slow->next;
//         fast=fast->next;
//         }
//     }
//     return slow;
// }

// node * merge(node * a, node* b){
//    node * result=NULL;
//    if(a==NULL){
//        return (b);
//    }
//    if(b==NULL){
//        return (a);
//    }
//    if(a->data<b->data){
//        result=a;
//        result->next= merge(a->next,b);
//    }
//    else{
//        result=b;
//        result->next=merge(a,b->next);
//    }
//    return result;
//  } 

 node * bubblesort(node * head){
     node * temp=NULL;
     node * temp2=NULL;
    int swap;
        do{
            swap=0;
            temp=head;
            while(temp->next!=temp2){
                if(temp->data>temp->next->data){
                    int t=temp->data;
                    temp->data= temp->next->data;
                    temp->next->data=t;
                    swap=1;
                }
                    temp=temp->next;
            }
            temp2=temp;
        }while(swap==1);
    return head;
 }