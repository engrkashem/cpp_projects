#include<bits/stdc++.h>

using namespace std;


int bi_search(int *a, int x, int lb, int ub){
    if(lb<=ub){
        int mid=(lb+ub)/2;
        if(x==a[mid])return mid;
        else if(x<a[mid]) bi_search(a,x,lb,mid-1);
        else bi_search(a,x,mid+1,ub);
    }
    else return -1;
}

int main(){
    int size;
    cin>>size;
    int a[size];
    for(int i=0; i<size; i++){
        cin>>a[i];
    }
    //sort(a,a+n);
    int check_value;
    cout<<"Enter your desired search: ";
    cin>>check_value;
    int resultant_index=bi_search(a,check_value,0,size-1);
    if(resultant_index==-1) cout<<"Not Found"<<endl;
    else cout<<a[resultant_index]<<" is found in the "<<resultant_index<<" index"<<endl;
return 0;
}
