#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * l,*r;
};

void inorder (struct node * root);
void postorder( struct node * root);
struct node * delete_post(struct node * root, int data);
struct node * inordersuccessor(struct node * root);



int main(){
    struct node * root= malloc(sizeof(struct node));
    root->data=6;
    struct node * n1= malloc(sizeof(struct node));
    n1->data=4;
    struct node * n2= malloc(sizeof(struct node));
    n2->data=8;
    struct node * n3= malloc(sizeof(struct node));
    n3->data=2;
    struct node * n4= malloc(sizeof(struct node));
    n4->data=5;
    root->l=n1;
    root->r=n2;
    n1->l=n3;
    n1->r=n4;

    inorder(root);
    printf("\n");
    delete_post(root, 6);
      inorder(root);
    return 0;
}


void inorder (struct node * root){
    if(root==NULL) return;

    inorder(root->l);
    printf("%d ",root->data);
    inorder(root->r);
}

void postorder( struct node * root){
    if(root==NULL)return;

    postorder(root->r);
    printf("%d ",root->data);
    postorder(root->l);
}

struct node * delete_post(struct node * root, int data){
    struct node * ipost;
    if(root==NULL)return NULL;
    if(root->l==NULL && root->r==NULL)//leaf node
    {
        free(root);
        return NULL;
    }
    if(data<root->data){
        root->l= delete_post(root->l, data);
    }
    else if( data> root->data){
        root->r = delete_post(root->r , data);
    }
    else{
        ipost=inordersuccessor(root);
        root->data=ipost->data;
        root->r= delete_post(root->r, ipost->data);
    }
    return root;
}

struct node * inordersuccessor(struct node * root){
    root= root->r;

    while(root->l!=NULL){
        root=root->l;
    }
    return root;
}