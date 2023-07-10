#include <unordered_map>
#include <stack>
void dfs(int node, unordered_map<int,vector<int>> &adj,
unordered_map<int,bool> &visited,stack<int> &s){
    visited[node]=true;
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(it,adj,visited,s);
        }
    }
    s.push(node);
}
void newdfs(int node, stack<int> &s,unordered_map<int,bool> &visited,
unordered_map<int,vector<int>> &adj,vector<int> &temp){
    visited[node]=true;
    temp.push_back(node);
    for(auto &it: adj[node]){
        if(!visited[it]){
            newdfs(it,s,visited,adj, temp);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }
        
    stack<int> s;
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i, adj, visited,s);
        }
    }
    //transpose
    unordered_map<int,vector<int>> rev;
   
   for(auto it:adj){

       int u=it.first;
       for(auto v: it.second){
           rev[v].push_back(u);
       }
   }
   unordered_map<int,bool> vis;
    vector<vector<int>> count;
    while(!s.empty()){
        int node=s.top();
        s.pop();
        if(!vis[node]){
            vector<int> temp;
            newdfs(node, s, vis, rev, temp);
            count.push_back(temp);
        }
    }
    return count;
}