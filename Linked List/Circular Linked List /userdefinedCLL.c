#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

void printlist(node *tail)
{
    if (tail == NULL)
    {
        printf("list empty");
    }
    else
    {

        node *ptr = tail->next;
        do
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } while (ptr != tail->next);
    }
    printf("\n");
}
int countnode(node * tail);
int search(node*tail, int element);
node *createlist(node *tail);
node *del_beg(node *tail);
node *del_end(node *tail);
node *del_pos(node *tail, int pos);

int main()
{
    node *tail = NULL;int p;
    tail = createlist(tail);
    printf("Data in the list:\n");
    printlist(tail);
/*     printf("Node deleted from beginning\n");
    tail = del_beg(tail);
    printlist(tail);
    printf("last node deleted: \n");
    tail = del_end(tail);
    printf("Enter pos: ");
    scanf("%d", &p);
    tail=del_pos(tail,p);*/
    int count=countnode(tail);
    printf("Number of nodes= %d\n",count);
    int el;
    printf("Enter a number: ");
    scanf("%d", &el);
    int index=search(tail,el);
    printlist(tail); 
    printf("index= %d\n",index);
    return 0;
}

node *createlist(node *tail)
{
    int data, n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n == 0)
    {
        return tail;
    }
    printf("Enter the data for node 1: ");
    scanf("%d", &data);
    tail = malloc(sizeof(node));
    tail->data = data;
    tail->next = tail;

    for (int i = 2; i <= n; i++)
    {
        printf("Enter the data for node %d: ", i);
        scanf("%d", &data);
        node *temp = malloc(sizeof(node));
        temp->data = data;
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
    }
    return tail;
}

node *del_beg(node *tail)
{
    if (tail == NULL)
    {
        return tail;
    }
    else if (tail->next == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    else
    {
        node *temp = tail->next;
        tail->next = temp->next;
        free(temp);
        temp = NULL;
        return tail;
    }
}

node *del_end(node *tail)
{
    if (tail == NULL)
    {
        return tail;
    }
    else if (tail == tail->next)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    else
    {
        node *temp = NULL;
        temp = tail->next;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = tail->next;
        free(tail);
        tail = temp;
        return tail;
    }
}

node *del_pos(node *tail, int pos)
{
    if(pos==1)
    {
        tail=del_beg(tail);
    }
    else if(tail->next==tail){
        free(tail);
        tail=NULL;
        
    }
    else
    {
        node *temp=tail->next;
        node *temp2;
        pos--;
        while(pos>1){
            temp=temp->next;
            pos--;
        }
        temp2=temp->next;
        if(temp2==tail){
            tail=temp;
        }
        temp->next=temp2->next;
        free(temp2);
        temp2=NULL;
    }
    return tail;
}

int countnode(node * tail){
    if(tail==NULL){
        return -1;
    }
    else{
    int count=0;
    node* temp=tail->next;
    while(temp!=tail){
        count++;
        temp=temp->next;
    }count++;
    return count;
    }
}

int search(node*tail, int element){
    if (tail==NULL){
        return -2;
    }
    else{
    node * temp=tail->next;
    int index=1;
    do{
        if(temp->data==element){
            return index;
        }
        temp=temp->next;
        index++;
    }while(temp!=tail->next);
    return -1;
    }
}