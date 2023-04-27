#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * l,*r;
}node;

node * createtree(int d){
    node * root=malloc(sizeof(node));
    root->data=d;
    root->l=NULL;
    root->r=NULL;
    return root;
}
node * createnode(int data){
    node * new=malloc(sizeof(node));
    new->data=data;
    new->l=NULL;
    new->r=NULL;
    return new;
}
node * bst_insert(node * root,int data)
{   
    if(root==NULL){
        return createnode(data);
    }
    if(data>root->data) {
        root->r=bst_insert(root->r,data);
    }
    else{
        root->l=bst_insert(root->l,data);
    }

    return root;
}

node * inorder_precede(node * root){
    root=root->l;
    while(root->r!=NULL){
        root=root->r;
    }
    return root;
}
node * bst_delete(node * root, int data){
    node * ipre;
    if(root==NULL) return NULL;
    if(root->l==NULL&&root->r==NULL){
        free(root);
        return NULL;
    }
    if(data>root->data){
        root->r=bst_delete(root->r,data);
    }
    if(data<root->data){
        root->l=bst_delete(root->l,data);
    }
    if(root->data==data){
        ipre=inorder_precede(root);
        root->data=ipre->data;
        root->l=bst_delete(root->l,ipre->data);
    }

    return root;
}
void preorder(node * root){
    if(root==NULL) return;

    printf("%d ",root->data);
    preorder(root->l);
    preorder(root->r);
}
void inorder(node * root){
    if(root==NULL) return;

    inorder(root->l);
    printf("%d ",root->data);
    inorder(root->r);
}
int height(node * root){
    if(root==NULL) return 0;
    int hr=0,hl=0;
    if(root->r!=NULL)
    hr=height(root->r)+1;
    if(root->l!=NULL)
    hl=height(root->l)+1;

    return ( (hr>hl) ? hr : hl );
}
int bal_fac(node * root){
    int bal=height(root->l) - height(root->r);

    return bal;
}
int LeftNode(node * root)
{
    if(root==NULL) 
        return 0;

    if(root->l!=NULL && root->r==NULL)
        return (1+LeftNode(root->l));

    return (LeftNode (root->l) + LeftNode (root->r));
}
int main(){
    node* root=createtree(8);
    bst_insert(root,5);
    bst_insert(root,4);
    bst_insert(root,19);
    bst_insert(root,10);
    bst_insert(root,1);
    bst_insert(root,13);
    bst_insert(root,3);
    inorder(root);
    printf("\nheight= %d",height(root));
    printf("\nbal= %d",bal_fac(root));
    printf("\ncount= %d",LeftNode(root));
    return 0;

}