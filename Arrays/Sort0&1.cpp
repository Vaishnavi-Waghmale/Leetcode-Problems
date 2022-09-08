#include <iostream>
using namespace std;
void printArray(int a[], int n){
  for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
  cout<<endl;
}

void sortOne(int a[], int n){
  int i =0;
  int j = n-1;
  while(i<j){
    while(a[i]==0){
      i++;
    }
    while(a[j]==1){
      j--;
    }
    if(a[i]==1 && a[j]==0){
    swap(a[i],a[j]);
    i++;
    j--;
    }
  }
}
int main() {
    int s;
    cin>>s;
    int a[s];
    for(int i=0; i<s; i++){
        cin>>a[i];
    }
    
  sortOne(a, s);
  printArray(a, s);
    

    return 0;
}
