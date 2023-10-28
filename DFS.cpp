#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
    map<int,bool> visited;
    map<int,list<int>> adj;
    void addedge(int v,int w);
    void dfs(int v);
};
void graph::addedge(int v,int w){
    adj[v].push_back(w);
}
void graph::dfs(int v){
    visited[v]=true;
    cout<<v<<" ";
    list<int>::iterator iter;
    for(iter=adj[v].begin();iter!=adj[v].end();++iter){
        if(!visited[*iter]){
            dfs(*iter);
        }
    }
}
int main(){
    graph g;
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(0,3);
    g.addedge(2,3);
    g.addedge(2,4);
    g.dfs(0);
    return 0;
}
