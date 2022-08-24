#include<bits/stdc++.h>
#include"MYSTACK.h"
#include"MYQUEUE.h"

using namespace std;


int main(){
    Stack<int> st;
    Queue<int> que;

    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int temp=i;
        while(temp!=0){
            st.push(temp%2);
            temp=temp/2;
        }
        while(!st.empty()){
            que.push(st.pop());
        }
        while(!que.empty())cout<<que.pop();
        cout<<" ";

        i++;
    }
    cout<<endl;
    //while(!que.empty())cout<<que.pop()<<endl;

return 0;
}
