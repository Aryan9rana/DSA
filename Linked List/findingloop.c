/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node *
add_el (struct node *head, int data)
{
  struct node *ptr = malloc (sizeof (struct node));
  ptr->data = data;
  ptr->next = NULL;
  head->next = ptr;
  return ptr;
}

struct node *
makehead (int data)
{
  struct node *head = malloc (sizeof (struct node));
  head->data = data;
  head->next = NULL;
  return head;
}

struct node *
createlist ()
{
  printf ("enter number of elements: ");
  int n;
  scanf ("%d", &n);
  printf ("Enter the first element linked list: ");
  int data;
  scanf ("%d", &data);
  struct node *head = makehead (data);
  struct node *ptr = head;
  for (int i = 1; i < n; i++)
    {
      printf ("enter element: ");
      int d;
      scanf ("%d", &d);
      ptr = add_el (ptr, d);
    }
  return head;
}

void
printlist (struct node *head)
{
  if (head == NULL)
    {
      printf ("list is empty\n");
    }
  else
    {
      struct node *temp = head;
      printf ("list is:\n");
      do
	    {
	        printf ("%d ", temp->data);
	        temp = temp->next;
	    }while (temp != NULL);
      printf ("\n");
    }
}
 void looplist(struct node* head){
    struct node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    printf("do you want to make a loop?(yes=1/no=0)\n");
    int l;
    scanf("%d",&l);
    if(l==1){
        printf("which element should last node point to: ");
        int nl;
        scanf("%d",&nl);
        //nl--;
        struct node *temp2=head;
        for(int i=1;i<nl;i++){
            temp2=temp2->next;
        }
        temp->next=temp2;
    }
    else if(l==0){
        printf("no loop created\n");
    }
    else{
        printf("wrong input\n");
    }
 }
int main ()
{
  struct node *head = createlist ();
  printlist (head);
  looplist(head);
  return 0;
}
