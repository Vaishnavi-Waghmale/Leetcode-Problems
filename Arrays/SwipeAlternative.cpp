#include <iostream>
using namespace std;
void printArray(int arr[], int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
void swapAlternate(int arr[], int size){
    for(int i=0; i<size; i+=2){
        if(i+1<size){
            swap(arr[i], arr[i+1]);
        }
    }
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    swapAlternate(a, n);
    printArray(a,n);

    return 0;
}
