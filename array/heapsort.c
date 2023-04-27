#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void swap(int * a, int * b){
    int temp= *a;
    *a= *b;
    *b= temp;
}

void heapify(int a[],int i ,int size){
    int l=2*i+1;
    int r=2*i+2;
    int largest=i;
    if(l<=size&&a[l]>a[largest])
        largest=l;

    if(r<=size&& a[r]>a[largest]) 
        largest= r;
    
    if(largest!=i){
        swap(&a[i],&a[largest]);
        heapify(a,largest,size);
    }
    
}

void build_heap(int a[],int beg,int end){
    for(int i=(end/2);i>=beg;i--){
        heapify(a,i,end);
    }
}

void sort(int a[], int size){
    for (int i=size;i>=1;i--){
        swap(&a[0],&a[i]);
        heapify(a,0,(i-1));
    }
}

void print(int a[], int n){
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
printf("\n");
}


int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the data:\n");
    for (int i=0;i<n;i++){
        printf("element %d: ",i+1);
        scanf("%d", &a[i]);
    }
    print(a,n);
    build_heap(a,0,n-1);
    print(a,n);
    sort(a,n-1);
    print(a,n);
    return 0;

}