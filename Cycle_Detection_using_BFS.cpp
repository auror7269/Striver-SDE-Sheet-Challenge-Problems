 #include <bits/stdc++.h> 
bool bfs(unordered_map<int,bool> &visited, unordered_map<int,vector<int>> &adj,
int node){
    unordered_map<int,int> parent;
    parent[node]=-1;
    visited[node]=true;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int front= q.front();
        q.pop();
        for(auto i : adj[front]){
            if(visited[i] && i !=parent[front]) return true;
            else if(!visited[i]){
                q.push(i);
                visited[i]=true;
                parent[i]=front;
            }
        }
    } 
    return false;
    }
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=bfs(visited, adj, i);
            if(ans) return "Yes";
        }
    }
    return "No";
    
}
