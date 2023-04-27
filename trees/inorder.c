#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node * left;
    struct node *right;
}node;
node * create(int data){
    node *newnode= malloc(sizeof(node));
    newnode->data= data;
    newnode->right= NULL;
    newnode->left= NULL;
    return newnode;
}
node * insert(node * root, int data){
    if(root==NULL) return create(data);
    else if(data<root->data){
        root->left=insert(root->left,data);
    }
    else root->right= insert (root->right,data);
    return root; 
}
node * search ( node * root, int data){
    if(root==NULL){
        return NULL;
    }
    if( root->data== data){
        return root;
    }
    else if(data<root->data){
        return search(root->left,data);
    }
    else return search(root->right, data);
}
void inorder ( node *root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
 }
void inorder_successor(node * temp){

}
int main(){
    node * root= malloc(sizeof(node));
    int data=0;
    printf("Enter root data: ");
    scanf("%d", &data);
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    int choice=0 ;
    while(choice==0){
        printf("Enter data: ");
        scanf("%d", &data);
        root=insert(root,data);
        printf("do you wish to continue (press 0): ");
        scanf("%d", &choice);
    }
    inorder(root);
    return 0;
}