
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};
void inorder_traversal(struct node *root);
struct node *create(int data);
struct node *insert(struct node *root, int data);

void main()
{
   int choice=0;

    int data;
    int cont = 3;  struct node *root = (struct node *)malloc(sizeof(struct node));
            root = NULL;
    printf("enter the root data\n");
    scanf("%d",&data);
    root=insert(root,data);
    
    do {
        printf("enter the data to be inserted\n");
        scanf("%d",&data);
        insert(root,data);
        printf("enter 0 to continue inserting\n");
        scanf("%d",&choice);
    }while(choice==0);
    /* struct node *root;
        root = insert(root,20);
        insert(root,5);
        insert(root,1);
        insert(root,15);
        insert(root,9);
        insert(root,7);
        insert(root,12);
        insert(root,30);
        insert(root,25);
        insert(root,40);
        insert(root, 45);
        insert(root, 42);*/
        printf("inorder traversal is\n");

    inorder_traversal(root);
    
   
}
struct node *create(int data)
{

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("memory not allocated\n");
        return 0;
    }
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

 struct node* insert(struct node *root, int x)
    {
        //searching for the place to insert
        if(root==NULL)
            return create(x);
        else if(x>root->data) // x is greater. Should be inserted to the right
            root->right = insert(root->right, x);
        else // x is smaller and should be inserted to left
            root->left = insert(root->left,x);
        return root;
}

void inorder_traversal(struct node *root)
{
    if (root->left == NULL && root->right==NULL) return;
    
    inorder_traversal(root->left);
    printf("%d\t", root->data);
    inorder_traversal(root->right);
}
