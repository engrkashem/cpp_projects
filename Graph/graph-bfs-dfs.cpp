#include<bits/stdc++.h>

using namespace std;

//1000 for mentioning max number of node or constrain of n
vector<int>v[100];
bool visited[100];

void bfs(int src){
    queue<pair<int,int>>q;
    q.push({src,0});

    while(!q.empty()){
        pair<int,int> parent=q.front();
        q.pop();
        if(visited[parent.first]==true)continue;

        // here code as per your logic required
        cout<<parent.first<<" | "<<parent.second<<endl;

        //traversing children whom not visited yet to avoid rigorous visiting
        for(int i=0; i<v[parent.first].size(); i++){
            int children=v[parent.first][i];
            if(visited[children]==false) q.push({children, parent.second+1});
        }

        visited[parent.first]=true;
    }
}


void dfs(int src){
    cout<<src<<endl;
    visited[src]=true;

    for(int i=0; i<v[src].size(); i++){
        int children=v[src][i];
        if(visited[children]==false) dfs(children);
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    for(int i=0; i<e; i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));

    int src;
    cin>>src;
    dfs(src);

return 0;
}
