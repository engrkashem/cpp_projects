#include<bits/stdc++.h>
#include"MYSTACK.h"

using namespace std;

void sortStack(Stack<int>&sorted, int chkEl){
    if(sorted.empty()){
        sorted.push(chkEl);
        return;
    }

    if(sorted.Top()<=chkEl){
        sorted.push(chkEl);
        return;
    }

    int topEl=sorted.Top();
    sorted.pop();
    sortStack(sorted,chkEl);
    sorted.push(topEl);
}

int main(){
    Stack<int> st;
    Stack<int> sorted;
    int n, temp;
    cin>>n;
    while(n!=0){
        temp;
        cin>>temp;
        st.push(temp);
        n--;
    }

    while(!st.empty()){
        temp=st.Top();
        sortStack(sorted, temp);
        st.pop();
    }
    cout<<endl;
    while(!sorted.empty()){
        cout<<sorted.pop()<<" ";
    }
    cout<<endl;

return 0;
}
