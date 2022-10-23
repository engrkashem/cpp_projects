#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>PAIR;

int main(){
    vector<int> v(3,-1);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl<<endl;

    v.push_back(4);

    vector<int>::iterator it;

    for(it=v.begin(); it!=v.end(); it++){
        cout<<*it<<" ";
    }
     cout<<endl<<endl;

    // 'auto' register
    for(auto element:v){
        cout<<element<<" ";
    }
    cout<<endl<<endl;

    for(auto it1=v.begin(); it1!=v.end(); it1++){
        cout<<*it1<<" ";
    }
    cout<<endl<<endl;

    //priority_queue<int, vector<int>>pq;
    // to make min priority queue.
    priority_queue<PAIR, vector<PAIR>, greater<PAIR>>pq;
    pq.push(make_pair(1,9));
    pq.push(make_pair(6,4));
    pq.push(make_pair(4,1));

    while(!pq.empty()){
        cout<<pq.top().first<<" | "<<pq.top().second<<endl;
        pq.pop();
    }
    cout<<endl<<endl;

return 0;
}
