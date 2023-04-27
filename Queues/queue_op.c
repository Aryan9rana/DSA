#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int size;
    int f,r;
    int * arr;
}queue;
int isEmpty (queue * q){
    if(q->f==q->r){
        return 1;
    }
    else return 0;
}

int isFull( queue * q){
    if(q->r==q->size-1){
        return 1;
    }
    else return 0;
}

void enqueue( queue * q,int data){
    if(isFull(q)){
        printf("Queue is Full\n");
    }
    // else if(q->f==-1&&q->r==-1){
    //     q->f=0;
    //     q->r=0;
    //     q->arr[q->r]=data;
    // }
    else {
        q->r=q->r+1;
        q->arr[q->r]=data;
    }
}
int dequeue ( queue * q){
    int val=-1;
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    // else if(q->f==q->r){
    //     val=q->arr[q->f];
    //     q->f=-1;
    //     q->r=-1;
    // }
    else{
        q->f++;
        val = q->arr[q->f];
    }
    return val;
}
int main(){
    queue *q=(queue*)malloc(sizeof(queue));
    q->size=10;
    q->f= q->r=-1;
    q->arr=(int *)malloc((q->size)*sizeof(int));
// enqueue(&q, 1);
enqueue(q, 3);

enqueue(q, 2);
enqueue(q, 4);
enqueue(q, 4);
enqueue(q, 4);
printf("%d \n",dequeue(q));
printf("%d \n",dequeue(q));
printf("%d \n",dequeue(q));
printf("%d \n",dequeue(q));
printf("%d \n",dequeue(q));

    return 0;
}