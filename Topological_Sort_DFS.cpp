#include <bits/stdc++.h> 
void dfs(vector<bool> &visited,stack<int> &s,
unordered_map<int,vector<int>> &adj, int node ){
    visited[node]=true;
    for(auto i: adj[node]){
        if(!visited[i]){
            dfs(visited,s, adj, i);
        }
    }
    s.push(node);
    return;
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }
    vector<bool> visited(v);
    stack<int> s;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(visited, s, adj, i);
        }
    }
    vector<int> ans;
    while (!s.empty()) {
      ans.push_back(s.top());
      s.pop();
    }
    return ans;
}