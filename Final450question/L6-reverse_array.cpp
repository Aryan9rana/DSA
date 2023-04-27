#include <iostream>
using namespace std;
void print(int *arr){
    for (int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void reveresearray(int *arr, int start, int end)
{
    while(start<end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
} 
void rev(int * arr){
    int *temp= (int*)malloc(sizeof(int)*5);
    int j=5-1;
    for ( int i=0;i<5;i++){
            temp[i]=arr[j--];
    }
    for ( int i=0;i<5;i++){
            arr[i]=temp[i];
    }
}
int main(){
    int *arr= (int*)malloc(sizeof(int)*5);
    int data;
    for ( int i=0;i<5;i++){
        cout<<"enter data:";
        cin>>data;
        arr[i]=data;
    }
    print(arr);
    reveresearray(arr,0,4);
    print(arr);

    return 0;
}