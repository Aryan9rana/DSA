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
node * rotateright(node * root){
    node * temp=root->l;
    root->l=temp->r;
    temp->r=root;

    return temp;
}
node * rotateleft(node * root){
    node * temp=root->r;
    root->r=temp->l;
    temp->l=root;

    return temp;
}
int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        
        int leftHeight = height(node->l);
        int rightHeight = height(node->r);
 
        
        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}
int bal_fac(node * root){
    int bal=height(root->l) - height(root->r);

    return bal;
}
node * avl_insert(node * root,int data)
{
    if(root==NULL){
        return createnode(data);
    }
    if(data>root->data)
    root->r=avl_insert(root->r,data);

    else if(data<root->data){
        root->l=avl_insert(root->l,data);
    }
    int bf=bal_fac(root);

    if(bf>1 && data<root->l->data){
        return rotateright(root);
    }
    if(bf> 1 && data>root->l->data){
        root->l=rotateleft(root->l);
        return rotateright(root);
    }
    if(bf< -1 && data>root->r->data){
        return rotateleft(root);
    }
    if(bf< -1 && data<root->r->data){
        root->r=rotateright(root->r);
        return rotateleft(root);
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
int main(){
    node* root=malloc(sizeof(node));
    root->data=8;
    avl_insert(root,5);
    avl_insert(root,4);
    avl_insert(root,3);
    avl_insert(root,19);
    preorder(root);
    printf("\n");
    inorder(root);
    return 0;

}