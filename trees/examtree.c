#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node * l,*r;
}node;

node * create(int data){
    node * new=malloc(sizeof(node));
    new->data=data;
    new->l=NULL;
    new->r=NULL;

    return new;
}
node* insert(node *root, int x)
    {
        //searching for the place to insert
        if(root==NULL)
            return create(x);
        else if(x>root->data) // x is greater. Should be inserted to the r
            root->r = insert(root->r, x);
        else // x is smaller and should be inserted to l
            root->l = insert(root->l,x);
        return root;
}
node * create_bst(){
    int n,key;
    node * root=malloc(sizeof(node));
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    if(n!=0){
        printf("Enter root data: ");
        scanf("%d", &key);
        root->data=key;
        root->l=NULL;
        root->r=NULL;
        for(int i=1;i<n;i++){
            printf("Enter data: ");
            scanf("%d", &key);
            root=insert(root,key);
        }
    }
    return root;
}
int count_left(node * root){
    int count=0;
    if(root==NULL) return 0;
    if(root->l!=NULL && root->r==NULL){
        return 1;
    }
    return count+ count_left(root->l)+count_left(root->r);
}

int LeftNode(node * root)
{
    if(root==NULL) 
        return 0;

    if(root->l!=NULL && root->r==NULL)
        return (1+LeftNode(root->l));

    return (LeftNode (root->l) + LeftNode (root->r));
}
void inorder ( node *root){
    if(root==NULL) return;
    inorder(root->l);
    printf("%d ",root->data);
    inorder(root->r);
 }
void preorder ( node *root){
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->l);
    preorder(root->r);
 }

int main(){
    node * root;
    root=create_bst();
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\ncount = %d",count_left(root));
    return 0;
}