#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};

int main(){
    struct node *head=NULL;
    head=(struct node *) malloc(sizeof(struct node));
    head->data=40;
    head->link=NULL;
    printf("%d, %d", head->data, head);
    return 0;
}