#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * left, *right;
    int height;
};

int max (int a , int b){
    if(a>b) return a;
    else return b;
}
struct node * createnode ( int data){
    struct node * n= (struct node *) malloc(sizeof(struct node));
    n->data= data;
    n->left=NULL;
    n->right= NULL;
    n->height= 1;

    return n;
}
int getheight( struct node * n){
    if(n==NULL) return 0;

    return n->height;
}
int getBalanceFactor(struct node * n){
    if(n==NULL) return 0;

    return getheight(n->left) - getheight(n->right);  
}

struct node * rightrotation( struct node * n){
    struct node * temp = n->left;
    struct node * temp2 = temp->right;
    temp->right = n;
    n->left= temp2;

    n->height= max(getheight(n->left), getheight(n->right))+1;
    temp->height= max(getheight(temp->left), getheight(temp->right))+1;

    return temp;
}
struct node * leftrotation( struct node * n){
    struct node * temp = n->right;
    struct node * temp2 = temp->left;
    temp->left = n;
    n->right= temp2;

    n->height= max(getheight(n->left), getheight(n->right))+1;
    temp->height= max(getheight(temp->left), getheight(temp->right))+1;

    return temp;
}

struct node * insert( struct node * root , int data){
    if(root==NULL) 
    return createnode(data);

    if( data< root->data){
        root->left= insert( root->left, data);
    }
    else if( data> root->data){
        root->right= insert ( root->right, data);
    }
    root->height= 1+ max(getheight(root->right),getheight(root->left));
    int bf= getBalanceFactor( root);
    //LL
    if(bf>1 && data<root->left->data){
     return rightrotation(root);
    }
    //RR
    if(bf< -1 && data>root->right->data){
     return leftrotation(root);
    }
    //LR
    if( bf>1 && data> root->left->data){
        root->left=leftrotation(root->left);
        return rightrotation(root);
    }
    //RL
    if(bf< -1 && data< root->right->data){
        root->right= rightrotation(root->right);
        return leftrotation(root);
    }

    return root;
}

void inorder( struct node * root){
    if(root==NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preOrder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
    struct node * root= NULL;
    root= insert(root, 45);
    root= insert(root, 2);
    root= insert(root, 4);
    root= insert(root, 6);
    root= insert(root, 65);
    root= insert(root, 80);
    root= insert(root, 7);
    preOrder(root);
    return 0;

}