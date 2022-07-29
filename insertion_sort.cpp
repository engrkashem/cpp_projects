#include<bits/stdc++.h>

using namespace std;

void print_array(int *a, int size){
    for(int i=0; i<size; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int size;
    cin>>size;
    int a[size];
    for(int i=0; i<size; i++){
        cin>>a[i];
    }
    cout<<"Before Sort: ";
    print_array(a,size);

    //insertion sort
    for(int i=1; i<size; i++)    {
        int temp=a[i];
        int j=i-1;
        while(a[j]>temp && j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }

    cout<<"after sort: ";
    print_array(a,size);

return 0;
}
