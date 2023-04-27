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
    else if(q->r==-1&&q->f==-1){
        q->f=0;
        q->r=0;
        q->arr[q->r]=data;
    }
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
    else{
        q->f++;
        val = q->arr[q->f];
    }
    return val;
}
int main(){
    queue q;
    q.size=100;
    q.f= q.r=0;
    q.arr=(int *)malloc(q.size*sizeof(int));


    int i=0;
    int visited[7]={0,0,0,0,0,0,0};
    int a[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };
    printf("%d ",i);
    visited[i]=1;
    enqueue(&q,i);
    // printf("%d ",dequeue(&q));
    while(!isEmpty(&q)){
        int node= dequeue(&q);
        for(int j=0;j<7;j++){
            if(a[node][j]==1 && visited[j]==0){
                printf("%d ",j);
                visited[j]=1;
                enqueue(&q,j);
            }
        }
    }
    return 0;
}