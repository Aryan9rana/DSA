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

 int isbst(node * root){
    static node * prev= NULL;
    if(root!=NULL){
        if(!isbst(root->left)) return 0;
        else if(prev!=NULL && prev->data >= root->data){return 1;}
        prev= root;
        return isbst(root->right);
    }
    else return 1;
 }


    node * inOrderPre(node * root){
        root=root->left;
        while(root->right!=NULL){
            root=root->right;
        }
        return root;
    }
node * delete(node * root, int data){
        node * ipre;
        if(root==NULL)return NULL;
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }

        if(data<root->data){
            root->left=delete(root->left, data);
        }
        else if(data>root->data){
            root->right=delete(root->right, data);
        }
        else{
            ipre=inOrderPre(root);
            root->data=ipre->data;
           root->left= delete(root->left,ipre->data);
        }

        return root;
    }

node * iterative_search ( node * root, int data){
    while(root!=NULL){
    if(data==root->data){
        return root;
    }
    else if( data<root->data){
        root=root->left;
    }
    else{
        root= root->right;
    }
    }
    return NULL;
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
        printf("do you wish to continue (press y): ");
        scanf("%d", &choice);
    }
    
    inorder(root);
    printf("\nisbst= %d\n",isbst(root));
    // printf("\nEnter element to search: ");
    // int d;
    // scanf("%d", &d);
    // node * s= search(root, d);
    // if(s!=NULL){
    // printf("found %d\n", s->data);
    // }
    // else printf("not found\n");

    printf("\nEnter element to delete: ");
    int d;
    scanf("%d", &d);
    root= delete(root,d );
    inorder(root);
    return 0;
}
