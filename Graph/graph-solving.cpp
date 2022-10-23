#include<bits/stdc++.h>

using namespace std;

//1000 for mentioning max number of node or constrain of n
vector<int>v[1000];

int main(){
    int n,e;
    cin>>n>>e;
    for(int i=0; i<e; i++){
        int a,b'
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

return 0;
}
