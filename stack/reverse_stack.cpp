#include<bits/stdc++.h>
#include"MYSTACK.h"

using namespace std;

void insertAtBottom(Stack<int>&st, int chkEl){
    if(st.empty()){
        st.push(chkEl);
        return;
    }

    int topEl=st.Top();
    st.pop();
    insertAtBottom(st,chkEl);
    st.push(topEl);
}

void reverseStack(Stack <int> &st){
    if(st.empty())return;

    int topEl=st.Top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, topEl);
}

int main(){
    Stack<int> st;
    int n;
    cin>>n;
   for(int i=1; i<=n; i++){
        st.push(i);
    }
    reverseStack(st);
    while(!st.empty()){
        cout<<st.pop()<<" ";
    }
    cout<<endl;

return 0;
}
