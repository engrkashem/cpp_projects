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

    //bubble sort
    for(int i=0; i<size-1; i++){//or i=1; i<size; i++
        bool isStop=false;
        for(int j=0; j<size-i-1; j++){// or j=0; j<size-i; j++
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                isStop=true;
            }
        }
        if(isStop==false)break;
    }

    cout<<"after sort: ";
    print_array(a,size);

return 0;
}
