#include <iostream>
using namespace std;
void print(int *arr){
    for (int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int max(int *arr)
{   int max=0;
    for(int i=1;i<5;i++){
        if(arr[i]>arr[max]){
            max=i;
        }
    }
    return max;
} 
int min(int *arr)
{   int min=0;
    for(int i=1;i<5;i++){
        if(arr[i]<arr[min]){
            min=i;
        }
    }
    return min;
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
    int m= max(arr);
    cout<<"max= "<<arr[m]<<endl;
    m= min(arr);
    cout<<"min= "<<arr[m]<<endl;

    return 0;
}