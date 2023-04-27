#include <stdio.h>
#include <stdlib.h>

typedef struct treenode{
    int data;
    struct treenode* left;
    struct treenode* right;
}treenode;
treenode * createnode(int data){
    treenode* result= malloc(sizeof(treenode));
    if (result !=NULL){
        result->data=data;
        result->left=NULL;
        result->right=NULL;
    }
    return result;
}
void tabs(int num){
    for(int i=0;i<num;i++){
        printf("\t");
    }
}

void inorder (treenode* root){
    if(root==NULL) return;

    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main(){
    treenode * n1= createnode(1);    
    treenode * n2= createnode(2);    
    treenode * n3= createnode(3);    
    treenode * n4= createnode(4);    
    treenode * n5= createnode(5);     

    n1->left= n2;
    n1->right = n3;
    n3->left=n4;
    n3->right =n5;

inorder(n1);
    free(n1);  
    free(n2);  
    free(n3);  
    free(n4);  
    free(n5);  
    return 0;
}