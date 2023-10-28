#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
    map<int,bool> visited;
    map<int,list<int>> adj;
    void addedge(int v,int w);
    void dfs(int v);
    void bfs(int v);
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
void graph::bfs(int v){
    visited[v]=true;
    list<int> q;
    q.push_back(v);
    while(!q.empty()){
        v=q.front();
        cout<<v<<" ";
        q.pop_front();
        list<int>::iterator iter;
        for(iter=adj[v].begin();iter!=adj[v].end();++iter){
            if(!visited[*iter]){
                visited[*iter]=true;
                q.push_back(*iter);
            }
        }
    }
}
int main(){
    graph g;
    g.addedge(1,2);
    g.addedge(1,3);
    g.addedge(1,4);
    g.addedge(2,5);
    g.addedge(2,6);
    g.addedge(5,9);
    g.addedge(5,10);
    g.addedge(4,7);
    g.addedge(4,8);
    g.addedge(7,11);
    g.addedge(7,12);
    g.bfs(1);
    return 0;
}
