#include<bits/stdc++.h>
#include"MYSTACK.h"
#include"MYQUEUE.h"

using namespace std;

int main(){
    Stack<int> st;
    Queue<int> que;

    int n, temp;
    cin>>n;
    while(n!=0){
        cin>>temp;
        que.push(temp);
        n--;
    }
//    cout<<"Before Reversing: "<<endl;
//    while(!que.empty()){
//        cout<<que.pop()<<" ";
//    }
//    cout<<endl;
    while(!que.empty()){
        st.push(que.pop());
    }
    while(!st.empty()){
        que.push(st.pop());
    }
    cout<<"After Reversing: "<<endl;
    while(!que.empty()){
        cout<<que.pop()<<" ";
    }
    cout<<endl;

return 0;
}
