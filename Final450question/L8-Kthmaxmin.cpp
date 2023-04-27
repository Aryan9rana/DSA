#include <iostream>
using namespace std;
void print(int *arr,int size){
    for (int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int * arr,int lb,int ub){
    // int pivot = arr[lb];
    // int start = lb; 
    // int end=ub;
    // while(start<end){
    //     while(arr[start]<=pivot) start++;
    //     while(arr[end]>pivot) end--;
    //     if(start<end) {
    //         swap(&arr[start],&arr[end]);
    //     }
    // }
    //         swap(&arr[lb],&arr[end]);

    // return end;
    int pivot= arr[lb];
    int count=0;
    for (int i=lb+1;i<=ub;i++){
        if(arr[i]<=pivot) count++;
    }
    int pIndex=lb+count;
    swap(&arr[pIndex],&arr[lb]);
    int i=lb,j=ub;
    while(i<pIndex && j>pIndex){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot) {j--;}
        if(i<pIndex&& j>pIndex){
            swap(&arr[i++],&arr[j--]);
        }

    }
return pIndex;
}
void quicksort(int *arr, int lb, int ub){
    if(lb>ub) return;
    
        int p=partition(arr,lb,ub);
        quicksort(arr,lb,p-1);
        quicksort(arr,p+1,ub);
    
}
int main(){
    int n=8;
    int *arr= (int*)malloc(sizeof(int)*n);
    int d;
    for(int i=0;i<n;i++){
        cout<<"enter data:";
        cin>>d; 
        arr[i]=d;   
    }
    print(arr,8);
    quicksort(arr,0,7);
    print(arr,8);
    return 0;
}