#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>PAIR;

int main(){
    int k;
    cin>>k;
    vector<vector<int>> allArrays(k);
    //input
    for(int i=0; i<k; i++){
        int size;
        cin>>size;
        allArrays[i]=vector<int>(size);
        for(int j=0; j<size; j++){
            cin>>allArrays[i][j];
        }
    }

    vector<int>indexTracker(3,0);

    priority_queue<PAIR, vector<PAIR>, greater<PAIR>>pq;

    //initialization of pq.
    for(int i=0; i<k; i++){
        pq.push(make_pair(allArrays[i][0],i));
    }


    vector<int>ans;
    //.main logic of heap
    while(!pq.empty()){
        PAIR x=pq.top();
        pq.pop();

        ans.push_back(x.first);

        if(indexTracker[x.second]+1 < allArrays[x.second].size()){
            pq.push(make_pair(allArrays[x.second][indexTracker[x.second]+1],x.second));
        }
        indexTracker[x.second]+=1;
    }

    //print answer
    for(auto element:ans){
        cout<<element<<" ";
    }
    cout<<endl<<endl;


return 0;
}
