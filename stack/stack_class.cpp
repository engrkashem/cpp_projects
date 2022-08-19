#include<bits/stdc++.h>
#include"MYSTACK.h"
using namespace std;

int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(6);
    while(!st.empty()){
        cout<<st.pop()<<endl;
    }
    cout<<st.size()<<endl;
    if(st.Top()!=-1) cout<<st.Top()<<endl;

return 0;
}
