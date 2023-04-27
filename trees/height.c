#include <stdio.h>  
#include <stdlib.h>  
   
typedef struct node{  
    int data;  
    struct node *left;  
    struct node *right;  
}node ;  

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

// int height(struct node *root){  
//     if(root==NULL){
//         printf("list is empty");
//         return 0;
//     }  
//     else {
//         int hl = , hr = 0;  
//         if(root->left != NULL)  
//             hl = height(root->left)+1;  
          
//         if(root->right != NULL)  
//             hr = height(root->right)+1;  
          
//         return ((hl > hr) ? hl : hr); 
//     }
// }  
int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
 
        
        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}

   void inorder ( struct node *root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
 }
   void preorder ( struct node *root){
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
 }
int main()  
{   
    node * root= malloc(sizeof(node));
    root->data=6;
    root->left=NULL;
    root->right=NULL;
    root=insert(root,8);
    root=insert(root,78);
    root=insert(root,3);
    root=insert(root,5);
    root=insert(root,2);
    printf("Maximum height of given binary tree: %d\n", height(root));  

preorder(root);
    return 0;  
}  