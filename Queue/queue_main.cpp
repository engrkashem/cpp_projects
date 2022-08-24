#include<bits/stdc++.h>
#include"MYQUEUE.h"

using namespace std;
typedef pair<char, int> myType;

int main(){
    Queue<myType> que;
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        char temp1;
        int temp2;
        cin>>temp1>>temp2;
        que.push(make_pair(temp1, temp2));
    }

//    while(!que.empty()){
//        myType res;
//        res=que.pop();
//        cout<<res.first<<" | "<<res.second<<endl;
//    }

    if(!que.empty()){
        myType res;
        res=que.front();
        cout<<"Front Value: "<<res.first<<" | "<<res.second<<endl;

        res=que.back();
        cout<<"Rear Value: "<<res.first<<" | "<<res.second<<endl;
    }

return 0;
}
