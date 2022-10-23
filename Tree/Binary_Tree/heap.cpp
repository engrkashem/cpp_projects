#include<bits/stdc++.h>

using namespace std;

void heapify(int a[], int n, int currentIndex);
void printArray(int a[], int n);
void heapSort(int *a, int n);

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<"Before Heapify:";
    printArray(a,n);
    int nonLeafStatingIndex=n/2 - 1;

    for(int i=nonLeafStatingIndex; i>=0; i--){
        heapify(a,n,i);
    }
    cout<<"After heapify:";
    printArray(a,n);

    heapSort(a,n);
    cout<<"After Heap Sort:";
    printArray(a,n);

    // 2 10 1 5 4 8 3 8 7
return 0;
}

void heapSort(int *a, int n){
    for(int i=n-1; i>=0; i--){
        swap(a[0], a[i]);
        heapify(a,i,0);
    }
};

void printArray(int a[], int n){
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
};

void heapify(int a[], int n, int currentIndex){
    int largest= currentIndex;
    int leftChild=2*currentIndex+1;
    int rightChild=2*currentIndex+2;

    if(leftChild<n && a[leftChild]>a[largest]){
        largest=leftChild;
    }

    if(rightChild<n && a[rightChild]>a[largest]){
        largest=rightChild;
    }

    if(largest!=currentIndex){
        swap(a[currentIndex], a[largest]);
        heapify(a,n,largest);
    }
}
