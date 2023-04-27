#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node * addnode(struct node * ptr, int d){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=d;
    temp->link=NULL;

    ptr->link=temp;
    return temp;
}
 printdata(struct node* head){
 void   struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr= ptr->link;
    }
}
struct node * delete_beg(struct node *head);
struct node * delete_last(struct node *head);
struct node * delete_pos(struct node * head, int pos);
int main(){
    struct node *head=NULL;
    struct node *ptr=NULL;
    head = malloc(sizeof(struct node));
    head->data=1;
    head->link=NULL;
    ptr=addnode(head,2);
    ptr=addnode(ptr,3);
    ptr=addnode(ptr,4);
    printdata(head);

/*     head=delete_beg(head);
    printdata(head);

    head=delete_last(head);
    printdata(head); */
    head= delete_pos(head,4);
    printdata(head);

    return 0;
}

struct node * delete_beg(struct node * head){
struct node * temp = head;
head = head->link;
free(temp);
temp=NULL;
printf("beginning Node deleted\n");
return head;
}

struct node * delete_last(struct node * head){
    if (head == NULL){
        printf("the list is empty\n");
    }
    else if(head->link==NULL)
    {
        free(head);
        head=NULL;
    }
/*     else{
        struct node * ptr1=head;
        struct node *ptr2=head;

        while (ptr1->link!=NULL){
            ptr2=ptr1;
            ptr1=ptr1->link;
        }
        ptr2->link=NULL;
        free(ptr1);
        ptr1=NULL;
    } */
    //using single pointer
    else
    {
        struct node* ptr=head;
        while (ptr->link->link!=NULL){
            ptr=ptr->link;
        }
        free(ptr->link);
        ptr->link=NULL;
    }
    
    printf("Last Node deleted\n");
    return head;
}
struct node * delete_pos(struct node * head, int pos){
      struct node * temp=head;
      struct node * holder;
      if(pos==1){
         head=temp->link;
         free(temp);
         temp=NULL;
     }
     else { 
     
      pos--;
      while(pos!=1){
          temp=temp->link;
          pos--;
      }
      holder=temp->link->link;
      free(temp->link);
      temp->link=holder;
      }
      printf("Node deleted\n");
      return head;
}