#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;
node* circular_ll(data){
    node*temp=malloc(sizeof(node));
    temp->data=data;
    temp->next=temp;
return temp;
}
void printdata(node * tail){
    node * ptr=tail->next;
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=tail->next);
    printf("\n");
}
node* add_beg(node * tail,int data){
    node * temp=malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;
    
    temp->next=tail->next;
    tail->next=temp;
    printf("Added at beginning\n");
return tail;
}
node* add_end(node * tail,int data){
    node * temp=malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;

    temp->next=tail->next;
    tail->next=temp;
    tail=temp;
//printf("Node added at the end\n");
return temp;
}

node* add_pos(node * tail, int pos,int data){
    if(pos==1){
        add_beg(tail,data);
    }
    else{
    node* temp=malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;
    node*ptr=tail->next;
    pos--;
    while(pos>1){
        ptr=ptr->next;
        pos--;
    }
        temp->next=ptr->next;
        ptr->next=temp;
        if(ptr==tail){
            tail=tail->next;
        }

    }
    printf("Node added at pos\n");
    return tail;
}
int main(){
    node* tail=NULL;
    tail=circular_ll(1);
    tail=add_end(tail,2);
    tail=add_end(tail,3);
    tail=add_end(tail,4); 
    printdata(tail);
    tail=add_pos(tail,3,10);
    printdata(tail);
    return 0;
}