#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * l,*r;
};
struct node * create(int d){
    struct node * new= (struct node *)malloc(sizeof(struct node));
    new->data=d;
    new->l=NULL;
    new->r=NULL;

    return new;
}
void insert(struct node ** root,struct node * temp){
    if(*root==NULL){
        (*root)=temp;
    }
    else if((*root)->data<temp->data){
        insert(&((*root)->r),temp);
    }
    else{
        insert(&((*root)->l),temp);
    }
}

void inorder(struct node * root){
    if(root==NULL) return;

    inorder(root->l);
    printf("%d ",root->data);
    inorder(root->r);
}
int inorder_pre(struct node * root){
    root=root->l;
    while(root->r!=NULL){
        root=root->r;
    }

    return root->data;
}

int is_bst(struct node * root){
    static struct node * prev=NULL;
    if(root!=NULL){
    
    if(!is_bst(root->l))return 0;
    if(prev!=NULL&&root->data<prev->data) return 1;
    prev=root;
    if(!is_bst(root->r)) return 0;
    }

    return 1;
    
}

int main(){
    struct node * root=(struct node *)malloc(sizeof(struct node));
    root->data=5;
    root->l=NULL;root->r=NULL;
    struct node * temp;
    temp=create(8);
    insert(&root,temp);
    temp=create(7);
    insert(&root,temp);
    temp=create(2);
    insert(&root,temp);
    temp=create(3);
    insert(&root,temp);
    temp=create(1);
    insert(&root,temp);
    temp=create(55);
    insert(&root,temp);
    temp=create(23);
    insert(&root,temp);
    inorder(root);
    printf("\n");
    if(is_bst(root)){
        printf("bst");
    }
    else printf("not bst");
    return 0;
}